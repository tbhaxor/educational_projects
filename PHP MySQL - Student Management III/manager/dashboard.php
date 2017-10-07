<html>
<head>
<title>Student Management Program</title>
<!--IMPORT STYLESHEET AND SCRIPT-->
<link rel="stylesheet" href="../assets/css/bootstrap.min.css">
<link rel="stylesheet" href="../assets/css/master.css">
<script type="text/javascript" src="../assets/js/bootstrap.min.js"></script>

<!--PHP BACKEND and FrontEnd-->
<?php
session_start();
include_once '../info.php';
if(isset($_POST['logout']) or !isset($_SESSION['slogin']))
{
  session_unset();
  header("location:../");
}
if(isset($_POST['new']))
{
  header("location:new.php");
}
echo "<center><div class='container margin-bottom-20 jumbotron header'><h2 class=top>Project Name : ".@$project."<br>Coded By : ".@$coder."<br>Submitted To :".@$submited_to."</h1></div></center>";
echo '<div class=container>';
echo '<form action="" method="post"><div class=row><div class=col-xs-4><button class="btn btn-primary" type=submit name="new"><i class="glyphicon glyphicon-plus-sign"></i> Add New Student</button></div>';
echo "<div class='col-xs-4 centerText'>Welcome, <b>$_SESSION[suser]</b></div>";
echo '<div class=col-xs-4><button class="btn btn-warning pull-right" type=submit name=logout><i class="glyphicon glyphicon-log-out"></i> Log Out</button></div></div></form>';
echo "<table class=table><tr class=studentTitle><th width=7% class='studentTitle'>#</th><th width=20% class='studentTitle'>Roll Number</th><th width=50% class='studentTitle'>Name</th><th width=23% class='studentTitle'>Action</th></tr>";
include_once '../dbconnection.php';
if($connection)
{
  $sql = "SELECT * FROM `stumanage_students`";
  $result = $connection->query($sql);
  while($row = $result->fetch_assoc())
  {
    echo "<tr class=students><td>$row[sno]</td><td>$row[roll_no]</td><td>$row[name]</td><td><a href='view.php?id=$row[sno]' title='View' class='btn btn-default margin-right-10'><i class='glyphicon glyphicon-eye-open'></i> View</a><a href='delete.php?id=$row[sno]' title='Delete' class='btn btn-danger margin-left-10'><i class='glyphicon glyphicon-remove-sign'></i> Delete</a></td></tr>";
  }
  $connection->close();
}
else {
  echo "<strong>Error : </strong>Can\'t Establish DB Connection";
}
echo "<table></div>";
?>
