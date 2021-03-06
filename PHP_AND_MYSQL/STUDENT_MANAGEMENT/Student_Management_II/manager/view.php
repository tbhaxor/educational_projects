<!--
 View details and updation page
-->
<html>
<head>
<title>Student Management Program</title>
<!--IMPORT STYLESHEET AND SCRIPT-->
<link rel="stylesheet" href="../assets/css/bootstrap.min.css">
<link rel="stylesheet" href="../assets/css/master.css">
<script type="text/javascript" src="../assets/js/bootstrap.min.js"></script>

<!--
PHP Backend and forntend
-->
<?php
if(!isset($_GET['id']) or empty(@$_GET['id'])) // checks whether url contains any id parameter and is not empty
{
  /*
   * stops entire script if id parameter is not set or empty
   */
  die();
}
$id = $_GET['id'];  // getting value of id parameter
include_once '../dbconnection.php';  // including dbconnection.php to set db connection
if(isset($_POST['update']) and $connection)  // checks whether connection to database is Established or not and if user wants to change
{
  /*
   * connection to db is Established and user wants to update the changes
   *
   * getting POST Request details from the user and storing the variable
   */
  $roll_no = $_POST['rollno'];
  $name = $_POST['name'];
  $dob = $_POST['dob'];
  $email = $_POST['email'];
  $cnum = $_POST['cnum'];
  $fname = $_POST['fname'];
  $fcnum = $_POST['fcnum'];
  $mname = $_POST['mname'];
  $mcnum = $_POST['mcnum'];
  $addr = $_POST['addr'];
  $nationality = $_POST['nationality'];
  $remarks = $_POST['remarks'];

  // running query on connection and checking if tuple is updated or not
  if($connection->query("UPDATE `stumanage_students` SET `roll_no`='$roll_no',`name`='$name',`dob`='$dob',`father_name`='$fname',`mother_name`='$mname',`email`='$email',`contact_number`='$cnum',`father_c_number`='$fcnum',`mother_c_number`='$mcnum',`nationality`='$nationality',`address`='$addr',`remarks`='$remarks' WHERE `sno`='$id'"))
  {
    /*
     * tuple is updated
     */
    echo "<script>alert('ERROR : Successfully Updated');window.location.href='dashboard.php';</script>"; // redirecting to dashboard
  }
  else
  {
    /*
     * tuple is not updated
     */
    echo "<script>alert('ERROR : Not Updated');window.location.href='dashboard.php';</script>";   // redirecting to dashboard
  }
  $connection->close();  // closing the mysql connection
}
else
{
  /*
   * user doesnt wants to update
   */
  if($connection) // checks whether connection to database is Established or not
  {
    $sql = "SELECT * FROM `stumanage_students` WHERE `sno`=$id";  // select Details for particular student
    if($result = $connection->query($sql))   // running query on connection and checking is entry exists or not
    {
      $row = $result->fetch_assoc();  // fetching data from result
      echo "<center><h1>Viewing Details For $row[roll_no]</h1></center><br><br><br>";
      echo "<form action='' method=post class=form-horizontal><div class=container>";
      echo "<div class=form-group><div class=col-xs-3><strong>Roll Number</strong></div><div class=col-xs-4><input type=text name='rollno' value='$row[roll_no]' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Student's Name</strong></div><div class=col-xs-4><input type=text name='name' value='$row[name]' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Date of Birth</strong></div><div class=col-xs-4><input type=date name='dob' value='$row[dob]' class=form-control></div><div class=col-xs-4 style=font-family:monospace;margin-top:7px;><i>Format used -> DD/MM/YYY</i></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Email Address</strong></div><div class=col-xs-4><input type=text name='email' value='$row[email]' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Student't Contact Number</strong></div><div class=col-xs-4><input type=text name='cnum' value='$row[contact_number]' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Father's Name</strong></div><div class=col-xs-4><input type=text name='fname' value='$row[father_name]' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Father's Contact Number</strong></div><div class=col-xs-4><input type=text name='fcnum' value='$row[father_c_number]' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Mother's Name</strong></div><div class=col-xs-4><input type=text name='mname' value='$row[mother_name]' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Mother's Contact Number</strong></div><div class=col-xs-4><input type=text name='mcnum' value='$row[mother_c_number]' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Address</strong></div><div class=col-xs-4><input type=text name='addr' value='$row[address]' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Nationality</strong></div><div class=col-xs-4><input type=text name='nationality' value='$row[nationality]' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>How $row[name] is performing?</strong></div><div class=col-xs-4><input type=text name='remarks' value='$row[remarks]' class=form-control></div></div>";
      echo "<center><button name='update' class='btn btn-warning btn-lg' style='width:50%'><i class='glyphicon glyphicon-pencil'></i> Update</button></center>";
      echo "</div></form>";
    }
    else {
      /*
       * entry doesn't exists
       */
      echo "<strong>Error : </strong>Can\'t Fetch Data";
    }
    $connection->close();   // closing mysql connection
  }
  else
  {
    /*
     * connection to db is not Established
     */
    echo "<strong>Error : </strong>Can\'t Establish DB Connection";
  }
}
?>
