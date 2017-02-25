<?php
$q = $_REQUEST["q"]; // get the q parameter from URL
$fp = fopen("/dev/ttyUSB0", "r+");
fwrite($fp, $q); // Output q parameter to com4 serial port
fclose($fp);
?>