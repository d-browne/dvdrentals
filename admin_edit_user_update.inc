<?php
// Check to make sure entered data is valid
include 'validateUser.php';
if (ValidateUserForm($_POST)) 
{
    // Set member values
    $surname = mysqli_real_escape_string($dataConnection, $_POST['surname']);
    $othername = mysqli_real_escape_string($dataConnection, $_POST['othername']);
    $username = mysqli_real_escape_string($dataConnection, $_POST['joinusername']);
    $password = mysqli_real_escape_string($dataConnection, $_POST['userpass']);
    $occupation = mysqli_real_escape_string($dataConnection, $_POST['occupation']);
    $contactmethod = mysqli_real_escape_string($dataConnection, $_POST['contactmethod']);
    $email = mysqli_real_escape_string($dataConnection, $_POST['email']);
    $landline = mysqli_real_escape_string($dataConnection, $_POST['phonenum']);
    $mobile = mysqli_real_escape_string($dataConnection, $_POST['mobilenum']);
    $streetaddr = mysqli_real_escape_string($dataConnection, $_POST['streetaddr']);
    $suburbstate = mysqli_real_escape_string($dataConnection, $_POST['suburbstate']);
    $postcode = mysqli_real_escape_string($dataConnection, $_POST['postcode']);
    
    // Set magazine value
    if (isset($_POST['magazine']))
    {
        $magazine = 1;
    }
    else
    {
        $magazine = 0;
    }
    
    // Create query to update member details
    $query =    "UPDATE member SET surname='".$surname."', 
                other_name='".$othername."', 
                contact_method='".$contactmethod."', 
                email='".$email."', 
                mobile='".$mobile."', 
                landline='".$landline."', 
                magazine=".(int)$magazine.", 
                street='".$streetaddr."', 
                suburb='".$suburbstate."', 
                postcode='".$postcode."', 
                password='".$password."', 
                occupation='".$occupation."'
                WHERE username='".$username."'";
    
    // Execute query
    $dataConnection->query($query);
    
    // Show updated user message
    echo '<div id="resultsTag">Updated user "'.$username.'"!</div>';
}

?>