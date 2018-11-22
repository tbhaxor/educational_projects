const mongoose = require("mongoose");
const Schema = mongoose.Schema;

const BookSchema = new Schema({
    title: String,
    quantity: Number,
    price: Number,
    author: String
});



module.exports = mongoose.model("Book", BookSchema)