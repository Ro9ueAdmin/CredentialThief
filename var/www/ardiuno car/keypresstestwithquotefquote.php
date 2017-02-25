<?php
// $q = $_REQUEST["q"]; // get the q parameter from URL
$fp = fopen("/dev/ttyUSB0", "r+");
fwrite($fp, "f"); // Output "f" parameter to ttyUSB0 serial port
fclose($fp);
?>