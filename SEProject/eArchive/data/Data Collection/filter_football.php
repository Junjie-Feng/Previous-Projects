<?php

$con = mysqli_connect("localhost", "root", "root", "hma2014");
//mysqli_query($con, "DELETE FROM tweets_new");

echo "Start<br>";

$Key_Word = "volleyball";

$sql = "SELECT * FROM tweets WHERE tweet_text LIKE
'%".$Key_Word."%' ";//AND tweet_text LIKE '%min%'
//";
//$sql1 = "SELECT tweet_text FROM tweets";

$result = mysqli_query($con, $sql);

if (!$result) { // add this check.
    die('Invalid query: ' . mysql_error());
}


//echo "hahaha";
while($array = mysqli_fetch_array($result)){
	echo "tweet id:".$array[0];
	echo "<br>";
	echo "tweet text:".$array[1];
	echo "<br>";
	echo "=======================<br>";
}

mysqli_close($con);
echo "END<br>";
?>