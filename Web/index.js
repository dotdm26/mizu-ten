const routes = require("./routes");
const express = require('express'); 
var session = require('express-session');
const app = express();

//EJS
app.set('view engine', 'ejs');
app.use(session({
    secret: 'djhxcvxfgshjfgjhgsjhfgakjeauytsdfy', // a secret key you can write your own 
    resave: false,
    saveUninitialized: true
}));
app.use('/', routes);

//MongoDb connection
const mongoose = require('mongoose'); //mongoose
const mongoURL = 'mongodb://danils:metropolia123@cluster0-shard-00-00.bcxje.mongodb.net:27017,cluster0-shard-00-01.bcxje.mongodb.net:27017,cluster0-shard-00-02.bcxje.mongodb.net:27017/test?replicaSet=atlas-cl2wx4-shard-0&ssl=true&authSource=admin';
mongoose.connect(mongoURL, { useNewUrlParser: true });

const db = mongoose.connection;
//Error
db.on('error', console.error.bind(console, 'MongoDB connection error:'));

//configure the server port
const PORT = 3000;
app.listen(PORT, () => {
    console.log('Server runs on port 3000')
})
