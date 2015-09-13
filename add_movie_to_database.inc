<?php
    // Function to add movie to database
    function addMovieToDatabase($dataConnection, $movieData)
    {
        $title = mysqli_real_escape_string($dataConnection, $movieData['movie_title']);
        
        if (isValidTitle($title))
        {
            echo $title . ' is valid!';
        }
        else 
        {
            echo $title . ' is invalid!';
        }
    }
    
    // Function to validate title
    // Must not be blank but may already exist in db
    function isValidTitle($title)
    {
        if (empty($title))
        {
            // is valid
            return true;
        }
        return false; // invalid
    }
    
    // Function to check year
    
?>