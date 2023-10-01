<?php
    // Get the text from the text area
    //$text = $_POST["textbox"];
	//$text = rtrim($_POST["textbox"]);
	$text = str_replace(array("\r\n", "\r", "\n"), "\n", $_POST["textbox"]);
	
	// Open or create the file.txt for writing
    $file = fopen("HexFile.hex", "w");
    
    if ($file) {
        fwrite($file, $text);
        fclose($file);
        
        echo "Hex file saved successfully!";
    } else {
        echo "Error opening the file.";
    }
?>