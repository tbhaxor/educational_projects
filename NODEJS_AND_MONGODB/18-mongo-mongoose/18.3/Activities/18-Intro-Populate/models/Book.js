// Require mongoose
var mongoose = require("mongoose");

// Create a Schema class with mongoose
var Schema = mongoose.Schema;

// make BookSchema a Schema
var BookSchema = new Schema({
  // author: just a string
  author: {
    type: String
  },
  // title: just a string
  title: {
    type: String
  }
});

// NOTE: the book's id is stored automatically
// Our Library model will have an array to store these ids

// Create the Book model with the BookSchema
var Book = mongoose.model("Book", BookSchema);

// Export the model so we can use it on our server file.
module.exports = Book;
