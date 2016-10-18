<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>SignUp/LogIn</title>
<link href='http://fonts.googleapis.com/css?family=Oswald' rel='stylesheet' type='text/css'>
<link href='http://fonts.googleapis.com/css?family=Oswald|Pontano+Sans' rel='stylesheet' type='text/css'>
<link href="css/style.css" rel="stylesheet" type="text/css" />
</head>
<body>
<div class="header-wrap">
  <div class="header">
    <div class="menu">
      <ul>
        <li><a href="index.html">Home</a></li>
        <li><a href="personal.html" >Personal Info</a></li>
        <li><a href="services.html"  >Services</a></li>
        <li><a href="portfolio.html">Information</a></li>
        <li><a href="signup.html" class="active">SignUp/LogIn</a></li>
      </ul>
    </div>
    <div class="social-media">
      <ul>
        <li><a href="#"><img src="images/aim.gif" alt="aim" /></a></li>
        <li><a href="#"><img src="images/facebook.gif" alt="facebook" /></a></li>
        <li><a href="#"><img src="images/linkedin.gif" alt="linkedin" /></a></li>
        <li><a href="#"><img src="images/twitter.gif" alt="twitter" /></a></li>
      </ul>
    </div>
  </div>
</div>
<!-- end of header wrapper -->
<div class="logo-sarch-wrap">
  <div class="logo-search-container">
    <div class="logo">
      <h1>sign up/log in page</h1>
    </div>
    <div class="search">
      <div class="search-input">
        <input type="text" class="search-text-field" value="Search Here ..." />
      </div>
      <div class="search-button"><a href="#"><img src="images/serach-icon.gif" alt="search" /></a></div>
    </div>
  </div>
</div>
<!-- end of header wrapper -->
<!-- end of header wrapper -->
<div class="clearing"></div>
<div class="page-wrapper">
  <div class="generic-content">
    <div class="title">
      <h1>Hello!    </h1>
    </div>
    <div class="content">
      <p>Welcome!</p>
      
	  <?php
	  error_reporting(0);
	  echo '<p>Login In at ';
	  echo date_default_timezone_set("Asian/Shanghai");
	  echo date("Y-m-d",time())."<p>";
      echo date("H:i:s",time());
      echo '</p>';
      echo '<p>Your information is as follows: </p>';

      echo 'Full Name: '.$name.'<br />';
      echo 'Email: '.$email.'<br />';
      echo 'Birthday: '.$birthday.'<br />';
      echo 'Gender(M/W): '.$gender.'<br />';
?>
      <p>&nbsp; </p>
      <form>
      </form>
    </div>
  </div>
</div>
<!-- end of page wrapper -->
<div class="clearing"></div>
<div class="footer-wrapper marginTop">
  <div class="footer">Copyright (c) Health Monitor Group #1. All rights reserved. Designed by: Tianzhe Wang. Images From: Google</div>
</div>
</body>
</html>
