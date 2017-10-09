<?php session_start(); if(!isset($_GET['do'])) {header("location:?do=home");}?>
<!DOCTYPE html>
<html>
  <head>
    <link rel="stylesheet" href="style.css">
    <meta charset="utf-8">
    <title>PHP File Manager</title>
  </head>
  <body>
    <header>
      <?php include_once 'config.php';
      echo "Project - PHP File Manager<br>";
      echo "Coded By - $coder<br>";
      echo "Submitted to - $submitted_to<br>";
      echo "Institution - $institution<br>";
      ?>
    </header>
<?php
if(!isset($_SESSION['flogin']))
{
  main($password);
}
else
{
  manager();
}
function actors()
{
  echo "<hr><center><div id=actors-band>";
  echo "&nbsp;&nbsp;&nbsp;&nbsp;[ <a href='?do=home' id=actors>Home</a> ]&nbsp;&nbsp;&nbsp;&nbsp;";
  echo "[ <a href='?do=upload' id=actors>Upload</a> ]&nbsp;&nbsp;&nbsp;&nbsp;";
  echo "[ <a href='?do=logout' id=actors>Logout</a> ]&nbsp;&nbsp;&nbsp;&nbsp;";
  echo "</div></center><hr>";
}
function manager()
{
  actors();
  switch ($_GET['do']) {
    case 'upload':
      uploader();
      break;
      case 'logout':
        logout();
        break;

  }
}
function uploader()
{
  echo "<center><div id=uploader-band>";
  echo "</div></center>";
}
function logout()
{
  session_unset();
  session_destroy();

}

function main($password)
{

  echo "<form action='' method=post><center><input id=login type=password name=pwd autofocus><br><span id=login-msg>Enter Password and Press Enter</span></center></form>";
  if(isset($_POST['pwd']) and @$_POST['pwd']==$password)
  {
    $_SESSION['flogin'] = "set";
    header("location:?do=home");
  }
}
?>
  </body>
</html>
