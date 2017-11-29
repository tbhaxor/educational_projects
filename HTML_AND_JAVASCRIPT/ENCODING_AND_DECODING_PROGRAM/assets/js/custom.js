//  -----------------------
//    Function to alert popup coder informations
//  -----------------------
function info () {
	var coder = "Mr. Gurkirat Singh"
	var submitted_to = "Mrs. Anita Pathak"
	var institution = "MDU Rohtak"
	alert("Coded By : " + coder + "\n" + 
		  "Submitted To : " + submitted_to + "\n"+ 
		  "Institution : " + institution
		  )   // alert popup for displaying coder info
}

//  -----------------------
//    Function to convert string to base64
//  -----------------------
function stb () {
	var input = document.getElementById('stb-input')  // getting properties of html element by id stb-input
	var output = document.getElementById('stb-output')   // getting properties of html element by id stb-ouput
	if(input.value == "")     // checking if input field is empty of not
		alert("Enter your string")   // alerting user to enter some text
	else
		output.value = btoa(input.value)     // converting string to base 64 using built in functions
}

//  -----------------------
//    Function to convert base64 to string
//  -----------------------
function bts () {
	var input = document.getElementById('bts-input')    // getting properties of html element by id bts-input
	var output = document.getElementById('bts-output')     // getting properties of html element by id bts-input
	if(input.value == "")    // checking if input field is empty of not
		alert("Enter your string")    // alerting user to enter some text
	else
		output.value = atob(input.value)     // converting base 64 to string using built in functions
}

//  -----------------------
//    Function to convert binary to string
//  -----------------------
function bin2str() {
	var input = document.getElementById('bin2str-input')    // getting properties of html element by id bin2str-input
	var output = document.getElementById('bin2str-output')     // getting properties of html element by id bin2str-input
	var bins = input.value.split(" ")    // making and array by spliting input.value wth " " as a delimiter
	var str = ""
	if(input.value == "")    // checking if input field is empty of not
		alert("Enter your string")    // alerting user to enter some text
	else
	{
		for(var i = 0; i < bins.length -1 ; i++)   // iterating loop body till bins.length - 1 to ignore last split by  " "
		{
			str += String.fromCharCode(parseInt(bins[i], 2))    // this will take ASCII code as int (parseInt converting string type of binary to int) with base 2 and generate a new String from "fromCharCode"
		}
		output.value = str
	}		

}

//  -----------------------
//    Function to convert string to binary
//  -----------------------
function str2bin() {
	var input = document.getElementById('str2bin-input')    // getting properties of html element by id str2bin-input
	var output = document.getElementById('str2bin-output')     // getting properties of html element by id str2bin-input
	var temp = ""    // temporary variable to store data
	if(input.value == "")    // checking if input field is empty of not
		alert("Enter your string")    // alerting user to enter some text
	else
	{
		for(var i = 0; i < input.value.length; i++)   // iterating loop body until and unless i != input.value.length
		{
			temp += input.value[i].charCodeAt(0).toString(2) + " "    // this will get ASCII code of each char of input string and convert that into string where 2 means base
		}
		output.value = temp
	}
}

//  -----------------------
//    Function to perform string escaping
//  -----------------------
function esc() {
	var input = document.getElementById('esc-input')    // getting properties of html element by id esc-input
	var output = document.getElementById('esc-output')     // getting properties of html element by id esc-input
	if (input.value == "")   // checking if input field is empty of not
		alert("Enter your string")    // checking if input field is empty of not
	else
		output.value = escape(input.value)  // escaping string from built in function
	
}

//  -----------------------
//    Function to perform string unescaping
//  -----------------------
function unesc() {
	var input = document.getElementById('unesc-input')    // getting properties of html element by id unesc-input
	var output = document.getElementById('unesc-output')     // getting properties of html element by id unesc-input
	if (input.value == "")   // checking if input field is empty of not
		alert("Enter your string")    // checking if input field is empty of not
	else
		output.value = unescape(input.value)  // unescaping string from built in function
}
