'use strict';

const assert = require('assert');

class Sensors {

  constructor() {
    //Acceptable keys for each find function
    this.general_props = ["index", "count"]
    this.sensor_type_props = ["id", "manufacturer", "modelNumber", "quantity",
      "unit", "limits.min", "limits.max"].concat(this.general_props);
    this.sensor_props = ["index", "id", "model", "period",
      "limits.min", "limits.max"].concat(this.general_props).concat(["doDetail"]);
    this.sensor_data_props = ["index", "sensorId", "timestamp",
      "value", "statuses"].concat(this.general_props).concat(["doDetail"]);
    this.last_index;

    //Hash maps that hold sensor information
    this.sensors = new Map;
    this.sensor_types = new Map;
    this.sensor_data = new Map;;
  }

  /** Clear out all data from this object. */
  async clear() {
     this.sensors.clear();
     this.sensor_types.clear();
     this.sensor_data.clear();
  }

  /** Subject to field validation as per FN_INFOS.addSensorType,
   *  add sensor-type specified by info to this.  Replace any
   *  earlier information for a sensor-type with the same id.
   *
   *  All user errors must be thrown as an array of objects.
   */
  async addSensorType(info) {
    const sensorType = validate('addSensorType', info);
    this.sensor_types.set(sensorType.id, sensorType);
    this.sensor_types = sort_map(this.sensor_types);
  }

  /** Subject to field validation as per FN_INFOS.addSensor, add
   *  sensor specified by info to this.  Replace any earlier
   *  information for a sensor with the same id.
   *
   *  All user errors must be thrown as an array of objects.
   */
  async addSensor(info) {
    const sensor = validate('addSensor', info);
    this.sensors.set(sensor.id, sensor);
    this.sensors = sort_map(this.sensors);
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
    let sensor = this.sensors.get(sensorData.sensorId);
    let type = this.sensor_types.get(sensor.model);
    set_status(sensorData,sensor, type);
    if (this.sensor_data.get(sensorData.timestamp) === undefined) {
      this.sensor_data.set(sensorData.timestamp, new Map);
    }
    this.sensor_data.get(sensorData.timestamp).set(sensorData.sensorId, sensorData);
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
    if(this.sensor_types.size === 0){
        throw [`no sensor types loaded`];
    }
    if(search_specs.id !== null && !this.sensor_types.has(search_specs.id)){
      throw [`cannot find sensor-type for id "${search_specs.id}"`];
    }
    check_properties(search_specs, this.sensor_type_props);
    const reorganized_specs = organizeSpecs(search_specs, this.general_props);
    const matching_types = find_matches(this.sensor_types, reorganized_specs.specs);
    const formatted_matches = format_matches(matching_types, reorganized_specs);

    return formatted_matches;
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
        throw [`no sensors loaded`];
    }
    if(search_specs.id !== null && !this.sensors.has(search_specs.id)){
      throw [`cannot find sensor for id "${search_specs.id}"`];
    }
    check_properties(search_specs, this.sensor_props);
    const reorganized_specs = organizeSpecs(search_specs, this.general_props.concat(['doDetail']));
    const matching_types = find_matches(this.sensors, reorganized_specs.specs);
    let formatted_matches = format_matches(matching_types, reorganized_specs);
    if (reorganized_specs.doDetail) {
      formatted_matches = detail_matches_sensor(formatted_matches, this.sensor_types);
    }
    return formatted_matches;
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
    if(this.sensor_data.size === 0){
        throw [`no sensor data loaded`];
    }
    if(!this.sensors.has(search_specs.sensorId)){
      throw [`unknown sensor id "${search_specs.sensorId}"`];
    }
    this.sensor_data = new Map([...this.sensor_data.entries()].sort().reverse());
    check_properties(search_specs, this.sensor_data_props);
    const reorganized_specs = organizeSpecs(search_specs, ['count', 'doDetail', 'statuses']);
    const matching_types = find_matches_data(this.sensor_data, reorganized_specs.specs, reorganized_specs.statuses);
    let formatted_matches = format_matches(matching_types, reorganized_specs);
    if (reorganized_specs.doDetail) {
      formatted_matches = detail_matches_data(formatted_matches, reorganized_specs.specs.sensorId, 
        this.sensors, this.sensor_types);
    }
    delete formatted_matches.nextIndex;
    return formatted_matches;
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
    index: 0,
  };
  for (let prop of gen_props) {
    reorganized_specs[prop] = search_specs[prop];
    delete search_specs[prop];
  }

  reorganized_specs.final_index = reorganized_specs.count + reorganized_specs.index;
  if (search_specs.id === null) {
    delete search_specs.id;
  }
  reorganized_specs.specs = search_specs;
  return reorganized_specs;
}

//Sorts unordered map keys
function sort_map(unordered) {
  var obj = new Map([...unordered.entries()].sort());
  return obj;
}

//Makes sure all search spec keys are valid
function check_properties(search_specs, possible_keys) {
  for (let spec in search_specs) {
    if (!possible_keys.includes(spec)) {
      throw [`no property '${spec}' for given type`];
    }
  }
}

//Finds all objects that match specs
//@returns array of matching values
function find_matches(collection, specifications) {
  let matches = new Array;

  for (let [object, value] of collection) {
    let to_include = true;

    for (let spec in specifications) {
      if (value[spec] !== specifications[spec]) {
        to_include = false;
      }
    }

    if (to_include) {
      matches.push(value);
    }
  }
  return matches;
}

//Finds all objects that match specs
//@returns array of matching values
function find_matches_data(collection, specifications, statuses) {
  let matches = new Array;
  for (let [timestamp, sens_map] of collection) {
    for (let [sens, data] of sens_map) {
      let to_include = true;
      for (let spec in specifications) {
        if (spec === 'timestamp') {
          if (data[spec] > specifications[spec]) {
            to_include = false;
          }
        }else{
           if (data[spec] !== specifications[spec]) {
            to_include = false;
          }
        }
      }
      if (to_include) {
        let temp = {
          timestamp: data.timestamp,
          value: data.value,
          status: data.status,
        }
        matches.push(temp);
      }
    }
  }
  matches = check_statuses(matches, statuses);
  return matches;
}

function check_statuses(matches, statuses){
  let retVal = [];
  for(let sensorData of matches){
    let to_include = false;
    for(let stat of statuses){
      if(sensorData.status === stat){
        to_include = true;
        break;
      } 
    }
    if(to_include){
      retVal.push(sensorData); 
    }
  }
  return retVal;
}

//Formats the matching objects
function format_matches(matches, specifications) {
  let formatted_matches = {
    nextIndex: 0,
    data: new Array,
  }

  for (let i = specifications.index; i < specifications.final_index; i++) {
    if (i !== matches.length) {
      formatted_matches.data.push(matches[i]);
      formatted_matches.nextIndex = i + 1;
    } else {
      formatted_matches.nextIndex = -1;
      break;
    }
  }
  return formatted_matches;
}

function detail_matches_sensor(matches, types) {
  for (let m in matches.data) {
    matches.data[m].sensorType = types.get(matches.data[m].model);
  }
  return matches;
}

function detail_matches_data(matches, sensorId, sensors, types) {
  let sensor = sensors.get(sensorId);
  let sensorType = types.get(sensor.model);
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
}
//@TODO add auxiliary functions as necessary

const DEFAULT_COUNT = 5;

/** Validate info parameters for function fn.  If errors are
 *  encountered, then throw array of error messages.  Otherwise return
 *  an object built from info, with type conversions performed and
 *  default values plugged in.  Note that any unknown properties in
 *  info are passed unchanged into the returned object.
 */
function validate(fn, info) {
  const errors = [];
  const values = validateLow(fn, info, errors);
  if (errors.length > 0) throw errors;
  return values;
}

function validateLow(fn, info, errors, name = '') {
  const values = Object.assign({}, info);
  for (const [k, v] of Object.entries(FN_INFOS[fn])) {
    const validator = TYPE_VALIDATORS[v.type] || validateString;
    const xname = name ? `${name}.${k}` : k;
    const value = info[k];
    const isUndef = (
      value === undefined ||
      value === null ||
      String(value).trim() === ''
    );
    values[k] =
      (isUndef)
        ? getDefaultValue(xname, v, errors)
        : validator(xname, value, v, errors);
  }
  return values;
}

function getDefaultValue(name, spec, errors) {
  if (spec.default !== undefined) {
    return spec.default;
  }
  else {
    errors.push(`missing value for ${name}`);
    return;
  }
}

function validateString(name, value, spec, errors) {
  assert(value !== undefined && value !== null && value !== '');
  if (typeof value !== 'string') {
    errors.push(`require type String for ${name} value ${value} ` +
      `instead of type ${typeof value}`);
    return;
  }
  else {
    return value;
  }
}

function validateNumber(name, value, spec, errors) {
  assert(value !== undefined && value !== null && value !== '');
  switch (typeof value) {
    case 'number':
      return value;
    case 'string':
      if (value.match(/^[-+]?\d+(\.\d+)?([eE][-+]?\d+)?$/)) {
        return Number(value);
      }
      else {
        errors.push(`value ${value} for ${name} is not a number`);
        return;
      }
    default:
      errors.push(`require type Number or String for ${name} value ${value} ` +
        `instead of type ${typeof value}`);
  }
}

function validateInteger(name, value, spec, errors) {
  assert(value !== undefined && value !== null && value !== '');
  switch (typeof value) {
    case 'number':
      if (Number.isInteger(value)) {
        return value;
      }
      else {
        errors.push(`value ${value} for ${name} is not an integer`);
        return;
      }
    case 'string':
      if (value.match(/^[-+]?\d+$/)) {
        return Number(value);
      }
      else {
        errors.push(`value ${value} for ${name} is not an integer`);
        return;
      }
    default:
      errors.push(`require type Number or String for ${name} value ${value} ` +
        `instead of type ${typeof value}`);
  }
}

function validateRange(name, value, spec, errors) {
  assert(value !== undefined && value !== null && value !== '');
  if (typeof value !== 'object') {
    errors.push(`require type Object for ${name} value ${value} ` +
      `instead of type ${typeof value}`);
  }
  return validateLow('_range', value, errors, name);
}

const STATUSES = new Set(['ok', 'error', 'outOfRange']);

function validateStatuses(name, value, spec, errors) {
  assert(value !== undefined && value !== null && value !== '');
  if (typeof value !== 'string') {
    errors.push(`require type String for ${name} value ${value} ` +
      `instead of type ${typeof value}`);
  }
  if (value === 'all') return STATUSES;
  const statuses = value.split('|');
  const badStatuses = statuses.filter(s => !STATUSES.has(s));
  if (badStatuses.length > 0) {
    errors.push(`invalid status ${badStatuses} in status ${value}`);
  }
  return new Set(statuses);
}

const TYPE_VALIDATORS = {
  'integer': validateInteger,
  'number': validateNumber,
  'range': validateRange,
  'statuses': validateStatuses,
};


/** Documents the info properties for different commands.
 *  Each property is documented by an object with the
 *  following properties:
 *     type: the type of the property.  Defaults to string.
 *     default: default value for the property.  If not
 *              specified, then the property is required.
 */
const FN_INFOS = {
  addSensorType: {
    id: {},
    manufacturer: {},
    modelNumber: {},
    quantity: {},
    unit: {},
    limits: { type: 'range', },
  },
  addSensor: {
    id: {},
    model: {},
    period: { type: 'integer' },
    expected: { type: 'range' },
  },
  addSensorData: {
    sensorId: {},
    timestamp: { type: 'integer' },
    value: { type: 'number' },
  },
  findSensorTypes: {
    id: { default: null },  //if specified, only matching sensorType returned.
    index: {  //starting index of first result in underlying collection
      type: 'integer',
      default: 0,
    },
    count: {  //max # of results
      type: 'integer',
      default: DEFAULT_COUNT,
    },
  },
  findSensors: {
    id: { default: null }, //if specified, only matching sensor returned.
    index: {  //starting index of first result in underlying collection
      type: 'integer',
      default: 0,
    },
    count: {  //max # of results
      type: 'integer',
      default: DEFAULT_COUNT,
    },
    doDetail: { //if truthy string, then sensorType property also returned
      default: null,
    },
  },
  findSensorData: {
    sensorId: {},
    timestamp: {
      type: 'integer',
      default: Date.now() + 999999999, //some future date
    },
    count: {  //max # of results
      type: 'integer',
      default: DEFAULT_COUNT,
    },
    statuses: { //ok, error or outOfRange, combined using '|'; returned as Set
      type: 'statuses',
      default: new Set(['ok']),
    },
    doDetail: {     //if truthy string, then sensor and sensorType properties
      default: null,//also returned
    },
  },
  _range: { //pseudo-command; used internally for validating ranges
    min: { type: 'number' },
    max: { type: 'number' },
  },
};  
