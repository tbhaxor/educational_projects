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
session_start();  // starting the server session
if(isset($_POST['login']))  // checking if user wants to login ?
{
  include_once 'dbconnection.php'; // including db connection file
  if($connection) // checking whether the client - server dbconnection is established or not
  {
    /*
     * Now here client is connected with data base
     */
      $name = $_POST['inuser'];  // getting username entered by the user
      $pass = $_POST['inpass'];  // getting userpass entered by the user
      $sql = "SELECT * FROM `stumanage_users` WHERE name='$name' and passwd='$pass'"; // sql query
      $statement = $connection->prepare($sql);  // preparing sql sql query and making its object
      $statement->execute(); // executing the query
      $statement->setFetchMode(PDO::FETCH_ASSOC);   // setting fetch type
      $result = $statement->fetchall();  // fetching all data at once
      if(count($result)==0) // checking if user exists or not
      {
        /*
         * user not exists
         */
        echo "<script>alert('Error : Username / Password is incorrcect');</script>";
      }
      else
      {
        /*
         * user exists
         */
        $result = $result[0];
        $_SESSION['slogin'] = true; // setting session
        $_SESSION['suser'] = $name;  // setting username
      }
    $connection = null;  // closing mysql connection
  }
  else
  {
    /*
     * Now here client is connected with data base
     */
    echo "<script>alert('Error : Can\'t Establish DB Connection');</script>";
  }
}
if(isset($_POST['signup']))  // checking whether user wants to be added
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
    try   // trying to add data
    {
      $name = $_POST['upuser'];  // getting username from user
      $pass = $_POST['uppass']; // getting password from user

      // applied security patch to prevent from XSS
      $name = str_replace("<","&lt;",$name);
      $name = str_replace(">","&gt;",$name);
      $pass = str_replace("<","&lt;",$pass);
      $pass = str_replace(">","&gt;",$pass);

      $sql = "INSERT INTO `stumanage_users`(`name`, `passwd`) VALUES ('$name','$pass')"; // sql query
      $connection->beginTransaction();  // beginning the sql transaction
      $statement = $connection->prepare($sql);  // preparing sql statement
      $statement->execute();  // executing the prepared statement
      $connection->commit();  // commit the changes mage on connection
      echo "<script>alert('Error : User $name is registered');</script>";
    }
    catch (PDOException $e)  // catching a PDOException
    {
      /*
       * if data is not commited
       */
      $connection->rollback();  // on error rolling back the actions
      echo "<script>alert('Error : Can\'t Run Query');</script>";
    }
    $connection = null; // closing mysql connection
  }
  else
  {
    /*
     * error while connection to data base
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
function index()
{
  // including all the variables for info.php
  include_once 'info.php';
  
  echo "<center><div class='container margin-bottom-20 jumbotron header'><h2 class=top>Project Name : ".@$project."<br>Coded By : ".@$coder."<br>Submitted To :".@$submited_to."</h1></div>";
  echo "<form method=post action='' class=form-horizontal>
  <div class=container>
  <div class=col-md-6><h3 class='underline bold'>Sign in Form</h3><div class=form-group><input type=text name=inuser placeholder='enter username' class='form-control index-ip '></div><div class=form-group><input type=password name=inpass placeholder='enter password' size=10 class='form-control index-ip'></div><div class=form-group><button type=submit name=login class='btn btn-info'><i class='glyphicon glyphicon-log-in'></i> Sign In</button></div></div>
  <div class=col-md-6><h3 class='underline bold'>Sign up Form</h3><div class=form-group><input type=text name=upuser placeholder='enter username' class='form-control index-ip '></div><div class=form-group><input type=password name=uppass placeholder='enter password' size=10 class='form-control index-ip'></div><div class=form-group><button type=submit name=signup class='btn btn-warning'>Sign Up</button></div></div>
  </form></center>
  ";
}
?>
