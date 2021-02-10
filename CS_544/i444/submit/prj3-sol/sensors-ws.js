const cors = require('cors');
const  url = require('url');
const express = require('express');
const bodyParser = require('body-parser');

const AppError = require('./app-error');

const OK = 200;
const CREATED = 201;
const BAD_REQUEST = 400;
const NOT_FOUND = 404;
const CONFLICT = 409;
const SERVER_ERROR = 500;


//@TODO set up express app, routing and listen
function serve(port, sensors) {
    const app = express();
    app.locals.port = port;
    app.locals.sensors = sensors;
    setupRoutes(app);
    app.listen(port, function() {
        console.log(`listening on port ${port}`);
    });
}

module.exports = { serve };

//@TODO routing function, handlers, utility functions
function setupRoutes(app) {
    app.locals.base = 'http://localhost:2345';
    app.use(cors());
    app.use(bodyParser.json());
    app.get(`/`, function(req, res){res.send('Hit Root URL\n')});
    app.get(`/:db`, doGet(app));
    app.get(`/:db/:id`, doGet(app));
    app.get(`/:db/:id/:timestamp`, doGet(app));
    app.post(`/:db`, doCreate(app));
    app.post(`/:db/:id`, doCreate(app));
    //app.use(doErrors()); //must be last
}

//Params contains the id
//Query contains _index and _count
function doGet(app){
    return errorWrap(async function(req, res) {
        try {
            const id = req.params.id;
            let copyQuery = Object.assign({}, req.query);
            if(id !== undefined){
                copyQuery.id = id;
            }

            //Obtain Results
            let results;
            if(req.params.db == 'sensor-types'){
                results = await app.locals.sensors.findSensorTypes(copyQuery);
            }else if(req.params.db === 'sensors'){
                results = await app.locals.sensors.findSensors(copyQuery);
            }else if(req.params.db === 'sensor-data'){
                copyQuery.sensorId = req.params.id;
                if(req.params.timestamp !== undefined){
                    copyQuery.timestamp = req.params.timestamp;
                    copyQuery._count = 1;
                }
                results = await app.locals.sensors.findSensorData(copyQuery);
                if(req.params.timestamp !== undefined && results.data[0] !== undefined && results.data[0].timestamp != req.params.timestamp){
                    const err = `no data for timestamp ${req.params.timestamp}`
                    throw [ new AppError('NOT_FOUND', err) ];                    
                }
            }

            //HATEOAS for sensor-types and sensors 
            if(req.params.db === 'sensor-types' || req.params.db === 'sensors'){
                let url;
                if(req.params.id != undefined){
                    url = `${app.locals.base}\/${req.params.db}\/${req.params.id}`;
                }else{
                    url = `${app.locals.base}\/${req.params.db}`;
                }
                for(let element of results.data){
                    element.self = `${app.locals.base}\/${req.params.db}\/${element.id}`;
                }
                let equery = encodeQuery(req.query);
                results.self = `${url}${equery}`;
                if(results.previousIndex > 0){
                    req.query._index = results.previousIndex; 
                    equery = encodeQuery(req.query)
                    results.prev = `${url}${equery}`;
                }
                if(results.nextIndex > 0){
                    req.query._index = results.nextIndex; 
                    equery = encodeQuery(req.query)
                    results.next = `${url}${equery}`;
                }
            }

            //HATEOAS for sensor-data
            if(req.params.db === "sensor-data"){
                let url = `${app.locals.base}\/${req.params.db}\/${req.params.id}`;
                for(let element of results.data){
                    element.self = `${url}\/${element.timestamp}`;
                }
                if(req.params.timestamp !== undefined){
                    url = `${app.locals.base}\/${req.params.db}\/${req.params.id}\/${req.params.timestamp}`;
                }
                let equery = encodeQuery(req.query);
                results.self = `${url}${equery}`;
                if(results.previousIndex > 0){
                    req.query._index = results.previousIndex; 
                    equery = encodeQuery(req.query)
                    results.prev = `${url}${equery}`;
                }
                if(results.nextIndex > 0){
                    req.query._index = results.nextIndex; 
                    equery = encodeQuery(req.query)
                    results.next = `${url}${equery}`;
                }
            }
            res.json(results);
        }
        catch(err) {
            let retError = {
                errors: []
            };
            retError.errors.push(mapError(err));
            let li = retError.errors.length -1;
            let stat = retError.errors[li].status;
            delete retError.errors[li].status;
            res.status(stat).json(retError);
        }
    });
}

function doCreate(app){
    return errorWrap(async function(req, res) {
        try {
            const replacement = Object.assign({}, req.body);
            if(req.params.id !== undefined){
                replacement.sensorId = req.params.id;
            }
            
            let results;
            if(req.params.db === 'sensors'){
                results = await app.locals.sensors.addSensor(replacement);
            }else if(req.params.db === 'sensor-types'){
                results = await app.locals.sensors.addSensorType(replacement);
            }else if(req.params.db === 'sensor-data'){
                results = await app.locals.sensors.addSensorData(replacement);
            }
            res.sendStatus(CREATED);
        }
        catch(err) {
            let retError = {
                errors: []
            };
            retError.errors.push(mapError(err));
            let li = retError.errors.length -1;
            let stat = retError.errors[li].status;
            delete retError.errors[li].status;
            res.status(stat).json(retError);
        }
    });
}

function encodeQuery(query){
    let retString = '';
    if(Object.keys(query).length !== 0){
        retString += '?';
        for(let key in query){
            retString += `${key}=${query[key]}&`;
        }
        retString = retString.substring(0, retString.length-1);
        return retString;
    }
    return '';
}

/** Set up error handling for handler by wrapping it in a
 *  try-catch with chaining to error handler on error.
 */
/*************************** Mapping Errors ****************************/
const ERROR_MAP = {
  EXISTS: CONFLICT,
  NOT_FOUND: NOT_FOUND
}

function errorWrap(handler) {
    return async (req, res, next) => {
        try {
            await handler(req, res, next);
        }
        catch (err) {
            next(err);
        }
    };
}

function mapError(err){
    let retError = { status: (ERROR_MAP[err[0].code] || BAD_REQUEST), code: err[0].code, message: err[0].msg}
    return retError;
}
