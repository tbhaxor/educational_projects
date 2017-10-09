<?php
include_once 'config.php';
$connection = new PDO("mysql:host=$dbhost;dbname=$dbname", $dbuser, $dbpass);
$connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
  
?>
