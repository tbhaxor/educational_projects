<!--
  THE MAIN INDEX FILE
  LOGIN PORTAL FOR THE MANAGER
-->
<html>
<head>
<title>Student Management Program</title>
<!--IMPORT STYLESHEET AND SCRIPT-->
<link rel="stylesheet" href="assets/css/bootstrap.min.css">
<link rel="stylesheet" href="assets/css/master.css">
<script type="text/javascript" src="assets/js/bootstrap.min.js"></script>

<!--PHP BACKEND and FrontEnd-->
<?php
session_start();   // starting the server session
if(isset($_POST['login']))   // checking if user wants to login ?
{
  include_once 'dbconnection.php';  // including db connection file
  if($connection)   // checking whether the client - server dbconnection is established or not
  {
    /*
     * Now here client is connected with data base
     */
    $name = $_POST['inuser'];  // getting username entered by the user
    $pass = $_POST['inpass'];  // getting userpass entered by the user
    $sql = "SELECT * FROM `stumanage_users` WHERE name='$name' and passwd='$pass'";  // sql query
    $result = @mysqli_query($connection,$sql);   // running sql query on connection
    if($result)  // checking whether the query executed or not
    {
      /*
       * query executed successfully
       */
      $row  = @mysqli_fetch_assoc($result);  // fetching the tuples from the query
      if($row)   // checking whether entered username and password exists or not
      {
        /*
         * user exists
         */
        $_SESSION['slogin'] = true; // setting session
        $_SESSION['suser'] = $name;  // setting username
      }
      else
      {
        /*
         * this says user does not exists
         */
        echo "<script>alert('Error : User $name is not registered');</script>";
      }
    }

    else
    {
      /*
       * Now here client is connected with data base
       */
      echo "<script>alert('Error : Can\'t Run Query');</script>";
    }

    mysqli_close($connection); // closing the mysql connection
  }
  else
  {
    /*
     * connection to data base was not established
     */
    echo "<script>alert('Error : Can\'t Establish DB Connection');</script>";
  }
}
if(isset($_POST['signup'])) // checking whether user wants to be added
{
  /*
   * connection to data base was not so
   */
  include_once 'dbconnection.php'; // including dbconnection, trying to establish the connection
  if($connection)  // checking whether client server database connection is established
  {
    /*
     * connection to database is established
     */
    $name = $_POST['upuser'];  // getting username from user
    $pass = $_POST['uppass']; // getting password from user

    // applied security patch to prevent from XSS
    $name = str_replace("<","&lt;",$name);
    $name = str_replace(">","&gt;",$name);
    $pass = str_replace(">","&gt;",$pass);
    $pass = str_replace("<","&lt;",$pass);

    $sql = "INSERT INTO `stumanage_users`(`name`, `passwd`) VALUES ('$name','$pass')"; // sql query
    $result = @mysqli_query($connection,$sql);  // running sql query on connection
    if($result)  // checks whether query successfully executed or not
    {
      /*
       * data successfully inserted
       */
        echo "<script>alert('Error : User $name is registered');</script>";
    }
    else
    {
      /*
       * error while running the sql Query
       */
      echo "<script>alert('Error : Can\'t Run Query');</script>";
    }

    mysqli_close($connection); // closing mysql connection
  }
  else
  {
    /*
     * connection to data base was not established
     */
    echo "<script>alert('Error : Can\'t Establish DB Connection');</script>";
  }
}
// checking if session for slogin is not set then shows the login - sign up portal
if(!isset($_SESSION['slogin']))
{
  index();
}
// will redirect to dashboard if session for signin exists
else
{
  panel();
}
/*
 *  function to redirect to dashboard if user is signed or already signed in
 */
function panel()
{
  header("location:manager/dashboard.php"); // header function is used to in
}

/*
 *  function to view login / signup portal
 */
function index()
{
  // including all the variables for info.php
  include_once 'info.php';

  // printing the front end
  echo "<center><div class='container margin-bottom-20 jumbotron header'><h2 class=top>Project Name : ".@$project."<br>Coded By : ".@$coder."<br>Submitted To :".@$submited_to."</h1></div>";
  echo "<form method=post action='' class=form-horizontal>
  <div class=container>
  <div class=col-md-6><h3 class='underline bold'>Sign in Form</h3><div class=form-group><input type=text name=inuser placeholder='enter username' class='form-control index-ip '></div><div class=form-group><input type=password name=inpass placeholder='enter password' size=10 class='form-control index-ip'></div><div class=form-group><button type=submit name=login class='btn btn-info'><i class='glyphicon glyphicon-log-in'></i> Sign In</button></div></div>
  <div class=col-md-6><h3 class='underline bold'>Sign up Form</h3><div class=form-group><input type=text name=upuser placeholder='enter username' class='form-control index-ip '></div><div class=form-group><input type=password name=uppass placeholder='enter password' size=10 class='form-control index-ip'></div><div class=form-group><button type=submit name=signup class='btn btn-warning'>Sign Up</button></div></div>
  </form></center>
  ";
}
?>
