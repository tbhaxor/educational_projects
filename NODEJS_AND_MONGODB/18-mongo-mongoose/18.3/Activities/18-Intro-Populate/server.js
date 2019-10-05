/* Showing Mongoose's "Populated" Method (18.3.6)
 * INSTRUCTOR ONLY
 * =============================================== */

// Dependencies
var express = require("express");
var bodyParser = require("body-parser");
var logger = require("morgan");
var mongoose = require("mongoose");
// Set mongoose to leverage built in JavaScript ES6 Promises
mongoose.Promise = Promise;

// Bring in our Models: Book and Library
var Book = require("./models/Book.js");
var Library = require("./models/Library.js");

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


// We'll create a new Library by using the Library model as a class
// The "unique" rule in the Library model's schema will prevent duplicate libraries from being added to the server
var exampleLibrary = new Library({
  name: "Campus Library"
});
// Using the save method in mongoose, we create our example library in the db
exampleLibrary.save(function(error, doc) {
  // Log any errors
  if (error) {
    console.log(error);
  }
  // Or log the doc
  else {
    console.log(doc);
  }
});


// Routes
// ======

// This POST route handles the creation of a new book in our mongodb books collection
app.post("/submit", function(req, res) {

  var newBook = new Book(req.body);

// Save the new book in the books collection
  newBook.save(function(err, doc) {
    // Send an error to the browser if there's something wrong
    if (err) {
      res.send(err);
    }
    // Otherwise...
    else {
    // Find one library in our Library collection (there's only one, so that's fine),
    // then update it by pushing the object id of the book we just saved
    //
    // REMEMBER: doc is a variable containing the document of the book we just saved,
    // so calling doc._id will grab the id of the doc, in this case, our new book

    // ALSO: We need "{new: true}" in our call,
    // or else our query will return the object as it was before it was updated
      Library.findOneAndUpdate({}, { $push: { "books": doc._id } }, { new: true }, function(error, doc) {
        // Send any errors to the browser
        if (error) {
          res.send(error);
        }
        // Or send the doc to the browser
        else {
          res.send(doc);
        }
      });
    }
  });
});


// This GET route let's us see the books we have added
app.get("/books", function(req, res) {
  // Using our Book model, "find" every book in our book db
  Book.find({}, function(error, doc) {
    // Send any errors to the browser
    if (error) {
      res.send(error);
    }
    // Or send the doc to the browser
    else {
      res.send(doc);
    }
  });
});


// Route to see what our library data looks in the browser
app.get("/library", function(req, res) {
  // Find all of the entries of Library (there's only one, remember)
  Library.find({}, function(error, doc) {
    // Send an error message to the browser
    if (error) {
      res.send(error);
    }
    // Or send the doc to the browser
    else {
      res.send(doc);
    }
  });
});

// Route to see what library looks like WITH populating
app.get("/populated", function(req, res) {
  // Set up a query to find all of the entries in our Library..
  Library.find({})
    // ..and string a call to populate the entry with the books stored in the library's books array
    // This simple query is incredibly powerful. Remember this one!
    .populate("books")
    // Now, execute that query
    .exec(function(error, doc) {
      // Send any errors to the browser
      if (error) {
        res.send(error);
      }
      // Or, send our results to the browser, which will now include the books stored in the library
      else {
        res.send(doc);
      }
    });
});

// Listen on port 3000
app.listen(3000, function() {
  console.log("App running on port 3000!");
});
