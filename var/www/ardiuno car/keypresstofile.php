<?php
// get the q parameter from URL
$q = $_REQUEST["q"];

// Output q parameter to file
$fp = fopen("somecrap.txt", "w");
fwrite($fp, $q);
fclose($fp);
?>