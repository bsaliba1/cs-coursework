'use strict';

const AppError = require('./app-error');
const validate = require('./validate');

const assert = require('assert');
const mongo = require('mongodb').MongoClient;

class Sensors {
    constructor(client){
        //Acceptable keys for each find function
        this.general_props = ["_index", "_count"]
        this.sensor_type_props = ["id", "manufacturer", "modelNumber", "quantity",
            "unit", "limits.min", "limits.max"].concat(this.general_props);
        this.sensor_props = ["id", "model", "period",
            "limits.min", "limits.max"].concat(this.general_props).concat(["_doDetail"]);
        this.sensor_data_props = ["sensorId", "timestamp",
            "value", "statuses"].concat(this.general_props).concat(["_doDetail"]);

        //set up mongodb
        this.client = client;
        this.db = client.db("sensors");

        //Create collections
        this.sensor_types = this.db.collection('sensor_types');
        this.sensors = this.db.collection('sensors');
        this.sensor_data = this.db.collection('sensor_data');
    }

    /** Return a new instance of this class with database as
     *  per mongoDbUrl.  Note that mongoDbUrl is expected to
     *  be of the form mongodb://HOST:PORT/DB.
     */
    static async newSensors(mongoDbUrl) {
        let regex = /^(mongodb:\/\/\w+:\d+)(\/\w+)/;
        let results = mongoDbUrl.match(regex); 
        if( results === null){
           throw [new AppError("INVALID_FORMAT","Url format is incorrect")];
        }
        let url = results[1];
        let client = await mongo.connect(url, MONGO_OPTIONS).catch(err => { throw [new AppError("INVALID_HOST/PORT", err)]});
        if(!client){
            throw [new AppError("CLIENT_CONNECTION", "Unable to connect to client")];
        }
        return new Sensors(client);
    }

    /** Release all resources held by this Sensors instance.
     *  Specifically, close any database connections.
     */
    async close() {
        this.client.close();
    }

    /** Clear database */
    async clear() {
        if (await this.sensors.countDocuments() !== 0){
            this.sensors.drop(function(err, ok) {
                if (err) throw [new AppError('COLLECTION_DROP', err)];
                //if (ok) console.log("Collection deleted");
            });
        }
        if (await this.sensor_types.countDocuments() !== 0){
            this.sensor_types.drop(function(err, ok) {
                if (err) throw [new AppError('COLLECTION_DROP', err)];
                //if (ok) console.log("Collection deleted");
            });
        } 
        if (await this.sensor_data.countDocuments() !== 0){
            this.sensor_data.drop(function(err, ok) {
                if (err) throw [new AppError('COLLECTION_DROP', err)];
                //if (ok) console.log("Collection deleted");
            });
        }
    }
    /** Subject to field validation as per FN_INFOS.addSensorType,
     *  add sensor-type specified by info to this.  Replace any
     *  earlier information for a sensor-type with the same id.
     *
     *  All user errors must be thrown as an array of objects.
     */
    async addSensorType(info) {
        const sensorType = validate('addSensorType', info);
        this.sensor_types.replaceOne({"id": sensorType.id}, sensorType,{upsert:true});
    }

    /** Subject to field validation as per FN_INFOS.addSensor, add
     *  sensor specified by info to this.  Replace any earlier
     *  information for a sensor with the same id.
     *
     *  All user errors must be thrown as an array of objects.
     */
    async addSensor(info) {
        const sensor = validate('addSensor', info);
        this.sensors.replaceOne({"id": sensor.id}, sensor,{upsert:true});
    }

    /** Subject to field validation as per FN_INFOS.addSensorData, add
     *  reading given by info for sensor specified by info.sensorId to
     *  this. Replace any earlier reading having the same timestamp for
     *  the same sensor.
     *
     *  All user errors must be thrown as an array of objects.
     */
    async addSensorData(info) {
        const sensorData = validate('addSensorData', info);
        if(await this.sensor_types.countDocuments() === 0 && await this.sensors.countDocuments() === 0){
            throw [new AppError("NO_DATA", "Must load sensor_types and sensors prior to loading data")];
        }
        let sensor = await this.sensors.findOne({id: sensorData.sensorId});
        if(sensor === null){
            throw [new AppError("NO_DATA", `No matching sensor for sensorID:${sensorData.sensorId}`)];
        }
        let type = await this.sensor_types.findOne({id: sensor.model});
        if(type === null){
            throw [new AppError("NO_DATA", `No matching sensor-type for model:${sensor.model}`)];
        }
        let updated_sensorData = set_status(sensorData,sensor, type);
        await this.sensor_data.replaceOne({timestamp: sensorData.timestamp, sensorId: sensorData.sensorId},updated_sensorData, {upsert: true});
    }

    /** Subject to validation of search-parameters in info as per
     *  FN_INFOS.findSensorTypes, return all sensor-types which
     *  satisfy search specifications in info.  Note that the
     *  search-specs can filter the results by any of the primitive
     *  properties of sensor types.
     *
     *  The returned value should be an object containing a data
     *  property which is a list of sensor-types previously added using
     *  addSensorType().  The list should be sorted in ascending order
     *  by id.
     *
     *  The returned object will contain a lastIndex property.  If its
     *  value is non-negative, then that value can be specified as the
     *  index property for the next search.  Note that the index (when
     *  set to the lastIndex) and count search-spec parameters can be used
     *  in successive calls to allow scrolling through the collection of
     *  all sensor-types which meet some filter criteria.
     *
     *
     *  All user errors must be thrown as an array of objects.
     */
    async findSensorTypes(info) {
        const search_specs = validate('findSensorTypes', info);
        if(await this.sensor_types.countDocuments() === 0){
            throw [new AppError("NO_DATA", "No sensor types loaded")];
        }
        check_properties(search_specs, this.sensor_type_props);
        const reorganized_specs = organizeSpecs(search_specs, this.general_props);
        
        let matching_types = await find_matches(this.sensor_types, reorganized_specs);
        return matching_types;
    }

    /** Subject to validation of search-parameters in info as per
     *  FN_INFOS.findSensors, return all sensors which
     *  satisfy search specifications in info.  Note that the
     *  search-specs can filter the results by any of the primitive
     *  properties of a sensor.
     *
     *  The returned value should be an object containing a data
     *  property which is a list of all sensors satisfying the
     *  search-spec which were previously added using addSensor().  The
     *  list should be sorted in ascending order by id.
     *
     *  If info specifies a truthy value for a doDetail property,
     *  then each sensor S returned within the data array will have
     *  an additional S.sensorType property giving the complete
     *  sensor-type for that sensor S.
     *
     *  The returned object will contain a lastIndex property.  If its
     *  value is non-negative, then that value can be specified as the
     *  index property for the next search.  Note that the index (when
     *  set to the lastIndex) and count search-spec parameters can be used
     *  in successive calls to allow scrolling through the collection of
     *  all sensors which meet some filter criteria.
     *
     *  All user errors must be thrown as an array of objects.
     */
    async findSensors(info) {
        const search_specs = validate('findSensors', info);
        if(this.sensors.size === 0){
            throw [new AppError("NO_DATA", "No sensors loaded")];
        }
        if(search_specs.id !== null && !this.sensors.has(search_specs.id)){
            throw [new AppError("X_ID", `Cannot find sensor for id ${search_specs.id}`)];
        }
        check_properties(search_specs, this.sensor_props);
        const reorganized_specs = organizeSpecs(search_specs, this.general_props.concat(['_doDetail']));
        let matching_types = await find_matches(this.sensors, reorganized_specs);
        if(reorganized_specs["_doDetail"]){
            matching_types = detail_sensors(matching_types,this.sensor_types);
        }
        return matching_types;
    }

    /** Subject to validation of search-parameters in info as per
     *  FN_INFOS.findSensorData, return all sensor reading which satisfy
     *  search specifications in info.  Note that info must specify a
     *  sensorId property giving the id of a previously added sensor
     *  whose readings are desired.  The search-specs can filter the
     *  results by specifying one or more statuses (separated by |).
     *
     *  The returned value should be an object containing a data
     *  property which is a list of objects giving readings for the
     *  sensor satisfying the search-specs.  Each object within data
     *  should contain the following properties:
     *
     *     timestamp: an integer giving the timestamp of the reading.
     *     value: a number giving the value of the reading.
     *     status: one of "ok", "error" or "outOfRange".
     *
     *  The data objects should be sorted in reverse chronological
     *  order by timestamp (latest reading first).
     *
     *  If the search-specs specify a timestamp property with value T,
     *  then the first returned reading should be the latest one having
     *  timestamp <= T.
     *
     *  If info specifies a truthy value for a doDetail property,
     *  then the returned object will have additional
     *  an additional sensorType giving the sensor-type information
     *  for the sensor and a sensor property giving the sensor
     *  information for the sensor.
     *
     *  Note that the timestamp and count search-spec parameters can be
     *  used in successive calls to allow scrolling through the
     *  collection of all readings for the specified sensor.
     *
     *  All user errors must be thrown as an array of objects.
     */
    async findSensorData(info) {
        const search_specs = validate('findSensorData', info);
        if(await this.sensor_data.countDocuments() === 0){
            throw [new AppError("NO_DATA", `No sensor data loaded`)];
        }
        if(await this.sensor_data.find({sensorId: search_specs.sensorId}).count() === 0){
            throw [new AppError("X_ID", `Unknown sensor id "${search_specs.sensorId}"`)];
        }
        check_properties(search_specs, this.sensor_data_props);
        const reorganized_specs = organizeSpecs(search_specs, ['_count', '_doDetail', 'statuses']);
        const matching_types = find_matches_data(this.sensor_data, reorganized_specs, this.sensors, this.sensor_types);
        return matching_types;
    }
}

module.exports = Sensors;

//Organize specs into comprehensive data structure
// rs = {
//  index:
//  count:
//  final_index:
//  specs: {...}
// }
function organizeSpecs(search_specs, gen_props) {
    let reorganized_specs = {
        _index: 0,
    };
    for (let prop of gen_props) {
        reorganized_specs[prop] = search_specs[prop];
        delete search_specs[prop];
    }
    reorganized_specs.final_index = reorganized_specs["_count"] + reorganized_specs["_index"];
    if (search_specs.id === null) {
        delete search_specs.id;
    }
    reorganized_specs.specs = search_specs;
    return reorganized_specs;
}

//Makes sure all search spec keys are valid
function check_properties(search_specs, possible_keys) {
    for (let spec in search_specs) {
        if (!possible_keys.includes(spec)) {
            throw [new AppError("X_PROPERTY", `No property '${spec}' for given type`)];
        }
    }
}

//Finds all objects that match specs
//@returns array of matching values
async function find_matches(collection, specifications) {
    let matches = await collection.find(specifications.specs,{sort: "id", fields:{_id: 0}});
    let formatted_matches = await format_matches(await matches, specifications);
    return formatted_matches;
}

//Finds all objects that match specs
//@returns array of matching values
async function find_matches_data(collection, specifications, sensors, sensor_types) {
    specifications.specs.timestamp = {$lte: specifications.specs.timestamp};
    specifications.specs.status = {$in: Array.from(specifications.statuses)};
    let matches = await collection.find(specifications.specs, {sort:{"timestamp": -1}, fields:{_id: 0, sensorId: 0}});
    let formatted_matches = await format_matches(matches, specifications);
    delete formatted_matches.nextIndex;
    if(specifications["_doDetail"]){
        formatted_matches = detail_data(formatted_matches, specifications.specs.sensorId, sensors, sensor_types);
    }
    return formatted_matches;
}

//Formats the matching objects
//@return
//  Object{
//    data: [matches]
//    nextIndex: int    
//  }
async function format_matches(cursor, specifications) {
    let formatted_matches = {
        data: new Array,
        nextIndex: 0,
    }
    let q_size = await cursor.count();
    cursor.skip(specifications["_index"]).limit(specifications["_count"]);
    if( q_size > specifications.final_index){
        formatted_matches.nextIndex = specifications.final_index;
    }else{
        formatted_matches.nextIndex = -1;
    }
    formatted_matches.data =  await cursor.toArray();
    return formatted_matches;
}

//Adds sensor_type field to each match
async function detail_sensors(matches, sensor_types) {
    for (let m in matches.data) {
        matches.data[m].sensor_type = await sensor_types.findOne({id: matches.data[m].model}, {fields:{_id: 0, sensorId: 0}});
    }
    return matches;
}

//Adds sensor_type and sensor fields to matches array
async function detail_data(matches, sensorId, sensors, types) {
    let sensor = await sensors.findOne({id: sensorId},{fields:{_id: 0}});
    let sensorType = await types.findOne({id: sensor.model},{fields:{_id: 0}});
    matches.sensorType = sensorType;
    matches.sensor = sensor;
    return matches;
}

function set_status(sensorData, sensor, type){
    let value = sensorData.value;
    //check if error
    if(value<type.limits.min || value>type.limits.max){
        sensorData.status = "error";
    }
    //check if outOfRange
    else if(value<sensor.expected.min || value>sensor.expected.max){
        sensorData.status = "outOfRange";
    }else{
        sensorData.status = "ok";
    }
    return sensorData;
}

module.exports = Sensors.newSensors;

//Options for creating a mongo client
const MONGO_OPTIONS = {
    useNewUrlParser: true,
    useUnifiedTopology: true,
};


function inRange(value, range) {
    return Number(range.min) <= value && value <= Number(range.max);
}
