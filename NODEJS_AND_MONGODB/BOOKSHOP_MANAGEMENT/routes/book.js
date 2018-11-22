const router = require("express").Router();
const Book = require("../models/book");

router.get("/", (req, res) => {
    res.status(404).render("404", {
        title: "Not Found",
        logged: req.session.user != undefined
    });
});


router.get("/add", (req, res) => {
    if (!req.session.user) {
        res.status(404).render("404", {
            title: "Not Found",
        });
    } else {
        res.render("bookAdd", {
            title: "Add New Book",
            logged: req.session.user != undefined
        });
    }
});

router.post("/add", (req, res) => {
    if (!req.session.user) {
        res.status(404).render("404", {
            title: "Not Found",
        });
    } else {
        if (req.body.title == "" || req.body.quantity == "" || req.body.price == "" || req.body.author == "") {
            res.status(406).render("bookAdd", {
                title: "Add New Book",
                logged: req.session.user != undefined,
                info: "All fields are mandatory"
            });
        } else {
            req.body.quantity = parseInt(req.body.quantity);
            req.body.price = parseFloat(req.body.price);
            const book = new Book(req.body);
            book.save((err, doc) => {
                if (err) {
                    res.status(503).render("bookAdd", {
                        title: "Add New Book",
                        error: "Something wnt wrong",
                        logged: req.session.user != undefined
                    });
                } else {
                    res.render("bookAdd", {
                        title: "Add New Book",
                        logged: req.session.user != undefined,
                        success: "New Book Added",
                        info: "ID = " + doc._id
                    });
                }
            });
        }
    }
});


router.get("/:id/view", (req, res) => {
    if (!req.session.user) {
        res.status(404).render("404", {
            title: "Not Found",
        });
    } else {
        Book.findById(req.params.id).exec((err, doc) => {
            if (doc) {
                res.render("bookView", {
                    title: "Details of book",
                    logged: req.session.user != undefined,
                    book: doc
                });
            } else {
                res.status(404).render("404", {
                    title: "Not Found",
                    logged: req.session.user != undefined,
                });
            }
        });
    }
});

router.get("/:id/delete", (req, res) => {
    if (!req.session.user) {
        res.status(404).render("404", {
            title: "Not Found",
        });
    } else {
        Book.findByIdAndDelete(req.params.id).exec((err, doc) => {
            if (doc) {
                res.redirect("/user/profile");
            } else {
                res.status(404).render("404", {
                    title: "Not Found",
                    logged: req.session.user != undefined,
                });
            }
        });
    }
});


router.get("/:id/edit", (req, res) => {
    if (!req.session.user) {
        res.status(404).render("404", {
            title: "Not Found",
        });
    } else {
        Book.findById(req.params.id).exec((err, doc) => {
            if (doc) {
                res.render("bookEdit", {
                    title: "Edit book",
                    logged: req.session.user != undefined,
                    book: doc
                });
            } else {
                res.status(404).render("404", {
                    title: "Not Found",
                    logged: req.session.user != undefined,
                });
            }
        });
    }
});

router.post("/:id/edit", (req, res) => {
    if (!req.session.user) {
        res.status(404).render("404", {
            title: "Not Found",
        });
    } else {
        if (req.body.title == "" || req.body.quantity == "" || req.body.price == "" || req.body.author == "") {
            res.status(406).render("bookAdd", {
                title: "Add New Book",
                logged: req.session.user != undefined,
                info: "All fields are mandatory"
            });
        } else {
            req.body.quantity = parseInt(req.body.quantity);
            req.body.price = parseFloat(req.body.price);
            Book.findByIdAndUpdate(req.params.id, req.body).exec((err, doc) => {
                if (doc) {
                    res.render("bookEdit", {
                        title: "Edit book",
                        logged: req.session.user != undefined,
                        book: req.body,
                        info: "Updated"
                    });
                } else {
                    res.status(404).render("404", {
                        title: "Not Found",
                        logged: req.session.user != undefined,
                    });
                }
            });
        }

    }
})
module.exports = router;