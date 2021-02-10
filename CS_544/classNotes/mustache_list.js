#!/usr/bin/env nodejs

const mustache = require('mustache')

//Iterates through list of people stored in view object and displays the template rendered

const template = `
  {{#people}}
    Hello {{name}}, you are {{age}} years old
  {{/people}}
`;

const view = {
  people: [
    {
      name: 'John',
      age: 10
    },
    {
      name: 'Mary',
      age: 15
    }
  ]
};

console.log(mustache.render(template, view));
