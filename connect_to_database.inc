<?php
    // This php include is the code to connect to the database
    
    // Include database settings
    include 'database_settings.inc';    // Edit database_settings.inc to change database settings
    
    // Connect to database
    $dataConnection = new mysqli($servername, $username, $password, $databaseName);
    
    // Check if connection successful and stop execution if not.
    if ($dataConnection->connect_error) {
        die("Error connecting to database: " . $dataConnection->connect_error);
    }
?>