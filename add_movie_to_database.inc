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
        $studio = mysqli_real_escape_string($dataConnection, $movieData['studio_name']);
        $new_studio = mysqli_real_escape_string($dataConnection, $movieData['new_studio']);
        $genre = mysqli_real_escape_string($dataConnection, $movieData['genre_name']);
        $new_genre = mysqli_real_escape_string($dataConnection, $movieData['new_genre']);
        $classification = mysqli_real_escape_string($dataConnection, $movieData['classification_name']);
        $new_classification = mysqli_real_escape_string($dataConnection, $movieData['new_classification']);
        $first_star = mysqli_real_escape_string($dataConnection, $movieData['first_star_name']);
        $new_first_star = mysqli_real_escape_string($dataConnection, $movieData['new_first_star']);
        $rental_period = mysqli_real_escape_string($dataConnection, $movieData['rental_period']);
        $dvd_rental_price = mysqli_real_escape_string($dataConnection, $movieData['dvd_rental_price']);
        $dvd_purchase_price = mysqli_real_escape_string($dataConnection, $movieData['dvd_purchase_price']);
        $numDVD = mysqli_real_escape_string($dataConnection, $movieData['numDVD']);
        $numDVDout = mysqli_real_escape_string($dataConnection, $movieData['numDVDout']);
        $bluray_rental_price = mysqli_real_escape_string($dataConnection, $movieData['bluray_rental_price']);
        $bluray_purchase_price = mysqli_real_escape_string($dataConnection, $movieData['bluray_purchase_price']);
        $numBluRay = mysqli_real_escape_string($dataConnection, $movieData['numBluRay']);
        $numBluRayOut = mysqli_real_escape_string($dataConnection, $movieData['numBluRayOut']);
        
        // Variable to make sure all required checks working
        $all_ok = true;
        
        // Check title
        if (isValidTitle($title))
        {
            //echo '<div id="resultsTag">Title valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid title - Must not be blank</div>';
            $all_ok = false;
        }
        
        // Check year
        if (isValidYear($year))
        {
            //echo '<div id="resultsTag">Year valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid Year must be 4 digits</div>';
            $all_ok = false;
        }
        
        // Check tagline
        if (isValidTagline($tagline))
        {
            //echo '<div id="resultsTag">tagline valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid tagline - must be unique and not blank</div>';
            $all_ok = false;
        }
        
        // Check plot
        if (isValidPlot($plot))
        {
            //echo '<div id="resultsTag">Plot valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid plot - must not be blank and must be unique</div>';
            $all_ok = false;
        }
        
        // Check image
        if (isValidPoster($poster))
        {
            //echo '<div id="resultsTag">Image valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid image - Must be an image format and under 2MB</div>';
            $all_ok = false;
        }
        
        // Check Director
        if (isValidDirector($director) || isValidNewDirector($new_director))
        {
            //echo '<div id="resultsTag">Director valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid director - You must select an existing director or specify a new one</div>';
            $all_ok = false;
        }
        
        
        // Check studio
        if (isValidStudio($studio) || isValidNewStudio($new_studio))
        {
            //echo '<div id="resultsTag">Valid studio</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid studio - Must specify a studio or specify a new one</div>';
            $all_ok = false;
        }
        
        // Check if valid genre
        if (isValidGenre($genre) || isValidNewGenre($new_genre))
        {
            //echo '<div id="resultsTag">Valid genre</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid Genre - select a genre or speicfy a new one</div>';
            $all_ok = false;
        }

        // Test if selected classification is valid
        if (isValidClassification($classification) || isValidNewClassification($new_classification))
        {
            //echo '<div id="resultsTag">Classification is valid</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid classification - select a classification or specify a new one</div>';
            $all_ok = false;
        }
        
        
        // Test to see if selected first star is a valid actor
//        if (isValidActor($first_star))
//        {
//            echo '<div id="resultsTag">selected first star is a valid actor</div>';
//        }
//        else
//        {
//            echo '<div id="resultsTag">selected first star is NOT a valid actor</div>';
//        }
//        
//        // Test to see if new first star is valid
//        if (isValidNewActor($new_first_star))
//        {
//            echo '<div id="resultsTag">New First start is valid!</div>';
//        }
//        else
//        {
//            echo '<div id="resultsTag">New First start is invalid!</div>';
//        }
        
        // Test if Rental period is an allowed value
        if (isValidRentalPeriod($rental_period))
        {
            //echo '<div id="resultsTag">Rental period is valid!</div>';
        }
        else
        {
            echo '<div id="resultsTag">Rental period is invalid!</div>';
            $all_ok = false;
        }
        
        // Check if valid dvd rental price
        if (isValidPrice($dvd_rental_price))
        {
            //echo '<div id="resultsTag">Valid DVD rental price</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid DVD rental price - must be a number</div>';
            $all_ok = false;
        }
        
        // Check purchase price
        if (isValidPrice($dvd_purchase_price))
        {
            
        }
        else 
        {
            echo '<div id="resultsTag">Invalid DVD purchase price - must be a number</div>';
            $all_ok = false;
        }
        
        // Check if valid dvd in stock quantity
        if (isValidStockQuantity($numDVD))
        {
            //echo '<div id="resultsTag">Valid DVD quantity!</div>';
        }
        else
        {
            echo '<div id="resultsTag">Invalid DVD in stock quantity - must be a number</div>';
            $all_ok = false;
        }
        
        // check dvd rented out quantity
        if (isValidStockQuantity($numDVDout))
        {
            
        }
        else
        {
            echo '<div id="resultsTag">Invalid out of stock DVD quantity - must be a number</div>';
            $all_ok = false;
        }
        
        // Check BluRay rental price
        if (isValidPrice($bluray_rental_price))
        {
            
        }
        else
        {
            echo '<div id="resultsTag">Invalid BluRay rental price - must be a number</div>';
            $all_ok = false;
        }
        
        // Check BluRay purchase price
        if (isValidPrice($bluray_purchase_price))
        {
            
        }
        else
        {
            echo '<div id="resultsTag">Invalid BluRay purchase price - must be a number</div>';
            $all_ok = false;
        }
        
        // Check BluRay in stock
        if (isValidStockQuantity($numBluRay))
        {
            
        }
        else
        {
            echo '<div id="resultsTag">Invalid BluRay in stock quantity - must be a number</div>';
            $all_ok = false;
        }
        
        // Check BluRay out stock 
        if (isValidStockQuantity($numBluRayOut))
        {
            
        }
        else
        {
            echo '<div id="resultsTag">Invalid BluRay in out of stock quantity - must be a number</div>';
            $all_ok = false;
        }
      
        var_dump($all_ok);
    }
    
    // Function to check if all the required values are valid
    function isAllRequiredValesValid($movieData)
    {
        
    }
    
    // Function to check if valid stock quantity
    // must be a number
    function isValidStockQuantity($quantity)
    {
        // Return true if value integer
        if (is_numeric($quantity))
        {
            return true;
        }
        // Not integer return false
        return false;
    }
    
    // Function to check if valid price
    // must be a number
    function isValidPrice($price) 
    {
        // return true if valid floating point number
        if (is_numeric($price))
        {
            return true;
        }
        
        // Not a valid float, return false
        return false;
    }
    
    // Function to check if valid rental period
    // Must be '3 Day', 'Weekly' or 'Overnight'
    function isValidRentalPeriod($rental_period)
    {
        $allowed_values = array('3 Day', 'Weekly', 'Overnight');
        
        // Check if rental period is an allowed value
        $isValid = in_array($rental_period, $allowed_values);
        if ($isValid)
        {
            return true;
        }
        
        return false; // Rental period not allowed
    }
    
    // Function to check if new actor is valid
    // must not be blank
    // not NOT exist in database
    function isValidNewActor($new_actor)
    {
        // Return false if blank
        if (empty($new_actor)) 
        {
            return false;
        }
        
        // connect to database
        include 'connect_to_database.inc';
        $query = "SELECT actor_name FROM actor WHERE actor_name = '".$new_actor."'";
        $result = $dataConnection->query($query);
        
        // Retrun false if actor already exists in database
        if ($result->num_rows > 0)
        {
            return false;
        }
        
        return true; // Valid new actor
    }
    
    // function to check if selected actor is valid
    // must exist in database
    function isValidActor($actor)
    {
        // Connect to database
        include 'connect_to_database.inc';
        
        // Query to check if actor is in database
        $query = "SELECT actor_name FROM actor WHERE actor_name = '".$actor."'";
        $result = $dataConnection->query($query);
        
        // Return true if actor is in database
        if ($result->num_rows > 0)
        {
            return true;
        }
        
        return false; // Actor not in database
        
    }
    
    // Function to check if new classification is valid
    // Must not be blank
    // must NOT exist in database
    function isValidNewClassification($new_classification)
    {
        // Check if new classification is blank
        if (empty($new_classification))
        {
            return false;
        }
        
        // Connect to database
        include 'connect_to_database.inc';
        
        // Query for new classification
        $query = "SELECT classification FROM movie WHERE classification = '".$new_classification."'";
        $result = $dataConnection->query($query);
        
        // If classification exists in database return false
        if ($result->num_rows > 0)
        {
            return false;
        }
        
        return true; // Valid new classification
    }
    
    // Function to check if selected classification is valid
    // Must exist in database
    function isValidClassification($classification)
    {
        // Connect to database
        include 'connect_to_database.inc';
        
        // Query for classifications
        $query = "SELECT classification FROM movie WHERE classification = '".$classification."'";
        $result = $dataConnection->query($query);
        
        // If classification in database return true
        if ($result->num_rows > 0)
        {
            return true;
        }
        
        return false; // Classification not in database, return false.
    }
    
    // Function to check if new_genre is valid
    // Must not be blank
    // must NOT exist in database
    function isValidNewGenre($new_genre)
    {
        if (empty($new_genre))
        {
            return false; // Is empty
        }
        
        // Connect to database
        include 'connect_to_database.inc';
        
        // Query to find typed genre
        $query = "SELECT genre_name FROM genre WHERE genre_name = '".$new_genre."'";
        $result = $dataConnection->query($query);
        
        // If genre in database return false
        if ($result->num_rows > 0)
        {
            return false;
        }
        
        return true; // Valid new genre
    }
    
    // Function to check if valid genre selected
    // Must exist in database
    function isValidGenre($genre) 
    {
        // Connect to database
        include 'connect_to_database.inc';
        
        // Query database for selected genre
        $query = "SELECT genre_name FROM genre WHERE genre_name = '".$genre."'";
        $result = $dataConnection->query($query);
        
        // if genre exists in database return true
        if ($result->num_rows > 0)
        {
            return true;
        }
        return false; // Genre not in database
    }
    
    // Function to check if new studio is valid
    // Must not be blank
    // Must NOT exist in database
    function isValidNewStudio($new_studio)
    {
        if (empty($new_studio))
        {
            return false; // Input is blank
        }
        
        // Connect to database
        include 'connect_to_database.inc';
        
        // Query database for studio
        $query = "SELECT studio_name FROM studio WHERE studio_name = '".$new_studio."'";
        $result = $dataConnection->query($query);
        
        // If studio exists in database return false
        if ($result->num_rows > 0)
        {
            return false;
        }
        
        return true; // New studio is valid
    }
    
    // Function to check if studio is valid
    // Must not be blank
    // Must exist in database
    function isValidStudio($studio)
    {
        // Return false if empty
        if (empty($studio))
        {
            return false;
        }
        
        // Connect to database
        include 'connect_to_database.inc';
        
        // Query database for selected stuido
        $query = "SELECT studio_name FROM studio WHERE studio_name = '".$studio."'";
        $result = $dataConnection->query($query);
        
        // If studio in database return true
        if ($result->num_rows > 0)
        {
            return true;
        }
        
        // Studio not found in database return false
        return false;
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