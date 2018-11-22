const router = require("express").Router();
const hash = require("crypto");
const User = require("../models/user");
// check if looged in
router.get("/", (req, res) => {
    if (req.session.user) {
        res.status(404).render("404", {
            title: "Not Found",
            logged: req.session.user != undefined
        });
    } else {
        res.render("login", {
            title: "Login",
            logged: req.session.user != undefined
        });
    }
});

// loggin in 
router.post("/", (req, res) => {
    if (req.session.user != undefined) {
        res.redirect("/user/profile");
    } else {
        if (req.body.email === "" || req.body.password === "") {
            res.status(406).render("login", {
                title: "Login",
                error: "All fields are mandatory",
                logged: req.session.user != undefined
            });
        } else {
            req.body.password = hash.createHash("md5").update(req.body.password).digest("hex");
            //  checking for user
            User.findOne(req.body).exec((err, doc) => {
                // handling error
                if (err) {
                    res.status(503).render("login", {
                        title: "Login",
                        logged: req.session.user != undefined,
                        error: err
                    });
                }

                // checking user existance
                if (doc) {
                    req.session.user = doc.email;
                    req.session.name = doc.name;
                    res.render("login", {
                        title: "Login",
                        success: "Logged in",
                        logged: req.session.user != undefined,
                    });
                } else {
                    res.status(404).render("login", {
                        title: "Login",
                        info: "No user found",
                        logged: req.session.user != undefined,
                    });
                }
            });
        }
    }
});

router.get("/reset-password", (req, res) => {
    if (req.session.user != undefined) {
        res.status(404).render("404", {
            title: "Not Found",
        });
    } else {
        res.render("reset", {
            title: "Reset Password",
        });
    }
});

module.exports = router;