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
if(isset($_POST['yes']))
{
$id = $_GET['id'];
include_once '../dbconnection.php';
if($connection)
{
  $sql = "DELETE FROM `stumanage_students` WHERE `sno`=$id";
  if($connection->query($sql))
  {
    $connection->close();
    header("location:dashboard.php");
  }
  else {
    echo "<strong>Error : </strong>Can\'t Delete Data";
  }
}
else
{
  echo "<strong>Error : </strong>Can\'t Establish DB Connection";
}
}
echo "<div class=container><form action='' method=post><h3>Are You Sure To Delete All The Details ? </h3><button type=submit name=yes class='btn btn-success'><i class='glyphicon glyphicon-ok'></i> Yes</button>&nbsp;&nbsp;<a href='dashboard.php' class='btn btn-danger'><i class='glyphicon glyphicon-remove-sign'></i> No</a></form>";
?>
