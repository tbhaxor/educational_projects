const router = require("express").Router();
const User = require("../models/user");
const hash = require("crypto");
const Book = require("../models/book");

router.get("/", (req, res) => {
    if (!req.session.user) {
        res.redirect("/login");
    } else {
        res.redirect("/user/profile");
    }
})

router.get("/profile", (req, res) => {
    if (!req.session.user) {
        res.redirect("/login");
    } else {
        Book.find().exec((err, books) => {
            if (err) {
                res.status(503).render("profile", {
                    title: "Dashboard",
                    name: req.session.name,
                    books: [],
                    error: "Something Went Wrong",
                    logged: req.session.user != undefined
                });
            } else {
                res.render("profile", {
                    title: "Dashboard",
                    name: req.session.name,
                    books: books,
                    logged: req.session.user != undefined
                });
            }
        });
    }
});

router.get("/logout", (req, res) => {
    if (!req.session.user) {
        res.status(404).render("404", {
            title: "Not Found"
        });
    } else {
        req.session.destroy(() => {
            res.redirect("/login");
        })
    }
});

router.get("/edit", (req, res) => {
    if (!req.session.user) {
        res.status(404).render("404", {
            title: "Not Found"
        });
    } else {
        res.render("edit", {
            title: "Edit Profile",
            userName: req.session.name,
            logged: req.session.user != undefined
        });
    }
});

router.post("/edit", (req, res) => {
    if (!req.session.user) {
        res.status(404).render("404", {
            title: "Not Found"
        });
    } else {
        if (req.body.password === '') {
            delete req.body.password;
        } else {
            req.body.password = hash.createHash("md5").update(req.body.password).digest("hex");
        }
        User.findOneAndUpdate({
            email: req.session.user
        }, req.body).exec((err, doc) => {
            if (err) {
                res.status(503).render("edit", {
                    title: "Edit Profile",
                    error: err,
                    userName: req.session.name,
                    logged: req.session.user != undefined
                });
            } else {
                req.session.name = req.body.name;
                res.render("edit", {
                    title: "Edit Profile",
                    success: "Updated",
                    userName: req.session.name,
                    logged: req.session.user != undefined
                });
            }
        });
    }
});

module.exports = router;