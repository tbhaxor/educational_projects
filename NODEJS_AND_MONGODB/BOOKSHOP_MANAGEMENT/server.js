const express = require("express");
const logger = require("morgan");
const expressSession = require("express-session");
const cookieParser = require("cookie-parser");
const bodyParser = require("body-parser");
const handleBars = require("express-handlebars");
const path = require("path");
const mongoose = require("mongoose");
mongoose.Promise = global.Promise;

// connecting to db
mongoose.connect("mongodb://localhost:27017/book-shop").then(() => {
    console.log("Connected To DB");
}).catch(() => {
    console.log("Failed to connect to db");
    process.exit(1);
});

// creating app
const app = express();

// using middle wares
app.use(express.static(path.resolve(path.join(__dirname, "./public")))); // adding static directory path
app.engine('hbs', handleBars({ // adding handlebars
    extname: 'hbs',
    defaultLayout: 'layout',
    layoutsDir: __dirname + '/views/layouts/'
}));
app.set('views', path.join(__dirname, 'views')); // setting path to views
app.set('view engine', 'hbs'); // adding extension
app.use(logger("dev")); // setting logger
app.use(bodyParser.json()); // adding body parser
app.use(bodyParser.urlencoded({ // adding body parser for forms
    extended: false
}))
app.use(cookieParser());
app.use(expressSession({
    secret: 'max',
    saveUninitialized: false,
    resave: false
}));
app.use(expressSession({
    cookie: {
        secure: false,
        maxAge: 864000000
    },
    saveUninitialized: true,
    resave: false,
    secret: "Ki1ETSQSNC",
    name: "Book Shop",

}))
// managing routes
app.get("/", (req, res) => {
    res.render("index", {
        title: "Home",
        logged: req.session.user != undefined
    });
});
app.use("/login", require("./routes/login"));
app.use("/signup", require("./routes/signup"));
app.use("/user", require("./routes/user"));
app.use("/book", require("./routes/book"));


// handling 404
app.get("*", (req, res) => {
    res.status(404).render("404", {
        title: "Not Found",
        logged: req.session.user != undefined
    });
});

// starting server
app.listen(3000, () => {
    console.clear();
    console.log("[%s]\tServer listening on http://localhost:3000", new Date())
})