const router = require("express").Router();
const User = require("../models/user");
const hash = require("crypto");

/**
 * @name SEND_SIGNUP_FORM
 */
router.get("/", (req, res) => {
    if (req.session.user) {
        res.status(404).render("404", {
            title: "Not Found",
            logged: req.session.user != undefined
        });
    } else {
        res.render("signup", {
            title: "Signup",
            logged: req.session.user != undefined
        });
    }
});

/**
 * @name CREATE_NEW_USER
 */
router.post("/", (req, res) => {
    if (req.session.user != undefined) {
        res.redirect("/user/profile");
    }
    // validating
    if (req.body.name == "") {
        req.body.name = "No Name"
    }
    if (req.body.email == "" || req.body.password == "") {
        res.render("signup", {
            title: "Signup",
            error: "All fields are mandatory",

        });
    } else {
        // attempt creating new user

        // hashing password
        req.body.password = hash.createHash('md5').update(req.body.password).digest("hex");

        // chking if user exists
        User.findOne({ // seting unique payload
            email: req.body.email
        }).exec((err, findResult) => {
            if (err) { // sending error response on error
                res.status(503).render("signup", {
                    title: "Signup",
                    error: err
                });
            } else {
                // attempt to create new user
                if (findResult) { // user already exists
                    res.render("signup", {
                        title: "Signup",
                        info: "User already exists"
                    });
                } else { // creating new user here
                    const user = new User(req.body);

                    // saving to db
                    user.save((err, doc) => {
                        if (err) { // sending error response on error
                            res.status(503).render("signup", {
                                title: "Signup",
                                error: err
                            });
                        } else { // user saved successfully, Send success message
                            res.render("signup", {
                                title: "Signup",
                                success: "Successfully Registered"
                            });
                        }
                    });
                }
            }
        });
    }
});


module.exports = router;