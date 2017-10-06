<html>
<head>
<title>Student Management Program</title>
<!--IMPORT STYLESHEET AND SCRIPT-->
<link rel="stylesheet" href="../assets/css/bootstrap.min.css">
<link rel="stylesheet" href="../assets/css/master.css">
<script type="text/javascript" src="../assets/js/bootstrap.min.js"></script>
<?php
if(!isset($_GET['id']) or empty(@$_GET['id']))
{
  die();
}
$id = $_GET['id'];
include_once '../dbconnection.php';
if($connection)
{

  $sql = "SELECT * FROM `stumanage_students` WHERE `sno`=$id";
  if($result = mysqli_query($connection,$sql))
  {
    $row = mysqli_fetch_assoc($result);
    echo "<center><h1>Viewing Details For $row[roll_no]</h1></center>";
    echo "<form action='' method=post class=form-horizontal>";
    echo "</form>";
  }
  else {
    echo "<strong>Error : </strong>Can\'t Delete Data";
  }
  mysqli_close($connection);
}
else
{
  echo "<strong>Error : </strong>Can\'t Establish DB Connection";
}
?>
