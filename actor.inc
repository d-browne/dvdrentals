<?php
    // This include performs the search by actor search

    // Include database settings
    include 'database_settings.inc';    // Edit database_settings.inc to change database settings

    // Connect to database
    $dataConnection = new mysqli($servername, $username, $password, $databaseName);
    
    // Check if connection successful and stop execution if not.
    if ($dataConnection->connect_error) {
        die("Error connecting to database: " . $dataConnection->connect_error);
    }
    
    
    // Get actors and id's and put them in array
        $actors = getActors($dataConnection);
        
        // Create form to submit actor name
        echo '<form action="moviezone.php?search" method="get">';
        echo '<input type="hidden" name="search" value="actor" />';
        // Create select box to hold actor names
        echo '<select name="actor_name">';
        echo '<option selected="" disabled="" value="">Select actor...</option>';
        // Loop through each actor in array and populate select box
        foreach ($actors as $id=>$name) {
            echo '<option value="'.$name.'">'.$name.'</option>';
        }
        echo '</select>'; // Closing tag for select box
        echo '<input type="submit" value="Search" />'; // Submit button for form
        echo '</form>'; // closing tag for form
    
   
    if (isset($_GET['actor_name']))  {
        // Show movies of selected actor
        showMoviesByActor($_GET['actor_name'], $dataConnection); // call function to show movies based on actor name
    } 
    
    // Function to return an array of actors
    function getActors($dataConnection) {
        $query = "SELECT * from actor ORDER BY actor_name";             // SQL query to get actors
        $result = $dataConnection->query($query);   // Result of query
        $actors = array();                               // Array to hold actors
        
        // If there are reslts
        if ($result->num_rows > 0) {
            // Loop through each row
            while ($row = $result->fetch_assoc()) {
                // Push row to array
                $actors[$row['actor_id']] = $row['actor_name'];
            }
        }
        
        return $actors;                             // Return array of actors
        
    }
    
    // Function to show movies based on actor name
    function showMoviesByActor($actor_name, $dataConnection) {
        // Query to find out what movies actor name in
        $query =    "SELECT movie_id FROM movie_actor_view
                     WHERE actor_name = '".$actor_name."'
                     ORDER BY actor_name";
        
        // run the query 
        $result = $dataConnection->query($query);
        
        // Check if there is a match
        if ($result->num_rows > 0) {
            // Print number of results
            echo '<div id="resultsTag">Showing '.$result->num_rows.' results for '.$actor_name.'....</div>';
            // Loop through each row
            while ($row = $result->fetch_assoc()) {
                // Query database for movie in row
                $movieQuery =   "SELECT * FROM movie
                                INNER JOIN genre 
                                ON movie.genre_id=genre.genre_id
                                INNER JOIN director
                                ON movie.director_id=director.director_id
                                INNER JOIN studio
                                ON movie.studio_id=studio.studio_id
                                WHERE movie_id = ".$row['movie_id'];
                
                $movieResult = $dataConnection->query($movieQuery); // Run query
                $row = $movieResult->fetch_assoc();                 // Get result as array
                
                // Get an array of actors from row
                $actors = getMovieActors($row['movie_id'], $dataConnection);
            
                // Crate html output from page
                echo '<div class="movieFieldSetContainer">';
                echo '<fieldset class="movieFieldSet">';
                echo '<legend>'.$row['title'].'</legend>';
                echo '<a href="images/movie_images/'.$row['thumbpath'].'" target="_blank">';
                echo '<img class="movieThumbnail" src="images/movie_images/'.$row['thumbpath'].'" width="105" height="150"/>';
                echo '</a>';
                echo '<div class="movieInfoField"><label id="rentalType">'.$row['rental_period'].' Rental</label></div>';
                echo '<div class="movieInfoField"><label>Genre: </label>'.$row['genre_name'].'</div>';
                echo '<div class="movieInfoField"><label>Year:</label> '.$row['year'].'</div>';
                echo '<div class="movieInfoField"><label>Director:</label> '.$row['director_name'].'</div>';
                echo '<div class="movieInfoField"><label>Classification:</label> '.$row['classification'].'</div>';
                echo '<div class="movieInfoField"><label>Starring:</label> '.join(', ', $actors).'</div>';
                echo '<div class="movieInfoField"><label>Studio:</label> '.$row['studio_name'].'</div>';
                echo '<div class="movieInfoField"><label>Tagline:</label> '.$row['tagline'].'</div>';
                echo '<div class="movieInfoField"><label>Description:</label></div>';
                echo '<div class="movieDescription">'.$row['plot'].'</div>';
                echo '<div class="movieInfoField"><label>Rental:</label> DVD - $'.$row['DVD_rental_price'].'  BluRay - $'.$row['BluRay_rental_price'].'</div>';
                echo '<div class="movieInfoField"><label>Purchase:</label> DVD - $'.$row['DVD_purchase_price'].'  BluRay - $'.$row['BluRay_purchase_price'].'</div>';
                echo '<div class="movieInfoField"><label>Availability:</label> DVD - '.$row['numDVD'].'   BluRay - '.$row['numBluRay'].'</div>';
                // If logged in add cart button
                if ($_SESSION['isLoggedIn']) {
                    echo '<form action="booking.php" method="post">';
                    echo '<input type="hidden" name="title" value="'.$row['title'].'" />'; // Hidden field to contain title of movie
                    echo '<input type="hidden" name="movie_id" value="'.$row['movie_id'].'" />'; // Hidden field to contain id of movie
                    // Check if movie already in cart
                    if (in_array($row['movie_id'], $_SESSION['cartMovies'])) {
                        echo '<input class="movieButtonOut" name="book" type="submit" disabled="" value="In Cart" />';
                    } else {
                        // Check if cart is not full
                        if (!($_SESSION['numberInCart'] >= 5)) {
                                // Check if in stock
                                if ($row['numDVD'] > 0 || $row['numBluRay'] > 0) {
                                    // Check if both dvd and blueray in stock
                                    if ($row['numDVD'] > 0 and $row['numBluRay'] > 0) {
                                        echo '<input class="movieButton" name="book" type="submit" value="Add to Cart" />';
                                    }
                                    // Check if dvd in stock but blueray out
                                    if ($row['numDVD'] > 0 and $row['numBluRay'] == 0) {
                                        echo '<input class="movieButton" name="book" type="submit" value="Only DVD" />';
                                    }
                                    // Check if BluRay in stock but dvd out
                                    if ($row['numDVD'] == 0 and $row['numBluRay'] > 0) {
                                        echo '<input class="movieButton" name="book" type="submit" value="Only BluRay" />';
                                    }
                            } else {
                                echo '<input class="movieButtonOut" name="book" type="submit" disabled="" value="Out" />';
                            }
                        } else {
                            echo '<input class="movieButtonOut" name="book" type="submit" disabled="" value="Cart Full" />';
                        }
                    }



                    echo '</form>';
                }

                echo '</fieldset>';
                echo '</div>';
                
                
                
            }
        } else {
            echo 'Actor "'.$actor_name.'" not found in database...'; // Display message that actor not found in databse
        }
    }
    
    // Function to return an array of actors for specific movie number
    function getMovieActors($movie_id, $dataConnecton) {
        $query = "SELECT * FROM movie_actor_view WHERE movie_id = " . $movie_id; 
        $result = $dataConnecton->query($query);
        $actors = array(); // Array to hold actor names
        
        // loop through results add directors to array
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                array_push($actors, $row['actor_name']);
            }
        }
        
        return $actors;
    }

?>