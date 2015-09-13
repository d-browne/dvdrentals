<?php
    // Function to add movie to database
    function addMovieToDatabase($dataConnection, $movieData)
    {
        $title = mysqli_real_escape_string($dataConnection, $movieData['movie_title']);
        $year = mysqli_real_escape_string($dataConnection, $movieData['movie_year']);
        $tagline = mysqli_real_escape_string($dataConnection, $movieData['movie_tagline']);
        $plot = mysqli_real_escape_string($dataConnection, $movieData['movie_plot']);
        $poster = $_FILES['movie_poster'];
        $director = mysqli_real_escape_string($dataConnection, $movieData['director_name']);
        $new_director = mysqli_real_escape_string($dataConnection, $movieData['new_director']);
        
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
        
        // Check if valid tagline is working
        if (isValidTagline($tagline))
        {
            echo '<div id="resultsTag">tagline valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">tagline invalid</div>';
        }
        
        // Check if plot is valid
        if (isValidPlot($plot))
        {
            echo '<div id="resultsTag">Plot valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Plot invalid</div>';
        }
        
        // Test to check if valid image check working
        if (isValidPoster($poster))
        {
            echo '<div id="resultsTag">Image valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Image Invalid</div>';
        }
        
        // Test to check if valid director selected
        if (isValidDirector($director))
        {
            echo '<div id="resultsTag">Director valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Director invalid</div>';
        }
        
        // Test to check if new_director test is working
        if (isValidNewDirector($new_director))
        {
            echo '<div id="resultsTag">New Director valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">New Director Invalid</div>';
        }
        
    }
    
    // Function to check if new director is valid
    // Must not be blank
    // Must not exist in database
    function isValidNewDirector($new_director)
    {
        if(empty($new_director))
        {
            return false; // Invalid, must enter data
        }
        
        // Connect to database
        include 'connect_to_database.inc';
        
        // query databse for director
        $query = "SELECT director_name FROM director WHERE director_name = '".$new_director."'";
        $result = $dataConnection->query($query);
        
        // If there are any results return false
        if ($result->num_rows > 0)
        {
            return false;
        }
        
        return true; // valid director
    }
    
    // Function to check if selected director is valid
    // must exist in databate
    function isValidDirector($director)
    {
        // Connect to database 
        include 'connect_to_database.inc';
        
        // Query database for selected director
        $query = "SELECT director_name FROM director WHERE director_name = '".$director."'";
        $result = $dataConnection->query($query);
        
        // Check if there is a result
        if ($result->num_rows > 0)
        {
            return true; // director in database
        }
        
        // Director not in database return false
        return false;
    }
    
    // Check if file is valid
    // Must have no errors, be a valid image type and under 2 mb
    function isValidPoster($poster)
    {
        // Check if uploaded file has any errors
        if ($poster['error'])
        {
            return false; // Invalid
        }
        
        // Check if image over 2mb
        if ($poster['size'] > 2000000)
        {
            return false; // Invalid, file too large
        }
        
        // Check image type is image
        $validTypes = array(IMAGETYPE_GIF, IMAGETYPE_JPEG, IMAGETYPE_PNG, IMAGETYPE_BMP);
        
        // Store image size in variable
        $imageSize = getimagesize($poster['tmp_name']);
        
        // Check if filetype NOT in array
        if (!in_array($imageSize[2], $validTypes))
        {
            return false; // Invalid file (wrong filetype)
        }
        
        return true; // Valid type
    }
    
    // Function to check of plot is valid
    // Must not be blank and must not exist in database
    function isValidPlot($plot)
    {
        // Check if empty
        if (empty($plot))
        {
            return false;
        }
        
        // Check if  plot in database
        include 'connect_to_database.inc'; // Connect to database
        
        // Query to see if plot in database
        $query = "SELECT plot FROM movie WHERE plot = '".$plot."'";
        $result = $dataConnection->query($query);  
        
        // If result returned then the plot already exists in database so return false
        if ($result->num_rows > 0)
        {
            return false;
        }
        
        return true; // Valid plot
    }
    
    // Function to check tagline
    // Must not be blank and must not exist in database
    function isValidTagline($tagline)
    {
        // check blank
        if (empty($tagline))
        {
            return false;
        }
        
        // Check if in database
        include 'connect_to_database.inc'; // Connect to database
        
        // Query to see if tagline in database
        $query = "SELECT tagline FROM movie WHERE tagline = '".$tagline."'";
        $result = $dataConnection->query($query);  
        
        // If result returned then the tagline already exists in database so return false
        if ($result->num_rows > 0)
        {
            return false;
        }
        
        return true; // Valid tagline
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