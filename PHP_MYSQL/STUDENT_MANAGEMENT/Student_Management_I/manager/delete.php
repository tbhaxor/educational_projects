<!--
  Delete Entry Confirmation page
-->
<html>
<head>
<title>Student Management Program</title>
<!--IMPORT STYLESHEET AND SCRIPT-->
<link rel="stylesheet" href="../assets/css/bootstrap.min.css">
<link rel="stylesheet" href="../assets/css/master.css">
<script type="text/javascript" src="../assets/js/bootstrap.min.js"></script>

<!--
  PHP Backend and Frontend
-->
<?php
if(!isset($_GET['id']) or empty(@$_GET['id'])) // checks whether url contains any id parameter and is not empty
{
  /*
   * stops entire script if id parameter is not set or empty
   */
  die();
}
if(isset($_POST['yes']))  // check whether user pressed yes or not
{
  /*
   * user pressed yes
   */
  $id = $_GET['id']; // getting value of id parameter
  include_once '../dbconnection.php';  // including dbconnection.php to set db connection
  if($connection) // checks whether connection to database is Established or not
  {
    /*
     * connection to database is Established
     */
    $sql = "DELETE FROM `stumanage_students` WHERE `sno`=$id";  // sql to delete tuple from the table "stumanage_students"
    if(mysqli_query($connection,$sql))  // running query on connection and checking if tuple is deleted or not
    {
      /*
       * tuple is deleted
       */
      mysqli_close($connection);  // closing the mysql connection
      header("location:dashboard.php");  // redirecting to dashboard
    }
    else {
      /*
       * tuple is not deleted
       */
      echo "<strong>Error : </strong>Can\'t Delete Data";
    }
  }
  else
  {
    /*
     * database connection is not Established
     */
    echo "<strong>Error : </strong>Can\'t Establish DB Connection";
  }
}
echo "<div class=container><form action='' method=post><h3>Are You Sure To Delete All The Details ? </h3><button type=submit name=yes class='btn btn-success'><i class='glyphicon glyphicon-ok'></i> Yes</button>&nbsp;&nbsp;<a href='dashboard.php' class='btn btn-danger'><i class='glyphicon glyphicon-remove-sign'></i> No</a></form>";
?>
