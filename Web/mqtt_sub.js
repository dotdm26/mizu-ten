const mqtt = require('mqtt');
const fs = require('fs');
const addr = 'd448cde686ee4b58b8c75ca6f43118e7.s2.eu.hivemq.cloud'; // url                                          // port
//const client = mqtt.connect(addr);
let file_loacation = "./data.json"

const brokerPort = 8883;  
const clientId = 'web-client';
const username = 'metropolia';
const password = 'P4ss12345!';
const topic = 'my/topic';



const client = mqtt.connect(`${brokerUrl}:${brokerPort}`, {
    clientId: clientId,
    username: username,
    password: password,
  });

client.on('connect', function() {
    client.subscribe('controller/status');
    console.log("Testing connection")
    if (!fs.existsSync(file_loacation)) { // if the file is not exist create one
        fs.writeFileSync(file_loacation, JSON.stringify([]))
    }
})

client.on('message', function(t, data) {
    fs.readFile(file_loacation, 'utf8', (err, json_data) => {
        //Error
        if (err) {
            console.log(`Error reading file from disk: ${err}`);
        } 
        else {
            // parse JSON string to JSON object
            const databases = JSON.parse(json_data);
            const json_ = JSON.parse(data);
            // add a new record
            databases.push(json_);
            // write new data back to the file
            fs.writeFile(file_loacation, JSON.stringify(databases, null, 2), (err) => {
                //Error
                if (err) { 
                    console.log(`Error writing file: ${err}`);
                }
            });
        }
    });
})

module.exports = fs;





// to access mqtt on another file, input                        import './mqtt_sub.js';



/*
const mqtt = require('mqtt');

const brokerUrl = 'mqtt://mqtt.example.com';
const brokerPort = 1883; // or 8883 for secure connections
const clientId = 'web-client';
const username = 'metropolia';
const password = 'P4ss12345!';
const topic = 'my/topic';

const client = mqtt.connect(`${brokerUrl}:${brokerPort}`, {
  clientId: clientId,
  username: username,
  password: password,
});

client.on('connect', function () {
  console.log('Connected to MQTT broker');
  client.subscribe(topic);
});

client.on('message', function (topic, message) {
  console.log(`Received message on topic ${topic}: ${message.toString()}`);
  // Update your website UI with the received message
});

*/