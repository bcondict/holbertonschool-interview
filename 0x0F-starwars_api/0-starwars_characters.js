#!/usr/bin/node

const args = process.argv[2];
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + args;

function makeRequest(url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        resolve(body);
      }
    });
  });
}

makeRequest(url)
  .then((body) => {
    const data = JSON.parse(body).characters;
    const promises = [];
    // for (let i = 0; i < data.length; i++) {
    //   promises.push(makeRequest(data[i]));
    // }
    for (const url of data) {
      promises.push(makeRequest(url));
    }
    return Promise.all(promises);
  })
  .then((responses) => {
    for (let i = 0; i < responses.length; i++) {
      console.log(JSON.parse(responses[i]).name);
    }
  })
  .catch((error) => {
    console.error(error);
  });
