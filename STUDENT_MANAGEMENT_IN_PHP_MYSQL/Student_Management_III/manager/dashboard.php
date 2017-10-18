<!--
    DASHBOARD
-->
<html>
<head>
<title>Student Management Program</title>
<!--IMPORT STYLESHEET AND SCRIPT-->
<link rel="stylesheet" href="../assets/css/bootstrap.min.css">
<link rel="stylesheet" href="../assets/css/master.css">
<script type="text/javascript" src="../assets/js/bootstrap.min.js"></script>

<!--PHP BACKEND and FrontEnd-->
<?php
session_start(); // starting the session

include_once '../info.php'; // including info file

if(isset($_POST['logout']) or !isset($_SESSION['slogin'])) // checking whether user wants to logout or user is already logged out
{
  /*
   * User is not logged in
   */
   session_unset();  // unsetting all sessions
   header("location:../");  // redirecting to portal page
}

if(isset($_POST['new'])) // checking whether user wants to add new details or not
{
  /*
   * User wants to add new student info
   */
   header("location:new.php");  // redirecting to page
}
// printing main banner
echo "<center><div class='container margin-bottom-20 jumbotron header'><h2 class=top>Project Name : ".@$project."<br>Coded By : ".@$coder."<br>Submitted To :".@$submited_to."</h1></div></center>";
echo '<div class=container>';
echo '<form action="" method="post"><div class=row><div class=col-xs-4><button class="btn btn-primary" type=submit name="new"><i class="glyphicon glyphicon-plus-sign"></i> Add New Student</button></div>';
echo "<div class='col-xs-4 centerText'>Welcome, <b>$_SESSION[suser]</b></div>";
echo '<div class=col-xs-4><button class="btn btn-warning pull-right" type=submit name=logout><i class="glyphicon glyphicon-log-out"></i> Log Out</button></div></div></form>';
echo "<table class=table><tr class=studentTitle><th width=7% class='studentTitle'>#</th><th width=20% class='studentTitle'>Roll Number</th><th width=50% class='studentTitle'>Name</th><th width=23% class='studentTitle'>Action</th></tr>";

include_once '../dbconnection.php';  // including dbconnection.php to Establish connection with database
if($connection)  // checking whether connection Established or not
{
  /*
   * Connection has been Established
   */
  $sql = "SELECT * FROM `stumanage_students`"; // selecting all details of the all students
  $statement = $connection->prepare($sql); // preparing sql query
  $statement->execute();  // executing sql query
  $statement->setFetchMode(PDO::FETCH_ASSOC);  // loop will itertrate till it fetchs details
  $result = $statement->fetchall();  // fetching all the data

  // printing the data
  foreach($result as $row)
  {
    echo "<tr class=students><td>$row[sno]</td><td>$row[roll_no]</td><td>$row[name]</td><td><a href='view.php?id=$row[sno]' title='View' class='btn btn-default margin-right-10'><i class='glyphicon glyphicon-eye-open'></i> View</a><a href='delete.php?id=$row[sno]' title='Delete' class='btn btn-danger margin-left-10'><i class='glyphicon glyphicon-remove-sign'></i> Delete</a></td></tr>";
  }
  $connection = null;  // closing mysql connection
}
else {
  /*
   * Error while establishng the conneciton
   */
  echo "<strong>Error : </strong>Can\'t Establish DB Connection";
}
echo "<table></div>";
?>
