<!--
Addnew Entry form
-->
<html>
<head>
<title>Student Management Program</title>
<!--IMPORT STYLESHEET AND SCRIPT-->
<link rel="stylesheet" href="../assets/css/bootstrap.min.css">
<link rel="stylesheet" href="../assets/css/master.css">
<script type="text/javascript" src="../assets/js/bootstrap.min.js"></script>

<!--PHP BACKEND AND FRONTEND-->
<?php
include_once '../dbconnection.php'; // including dbconnection.php to Establish connection with the db
if(isset($_POST['enter']) and $connection)   // checking whether use wants to add new entry and also if db connection is Established or not
{
  /*
   * connection to db is Established and also user wants to enter new deatils
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

  // running query on the conneting and checking is executed or not
  if(mysqli_query($connection,"INSERT INTO `stumanage_students`(`roll_no`, `name`, `dob`, `father_name`, `mother_name`, `email`, `contact_number`, `father_c_number`, `mother_c_number`, `nationality`, `address`, `remarks`) VALUES ('$roll_no','$name','$dob','$fname','$mname','$email','$cnum','$fcnum','$mcnum','$nationality','$addr','$remarks')"))
  {
    /*
     * new entry added
     */
    echo "<script>alert('ERROR : Successfully Entered');window.location.href='dashboard.php';</script>"; // redirecting to dashboard
  }
  else
  {
    /*
     * new entry is not added
     */
    echo "<script>alert('ERROR : Not Insert');window.location.href='dashboard.php';</script>"; // redirecting to dashboard
  }
  mysqli_close($connection); // closing mysql connection
}
else
{
  if($connection) // checking if connection is set or not
  {
      /*
       * connection is Established
       */

      echo "<center><h1>Enter Detail For New Student</h1></center><br><br><br>";
      echo "<form action='' method=post class=form-horizontal><div class=container>";
      echo "<div class=form-group><div class=col-xs-3><strong>Roll Number</strong></div><div class=col-xs-4><input type=text name='rollno'class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Student's Name</strong></div><div class=col-xs-4><input type=text name='name' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Date of Birth</strong></div><div class=col-xs-4><input type=date name='dob' class=form-control></div><div class=col-xs-4 style=font-family:monospace;margin-top:7px;><i>Format used -> DD/MM/YYY</i></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Email Address</strong></div><div class=col-xs-4><input type=text name='email' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Student't Contact Number</strong></div><div class=col-xs-4><input type=text name='cnum' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Father's Name</strong></div><div class=col-xs-4><input type=text name='fname' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Father's Contact Number</strong></div><div class=col-xs-4><input type=text name='fcnum' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Mother's Name</strong></div><div class=col-xs-4><input type=text name='mname' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Mother's Contact Number</strong></div><div class=col-xs-4><input type=text name='mcnum' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Address</strong></div><div class=col-xs-4><input type=text name='addr' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Nationality</strong></div><div class=col-xs-4><input type=text name='nationality' class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Remarks</strong></div><div class=col-xs-4><input type=text name='remarks' class=form-control></div></div>";
      echo "<center><button name='enter' class='btn btn-success btn-lg' style='width:50%'><i class='glyphicon glyphicon-plus-sign'></i> Add New Student Entry</button></center>";
      echo "</div></form>";
    }
  else
  {
    // Connection not Established
    echo "<strong>Error : </strong>Can\'t Establish DB Connection";
  }
}
?>
