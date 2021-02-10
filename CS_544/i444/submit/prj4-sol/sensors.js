'use strict';

const assert = require('assert');
const cors = require('cors');
const express = require('express');
const bodyParser = require('body-parser');
const url = require('url');
const fs = require('fs');
const axios = require('axios');
const querystring = require('querystring');


const Mustache = require('./mustache');
const widgetView = require('./widget-view');

const STATIC_DIR = 'statics';
const TEMPLATES_DIR = 'templates';

const FIELD_REGEX = {
  id: /^[\d,\w,-,_]+$/g,
  modelNumber: /^[\d,\w,-,_]+$/g,
  model: /^[\d,\w,-,_]+$/g,
  manufacturer: /^[\d,\w,-,_]+$/g,
  quantity: /(temperature|pressure|flow)/g,
  period: /^\d+$/g,
  expected: /^\d+$/g,
  limits: /^\d+$/g,
  errors:{
    id: "can contain only alphanumerics, '-' or '_'",
    modelNumber: "can contain only alphanumerics, '-' or '_'",
    model: "can contain only alphanumerics, '-' or '_'",
    manufacturer: "can contain only alphanumerics, '-' or '_'",
    quantity: " field must be an available option",
    period: "field must be an integer", 
    expected: "field must be a number",
    limits: "field must be a number",
  }
}

const PAGE_OPTIONS = {
  ADD_SENSORS: {
    form_method: 'POST',
    add: true,
    page_class: 'tst-sensor-add-page',
    title: 'Create / Update Sensors',
    id_label: 'Sensor ID',
    model_label: 'Model',
    widgets: ['period', 'expected'],
    period_label: 'Period',
    expected_label: 'Expected Range',
    button_label: 'add',
    errors:{},
  },

  ADD_SENSOR_TYPES: {
    form_method: 'POST',
    add: true,
    page_class: 'tst-sensor-types-add-page',
    title: 'Create / Update Sensor Types',
    id_label: 'Sensor Type ID',
    modelNumber_label: 'Model Number',
    widgets: ['manufacturer', 'measure', 'limits'],
    manufacturer_label: 'Manufacturer',
    quantity_label: 'Measure',
    limits_label: 'Limits',
    button_label: 'add',
    errors:{},
  },

  SEARCH_SENSORS: {
    form_method: 'GET',
    sensor_types: false,
    add: false,
    page_class: 'tst-sensor-search-page',
    title: 'Search Sensors',
    id_label: 'Sensor ID',
    model_label: 'Model',
    widgets: ['period'],
    period_label: 'Period',
    button_label: 'search',
    errors:{},
  },

  SEARCH_SENSOR_TYPES: {
    form_method: 'GET',
    sensor_types: true,
    add: false,
    page_class: 'tst-sensor-types-search-page',
    title: 'Search Sensor Types',
    id_label: 'Sensor ID',
    modelNumber_label: 'Model Number',
    widgets: ['measure', 'manufacturer'],
    manufacturer_label: 'Manufacturer',
    quantity_label: 'Measure',
    button_label: 'search',
    errors:{},
  },
}


function create_widgets(options, query) {
  query = validate_input(query, options.add, options);
  let view = {
    widgets: []
  }
  view.page_class = options.page_class;
  view.title = options.title;

  //Always has id field
  let id = {
    name: "id",
    label: options.id_label,
    isRequired: options.add,
    type: 'text',
    opts: {
      value: query.id,
      error: query.errors.id,
    }
  }
  view.widgets.push(widgetView(id, id.opts));

  //Always has model field
   if(options.modelNumber_label!== undefined){
      let modelNumber = {
        name: 'modelNumber',
        label: options.modelNumber_label,
        isRequired: options.add,
        type: 'text',
        opts: {
          value: query.modelNumber,
          error: query.errors.modelNumber,
        }
      }
      view.widgets.push(widgetView(modelNumber, modelNumber.opts));
   }
   if(options.model_label!== undefined){
      let model = {
        name: 'model',
        label: options.model_label,
        isRequired: options.add,
        type: 'text',
        opts: {
          value: query.model,
          error: query.errors.model,
        }
      }
      view.widgets.push(widgetView(model, model.opts));
   }

  if (options.widgets.includes('manufacturer')) {
    let manufacturer = {
      name: 'manufacturer',
      label: options.manufacturer_label,
      isRequired: options.add,
      type: 'text',
      opts: {
        value: query.manufacturer,
        error: query.errors.manufacturer,
      }
    }
    view.widgets.push(widgetView(manufacturer, manufacturer.opts));
  }
  if (options.widgets.includes('measure')) {
    let measure = {
      name: 'quantity',
      label: options.quantity_label,
      type: 'select',
      isRequired: options.add,
      choices: {
        '': 'Select',
        temperature: 'Temperature',
        pressure: 'Pressure',
        flow: 'Flow Rate',
      },
      opts: {
        value: query.quantity,
        error: query.errors.quantity,
      }
    }
    view.widgets.push(widgetView(measure, measure.opts));
  }
  if (options.widgets.includes('period')) {
    let period = {
      name: 'period',
      label: options.period_label,
      type: 'text',
      isRequired: options.add,
      opts: {
        value: query.period,
        error: query.errors.period,
      }
    }
    view.widgets.push(widgetView(period, period.opts));
  }
  if (options.widgets.includes('expected')) {
    let expected = {
      name: 'expected',
      label: 'Expected Range',
      type: 'interval',
      classes: ['numeric interval'],
      isRequired: options.add,
      opts: {
        value: query.expected,
        error: query.errors.expected,
      }
    }
    view.widgets.push(widgetView(expected, expected.opts));
  }
  if (options.widgets.includes('limits')) {
    let limits = {
      name: 'limits',
      label: 'Limits',
      type: 'interval',
      classes: ['numeric interval'],
      isRequired: options.add,
      opts: {
        value: query.limits,
        error: query.errors.limits,
      }
    }
    view.widgets.push(widgetView(limits, limits.opts));
  }
  view.form_method = options.form_method;
  view.search = !options.add;
  view.sensor_types = options.sensor_types;
  view.button_label = options.button_label;

  return view;
}

function serve(port, model, base = '') {
  const app = express();
  app.locals.port = port;
  app.locals.base = base;
  app.locals.model = model;
  app.locals.mustache = new Mustache();
  setupRoutes(app);
  app.listen(port, function () {
    console.log(`listening on port ${port}`);
  });
}


module.exports = serve;

function setupRoutes(app) {
  app.use(cors());
  app.use(bodyParser.json());
  app.use(express.static(STATIC_DIR));
  app.get(`/`, function (req, res) { res.send('Hit Root URL\n') });
  app.get('/:id.html', search_handler(app));
  app.get('/:id/add.html', create_add_form(app));
  app.post('/:id/add.html', bodyParser.urlencoded({extended: false}), submit_form(app));
}

function search_handler(app) {
  return async function (req, res) {
    let mustache = new Mustache();
    let query = Object.assign({}, req.query);
    if (req.params.id == 'sensors') {
      let view = create_widgets(PAGE_OPTIONS.SEARCH_SENSORS, query);
      view = await build_table(app, req.query, view);
      res.send(mustache.render('page', view));
    } else if (req.params.id == 'sensor-types') {
      let view = create_widgets(PAGE_OPTIONS.SEARCH_SENSOR_TYPES, query);
      view = await build_table(app, req.query, view);
      res.send(mustache.render('page', view));
    }
  }
}

function create_add_form(app) {
  return async function (req, res) {
    let mustache = new Mustache();
    let query = Object.assign({}, req.query);
    if (req.params.id == 'sensors') {
      res.send(mustache.render('page', create_widgets(PAGE_OPTIONS.ADD_SENSORS, query)));
    } else if (req.params.id == 'sensor-types') {
      res.send(mustache.render('page', create_widgets(PAGE_OPTIONS.ADD_SENSOR_TYPES, query)));

    }
  }
}

function validate_input(query, fields_required, options) {
  let fields = ['id', 'modelNumber', 'model', 'manufacturer', 'quantity', 'period', 'expected', 'expected[min]', 'expected[max]', 'limits', 'limits[min]', 'limits[max]'];
  query.errors = {};
  for (const field of fields) {
    let field_label = `${field}_label`;
    if (query[field] !== undefined) {
      if(field === 'limits' || field === 'expected'){
        if (query[field].min === '' && query[field].max === '' && fields_required) {
          query.errors[field] = `Both Min and Max value for '${options[field_label]}' must be provided.`
        }
        else{ 
          if(query[field].min.match(FIELD_REGEX[field]) == null && query[field].min !== ''){
           query.errors[field] = `${options[field_label]} Min ${FIELD_REGEX.errors[field]}`;
          }
          if(query[field].max.match(FIELD_REGEX[field]) == null && query[field].max !== ''){
             query.errors[field] = `${options[field_label]} Max ${FIELD_REGEX.errors[field]}`;
          }
        }
      }
      else if(field === 'limits[min]' || field === 'expected[min]'){
        if (query[field] === '' && fields_required) {
          query.errors[field] = `Both Min and Max value for '${options[field_label]}' must be provided.`
        }
        else{ 
          if(query[field].match(FIELD_REGEX['limits']) == null && query[field] !== ''){
           query.errors[field] = `${options[field_label]} Min ${FIELD_REGEX.errors[field]}`;
          }
        }
      }
      else if(field === 'limits[max]' || field === 'expected[max]'){
        if (query[field] === '' && fields_required) {
          query.errors[field] = `Both Min and Max value for '${options[field_label]}' must be provided.`
        }
        else{ 
          if(query[field].match(FIELD_REGEX['limits']) == null && query[field] !== ''){
           query.errors[field] = `${options[field_label]} Max ${FIELD_REGEX.errors[field]}`;
          }
        }
      }
      else if (query[field] === '' && fields_required) {
        query.errors[field] = `A value for '${options[field_label]}' must be provided.`
      }
      else if(query[field].match(FIELD_REGEX[field]) == null && query[field] !== ''){
         query.errors[field] = `${options[field_label]} ${FIELD_REGEX.errors[field]}`;
      }
    }
  }
  return query;
}

function submit_form(app){
  return async function (req, res) {
    let structured = req.body;
    
    //Update Sensor-Types
    if(req.params.id === 'sensor-types'){
      let path = "/sensor-types.html";
      let query = validate_input(req.body, true, PAGE_OPTIONS.ADD_SENSOR_TYPES);      
      if(Object.keys(query.errors).length !== 0){
        path = "/sensor-types/add.html";
      }else{
        structured = edit_body(req.body);
        console.log(structured);
        await app.locals.model.update('sensor-types', structured);
      }
      let send = Object.assign({},req.body);
      delete send['limits[min]'];
      delete send['limits[max]'];
      res.redirect(url.format({
      pathname: path,
      query: send,
      }));

    //Update Sensors
    }else if(req.params.id === 'sensors'){
      let path = "/sensors.html";
      let query = validate_input(req.body, true, PAGE_OPTIONS.ADD_SENSORS);
      if(Object.keys(query.errors).length !== 0){
        path = "/sensors/add.html";
      }else{
        structured = edit_body(req.body);
        console.log(structured);
        try{
          await app.locals.model.update('sensors', structured);
        }catch(error){
            req.body.no_results=true;
        }
      }
      let send = Object.assign({},req.body);
      delete send['expected[min]'];
      delete send['expected[max]'];
      console.log(send);
      res.redirect(url.format({
      pathname: path,
      query: send,
      }));
    }
  }
}
async function build_table(app, query, view){
  if(view.sensor_types){
      try{
        let response = await app.locals.model.list('sensor-types', query);
        view.table_data = response;
        if(view.table_data.next !== undefined){
            view.next_url = '/sensor-types.html'+view.table_data.next.match(/\?.+/g);
        }
        if(view.table_data.prev !== undefined){
            view.prev_url = '/sensor-types.html'+view.table_data.prev.match(/\?.+/g);
        }
      }catch(error){
        view.no_results = true;
      }
  }else{
     try{
        let response = await app.locals.model.list('sensors', query);
        view.table_data = response;
        if(view.table_data.next !== undefined){
            view.next_url = '/sensors.html'+view.table_data.next.match(/\?.+/g);
        }
        if(view.table_data.prev !== undefined){
            view.prev_url = '/sensors.html'+view.table_data.prev.match(/\?.+/g);
        }
      }catch(error){
        view.no_results = true;
      }
  }
  return view;
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
function edit_body(body){
  let retBody = Object.assign({},body);
  let UNITS = {
    pressure: 'PSI',
    temperature: 'C',
    flow: 'gpm',
    humidity: '%',
  }
  delete retBody.errors;
  if(retBody['limits[min]']!== undefined){ 
    retBody.limits = {};
    retBody.limits.min = retBody['limits[min]'];
    retBody.limits.max = retBody['limits[max]'];
    delete retBody['limits[max]'];
    delete retBody['limits[min]'];
  }
  if(retBody['expected[min]']!== undefined){ 
    retBody.expected = {};
    retBody.expected.min = retBody['expected[min]'];
    retBody.expected.max = retBody['expected[max]'];
    delete retBody['expected[max]'];
    delete retBody['expected[min]'];
  }
  if(body.quantity != undefined){
    retBody.unit = UNITS[body.quantity];
  }
  return retBody;
}
