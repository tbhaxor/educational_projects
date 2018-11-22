const mongoose = require("mongoose");
const Schema = require("mongoose").Schema;
const Types = require("mongoose").Types;

const UserSchema = new Schema({
    name: String,
    email: String,
    password: String,
})

module.exports = mongoose.model("User", UserSchema);