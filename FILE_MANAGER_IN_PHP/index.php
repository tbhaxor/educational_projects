<?php session_start(); error_reporting(0); if(!isset($_GET['do'])) {header("location:?do=home");}?>
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
  echo "[ <a href='?do=newfile' id=actors>New File</a> ]&nbsp;&nbsp;&nbsp;&nbsp;";
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
      case 'home':
        home();
        break;
      case 'newfile':
        newfile();
        break;
      case 'del':
        if(isset($_GET['dir']))
          rmdir(base64_decode($_GET['dir']));
        echo "<script>window.location = '?do=home';</script>";
        break;
  }
}

function newfile()
{
  echo "<center><div><form action='' method=post id=nf>File Will Be Saved in - <i><b>".getcwd()."</b></i><br><br>File name : <input id=l1 placeholder=file.txt autofocus name=fname><br><br><span style='vertical-align:top;'>File Contents : </span><textarea name=fdata id=l2 rows=5 cols=40></textarea><br><br><input type=submit value='Make File' name=make></form></div></center>";
  if(isset($_POST['make']))
  {
    $file = fopen(getcwd() . "/" .$_POST['fname'],"w");
    $data = $_POST['fdata'];
    fwrite($file,$data);
    fclose($file);
    echo "<script>window.location = '?do=home';</script>";
  }
}

function home()
{
  $cwd = getcwd();
  if(isset($_POST['GO']))
  {
    $cwd = $_POST['cwd'];
    chdir($cwd);
  }
  echo "<center><div id=pwd><form method=post action=''>Present Working Directory : <input id=PWD name=cwd size=80 value='$cwd'><input type=submit name=GO value=Go></form></div></center>";
  $files = scandir($cwd);
  echo "<center id=fn><table border=1><tr id=th><th>Name</th><th>Permissions</th><th>Action</th><tr>";
  foreach ($files as $file) {
    if($file[0]=="."){continue;}
    if(is_dir($file))
    {
      echo "<tr><td>[ $file ]</td><td>".fileperms($file)."</td><td><pre><a href='?do=dnf&dir=".base64_encode(realpath($file))."' id=hactor>{New File}</a> <a href='?do=dnf' id=hactor>{Open}</a> <a href='?do=del&dir=".base64_encode($cwd)."' id=hactor>{Delete}</a> <a href='?do=ren&dir=".$cwd."' id=hactor>{Rename}</a></pre></td></tr>";
    }
  }
  foreach ($files as $file) {
    if(!is_dir($file))
    {
      echo "<tr><td>$file</td><td>".fileperms($file)."</td><td>NEW FILE DELETE</td></tr>";
    }
  }
  $write = is_writable(getcwd()) ? "<p style=color:royalblue;>{ Writable }</p>" : "<p style=color:royalblue;>{ Non Writable }</p>";
  echo "</table><br>$write</center>";
}
function uploader()
{
  echo "<center><div id=uploader-band>";
  $cwd = getcwd();
  $isw = is_writable($cwd) ? "YES" : "NO";
  if(isset($_POST['upfile']))
  {
    if(isset($_FILES['image'])){
      $errors= array();
      $file_name = $_FILES['image']['name'];
      $file_size =$_FILES['image']['size'];
      $file_tmp =$_FILES['image']['tmp_name'];
      $file_type=$_FILES['image']['type'];
      $file_ext=strtolower(end(explode('.',$_FILES['image']['name'])));

      $expensions= array("jpeg","jpg","png");

      if(in_array($file_ext,$expensions)=== false){
         $errors[]="extension not allowed, please choose a JPEG or PNG file.";
      }

      if($file_size > 2097152){
         $errors[]='File size must be excately 2 MB';
      }

      if(empty($errors)==true){
         move_uploaded_file($file_tmp,"images/".$file_name);
         echo "Success";
      }else{
         print_r($errors);
      }
   }
  }
  echo "</div></center>";
}
function logout()
{
  session_unset();
  session_destroy();
  echo "<script>window.location = window.location;</script>";
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
