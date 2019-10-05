// 4 - Sorting Results
// ================================

// The format of a sort follows db.COLLECTION_NAME.find().sort({FIELD:1})

// A value of 1 is for ascending order.
// A value of -1 is for descending order.

// NOTE: Remember to add .pretty() afterwards so the results are readable!
// In the mongo shell, using the animals collection that you created in the last exercise:

// 1. Show them how to sort by id:
// The id contains a timestamp, so sorting by id will sort by when they were entered to the database.
db.animals.find().sort({_id:1})
db.animals.find().sort({_id:-1})

// 2. Show them how to sort by an integer - numlegs:
db.animals.find().sort({numlegs:1})
db.animals.find().sort({numlegs:-1})


// 3. Show them how to sort by a string - class:
db.animals.find().sort({class:1})
db.animals.find().sort({class:-1})
