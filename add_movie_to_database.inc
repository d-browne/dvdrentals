<?php
    // Function to add movie to database
    function addMovieToDatabase($dataConnection, $movieData)
    {
        $title = mysqli_real_escape_string($dataConnection, $movieData['movie_title']);
        $year = mysqli_real_escape_string($dataConnection, $movieData['movie_year']);
        
        // Check valid title is working
        if (isValidTitle($title))
        {
            echo '<div id="resultsTag">Title valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Title invalid</div>';
        }
        
        // Check if valid year is working
        if (isValidYear($year))
        {
            echo '<div id="resultsTag">Year valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Year invalid</div>';
        }
        
        
        
    }
    
    // Function to validate title
    // Must not be blank but may already exist in db
    function isValidTitle($title)
    {
        if (!empty($title))
        {
            // is valid
            return true;
        }
        return false; // invalid
    }
    
    // Function to check year
    // must be 4 digits
    function isValidYear($year)
    {
        // Regex pattern
        $pattern = '/\d{4}/';
        
        // Check if year matches pattern
        if (preg_match($pattern, $year))
        {
            return true; // Is valid
        }
        return false; // is invalid
    }
?>