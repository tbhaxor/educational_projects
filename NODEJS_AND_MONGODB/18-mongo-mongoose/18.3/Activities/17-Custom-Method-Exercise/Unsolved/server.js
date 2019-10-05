/* Custom Methods (Student) (18.3.5)
 * ===================================== */


/* INSTRUCTIONS:
 * 1: Go to userModel.js, and create custom methods
 *    based on the details offered in the file.
 *
 * 2: Once you've made those custom methods, use them
 *    in this file's POST request
 *
 *    Good luck!
 * -/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ */


// Dependencies
var express = require("express");
var bodyParser = require("body-parser");
var logger = require("morgan");
var mongoose = require("mongoose");
// Set mongoose to leverage built in JavaScript ES6 Promises
mongoose.Promise = Promise;

// Require our userModel model
var Example = require("./userModel.js");

// Initialize Express
var app = express();


// Use morgan and body parser with our app
app.use(logger("dev"));
app.use(bodyParser.urlencoded({
  extended: false
}));

// Make public a static dir
app.use(express.static("public"));


// Database configuration with mongoose
mongoose.connect("mongodb://localhost/week18day3mongoose");
var db = mongoose.connection;

// Show any mongoose errors
db.on("error", function(error) {
  console.log("Mongoose Error: ", error);
});

// Once logged in to the db through mongoose, log a success message
db.once("open", function() {
  console.log("Mongoose connection successful.");
});


// Routes
// ======

app.post("/submit", function(req, res) {

  var user = new Example(req.body);


/* OUR CUSTOM METHODS
 * (methods created in the userModel.js)
 * -/-/-/-/-/-/-/-/-/ */


 // TODO: Use our custom methods to create
 // the FullName and LastUpdatedDate entries
 // in the doc that the user submits. These
 // will get saved to the mongoDB collection.
 //
 // TIP: You must create these methods in the model.


// END OF CUSTOM METHODS
// =====================
// NORMAL METHOD BELOW

  // Save a user to our mongoDB
  user.save(function(error, doc) {
    // Send an error to the browser
    if (error) {
      res.send(error);
    }
    // Or send the doc to our browser
    else {
      res.send(doc);
    }
  });
});

// Listen on port 3000
app.listen(3000, function() {
  console.log("App running on port 3000!");
});
