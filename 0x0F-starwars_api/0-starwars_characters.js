#!/usr/bin/node

let args = parseInt(Array.prototype.slice.call(process.argv, 2));
const fetch = require('node-fetch');
const url = 'https://swapi-api.hbtn.io/api/films/' + args;

fetch(url)
  .then(response => response.json())
  .then(data => {
    for (let i = 0; i < data.characters.length; i++) {
      fetch(data.characters[i])
        .then(response => response.json())
        .then(data => console.log(data.name));
    }
  })
  .catch(err => console.error(err));
