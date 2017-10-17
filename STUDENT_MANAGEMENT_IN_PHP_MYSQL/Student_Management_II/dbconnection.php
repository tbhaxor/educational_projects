<?php
// including all the variable from config.php
include_once 'config.php';

// connecting to data base and assigning the mysqli object to connection
$connection = new mysqli($dbhost, $dbuser, $dbpass, $dbname);
?>
