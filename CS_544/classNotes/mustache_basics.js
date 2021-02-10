#!/usr/bin/env nodejs

const mustache = require('mustache')

const template =
  `Hello {{name}}{{#age}}, you are {{age}} years old{{/age}}`;

const view = {
  name: 'John',
  age: 10,
};

console.log(mustache.render(template, view));
