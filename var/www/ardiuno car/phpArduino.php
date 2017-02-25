<?php
function openSerial($command) {
	echo 'lkjhkljkjlhkljh ';
	$openSerialOK = false;


	try {
		exec("mode com4: BAUD=9600 PARITY=n DATA=8 STOP=1 to=off dtr=off rts=off");
		//$fp =fopen("com4", "w");
		$fp = fopen('/dev/ttyUSB0','w'); //use this for Linux
		$openSerialOK = true;
	} catch(Exception $e) {
		echo 'Message: ' .$e->getMessage();
	}

	if($openSerialOK) {
		fwrite($fp, $command); //write string to serial
		fclose($fp);
    }	
}

if(isset($_POST['submit1'])) {
    openSerial("f");
}

if(isset($_POST['submit2'])) {
    openSerial("g");
}

if(isset($_POST['submit3'])) {
    openSerial("r");
}

if(isset($_POST['submit4'])) {
    openSerial("s");
}

if(isset($_POST['submit5'])) {
    openSerial("b");
}

if(isset($_POST['submit6'])) {
    openSerial("c");
}

if(isset($_POST['submit7'])) {
    openSerial("l");
}

if(isset($_POST['submit8'])) {
    openSerial("m");
}

?>

<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">

<TABLE padding="20px">
<TR>
<TD></TD>
<TD><input type="submit" name="submit1" value="1 on"><input type="submit" name="submit2" value="1 off"></TD>
<TD></TD>
</TR> 
<TR>
<TD><input type="submit" name="submit3" value="2 on"><input type="submit" name="submit4" value="2 off"></TD> 
<TD><input type="submit" name="submit5" value="3 on"><input type="submit" name="submit6" value="3 off"></TD>
<TD><input type="submit" name="submit7" value="4 on"><input type="submit" name="submit8" value="4 off"></TD>
</TR>
</TABLE>
</form>

