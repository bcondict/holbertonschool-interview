# Failure tries
This are all the tries that I made to solve the problem. here are the steps that I followed to solve the problem.

### first
```js
const request = require('https');

request('https://swapi-api.hbtn.io/api/films/' + args, function (error, response, body) {
  if (!error && response.statusCode === 200) {
    let json = JSON.parse(body);
    let characters = json.characters;
    for (let i = 0; i < characters.length; i++) {
      request(characters[i], function (error, response, body) {
        if (!error && response.statusCode === 200) {
          let json = JSON.parse(body);
          console.log(json.name);
        }
      });
    }
  }
  else {
    console.log(error);
  }
});
```


### second
```js
const request = require('request');
request('https://swapi-api.hbtn.io/api/films/' + args, function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    let results = JSON.parse(body).characters;
    for (let i = 0; i < results.length; i++) {
      request(results[i], function (error, response, body) {
        if (error) {
          console.log(error);
        } else {
          console.log(JSON.parse(body).name);
        }
      });
    }
  }
});
```


### thrid
```js
let args = parseInt(Array.prototype.slice.call(process.argv, 2));
const request = require('https');
const url = 'https://swapi-api.hbtn.io/api/films/' + args;
const options = {
  hostname: 'swapi-api.hbtn.io',
  port: 443,
  path: '/api/films/' + args,
  method: 'GET'
};

const req = request.request(options, (res) => {
  let data = '';
  res.on('data', (d) => {
    data += d;
  });
  res.on('end', () => {
    let characters = JSON.parse(data).characters;
    for (let i = 0; i < characters.length; i++) {
      const options = {
        hostname: 'swapi-api.hbtn.io',
        port: 443,
        path: characters[i].slice(21),
        method: 'GET'
      };
      const req = request.request(options, (res) => {
        let data = '';
        res.on('data', (d) => {
          data += d;
        });
        res.on('end', () => {
          console.log(JSON.parse(data).name);
        });
      });
      req.on('error', (error) => {
        console.error(error);
      });
      req.end();
    }
  });
});
```

### fourth
```js
request.get(url, function (err, res, body) {
  if (err) {
    console.log("hola");
    return;
  }
  let characters = JSON.parse(body).characters;
  for (let i = 0; i < characters.length; i++) {
    request.get(characters[i], function (err, res, body) {
      if (err) {
        console.log(err);
      } else {
        console.log(JSON.parse(body).name);
      }
    });
  }
  console.log(characters);
});
```


### fifth
using fetch 
```js
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
```


### sixth
functional but in other order
```js
let args = process.argv[2];
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + args;

request(url, function (error, response, body) {
  if (error) {
    throw error;
  }

  let data = JSON.parse(body).characters;
  for (let i = 0; i < data.length; i++) {
    request(data[i], function (error, response, body) {
      if (error) {
        console.error(error);
      }
      let data = JSON.parse(body);
      console.log(data.name);
    });
  }
});

```


### seventh
```js
let args = process.argv[2];
const request = require('request-promise');
const url = 'https://swapi-api.hbtn.io/api/films/' + args;

request(url)
  .then((body) => {
    let data = JSON.parse(body).characters;
    let promises = [];

    for (let i = 0; i < data.length; i++) {
      promises.push(request(data[i]));
    }
    return Promise.all(promises);
  })
  .then((responses) => {
    let names = responses.map((response) => JSON.parse(response).name);
    console.log(names);
  })
  .catch((error) => {
    console.error(error);
  });
```

### eighth
```js
const args = process.argv[2];
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${args}`;

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
    for (let i = 0; i < data.length; i++) {
      promises.push(makeRequest(data[i]));
    }
    return Promise.all(promises);
  })
  .then((responses) => {
    const names = responses.map((response) => JSON.parse(response).name);
    console.log(names);
  })
  .catch((error) => {
    console.error(error);
  });
```


### final
```js
const args = process.argv[2];
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${args}`;

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
    for (let i = 0; i < data.length; i++) {
      promises.push(makeRequest(data[i]));
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
```
