<html>
<head>
<title>Student Management Program</title>
<script type="text/javascript">
  getElementById('id')
  innerHTML
</script>
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
if(isset($_POST['update']))
{
  echo "<script>var a = document.getElementById('update'); a.innerHTML = 'LOLWA';</script>";
}
else
{
  if($connection)
  {
    $sql = "SELECT * FROM `stumanage_students` WHERE `sno`=$id";
    if($result = mysqli_query($connection,$sql))
    {
      $row = mysqli_fetch_assoc($result);
      echo "<center><h1>Viewing Details For $row[roll_no]</h1></center><br><br><br>";
      echo "<form action='' method=post class=form-horizontal><div class=container>";
      echo "<div class=form-group><div class=col-xs-3><strong>Roll Number</strong></div><div class=col-xs-4><input type=text name='rollno' value=$row[roll_no] class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Student's Name</strong></div><div class=col-xs-4><input type=text name='name' value=$row[name] class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Date of Birth</strong></div><div class=col-xs-4><input type=date name='dob' value=$row[dob] class=form-control></div><div class=col-xs-4 style=font-family:monospace;margin-top:7px;><i>Format used -> DD/MM/YYY</i></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Email Address</strong></div><div class=col-xs-4><input type=text name='email' value=$row[email] class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Student't Contact Number</strong></div><div class=col-xs-4><input type=text name='cnum' value=$row[contact_number] class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Father's Name</strong></div><div class=col-xs-4><input type=text name='fname' value=$row[father_name] class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Father's Contact Number</strong></div><div class=col-xs-4><input type=text name='fcnum' value=$row[father_c_number] class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Mother's Name</strong></div><div class=col-xs-4><input type=text name='mname' value=$row[mother_name] class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Mother's Contact Number</strong></div><div class=col-xs-4><input type=text name='mname' value=$row[mother_c_number] class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Address</strong></div><div class=col-xs-4><input type=text name='addr' value=$row[address] class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>Nationality</strong></div><div class=col-xs-4><input type=text name='nationality' value=$row[nationality] class=form-control></div></div>";
      echo "<div class=form-group><div class=col-xs-3><strong>How $row[name] is performing?</strong></div><div class=col-xs-4><input type=text name='nationality' value=$row[remarks] class=form-control></div></div>";
      echo "<center><button id='update' class='btn btn-warning btn-lg' style='width:50%'><i class='glyphicon glyphicon-pencil'></i> Update</button></center>";
      echo "</div></form>";
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
}
?>
