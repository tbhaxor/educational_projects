/* 18.1.2-Starting with Mongo JS
 * -/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/- */


// A. Use the command line to create a classroom database. 
// Insert entries for yourself and the people in your row in a students collection. 
// Each document should have:

// 1. A field of name with the person's name.
// 2. A field of rownumber which will contain the row number that they are in.
// 3. A field of os which will contain the Operating System 
//    of the computer they are using: 'Mac', 'Win', etc
// 4. A field of hobbies with an array of the hobbies the person likes to do.

// Example:
use classroom
db.classroom.insert({name: 'Steve', row:3, os:'Mac', hobbies:['Coding', 'Reading', 'Running'] })
	/* ASK STUDENTS FOR TWO-FOUR MORE EXAMPLES TO FILL OUT YOUR COLLECTION */

// B. Use find commands to get:
// 1. A list of everyone in your row.
db.classroom.find({row:3})

// 2. An entry for a single person.
db.classroom.find({name:'Steve'})

// 3. The entries for all the Mac users in your row. 
db.classroom.find({name:'Steve', row:3, os:'Mac'})

// Bonus:
// If you finish early, check out the MongoDB documentation 
// and figure out how to find users by an entry in an array.
db.classroom.find({"hobbies": {$in: ["hobby1"]}})