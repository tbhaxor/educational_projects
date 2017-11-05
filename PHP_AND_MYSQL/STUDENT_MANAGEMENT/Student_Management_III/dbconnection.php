<?php
// including all the variable from config.php
include_once 'config.php';

// connecting to data base and assigning the mysqli object to connection
$connection = new PDO("mysql:host=$dbhost;dbname=$dbname", $dbuser, $dbpass);

// setting error mode as try catch statement
$connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
?>
