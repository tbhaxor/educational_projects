/* Mongoose Example (Solution) (18.3.03)
 * ===================================== */

// Dependency
var mongoose = require("mongoose");

// Create the Schema class
var Schema = mongoose.Schema;

// Instantiate a userSchema object with the Schema class we just made
var UserSchema = new Schema({
  // username is a string. We will trim any trailing whitespace. It's also required
  username: {
    type: String,
    trim: true,
    required: "Username is Required"
  },
  // password is a string. We will trim any trailing whitespace. It's also required
  // It has a custom validate function that checks the length of the input
  // If it's less than six chars, mongoose will throw an error
  password: {
    type: String,
    trim: true,
    required: "Password is Required",
    validate: [
      function(input) {
        return input.length >= 6;
      },
      "Password should be longer."
    ]
  },
  // email is a string, and it must be a unique one in our collection
  // Notice how it must match our regex, which checks for email
  email: {
    type: String,
    unique: true,
    match: [/.+\@.+\..+/, "Please enter a valid e-mail address"]
  },
  // This will make a userCreated entry in our doc, by default the current time string.
  userCreated: {
    type: Date,
    default: Date.now
  }
});

// Create the "User" model with our UserSchema schema
var User = mongoose.model("User", UserSchema);

// Export the User model, so it can be used in server.js with a require
module.exports = User;
