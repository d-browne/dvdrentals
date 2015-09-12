<?php
    // This include performs the search by director
    
    // Include database settings
    include 'database_settings.inc';    // Edit database_settings.inc to change database settings

    // Connect to database
    $dataConnection = new mysqli($servername, $username, $password, $databaseName);
    
    // Check if connection successful and stop execution if not.
    if ($dataConnection->connect_error) {
        die("Error connecting to database: " . $dataConnection->connect_error);
    }
    
    // Create director selection box
    // Get directors and put them in array
    $directors = getDirectors($dataConnection);
    
    // Draw form to submit directors search
    echo '<form action="moviezone.php?search" method="get">';
    echo '<input type="hidden" name="search" value="director" />';
    echo '<select name="director_name">';
    echo '<option selected="" disabled="" value="">Select Director...</option>';
    // Loop through each actor in array and populate select box
    foreach ($directors as $name=>$id) {
        echo '<option value="'.$name.'">'.$name.'</option>';
    }
    echo '</select>'; // Closing tag for select box
    echo '<input type="submit" value="Search" />'; // Submit button for form
    echo '</form>'; // closing tag for form
    
    // Check if director name is specified in the get requet
    if (isset($_GET['director_name'])) {
        // Show movies with selected director
        
        $query =                "SELECT * FROM movie
                                INNER JOIN genre 
                                ON movie.genre_id=genre.genre_id
                                INNER JOIN director
                                ON movie.director_id=director.director_id
                                INNER JOIN studio
                                ON movie.studio_id=studio.studio_id
                                WHERE director_name = '".$_GET['director_name']."'"; // Query to select movies of matching director
        
        // Execute query
        $result = $dataConnection->query($query);
        
        // check if results > 0
        if ($result->num_rows > 0) {
            // Show number of results
            echo '<div id="resultsTag">Showing '.$result->num_rows.' results for the director '.$_GET['director_name'].'...</div>';
            
            // Loops through each row and display movie information 
            while ($row = $result->fetch_assoc()) {
                // Get an array of actors
                $actors = getActors($row['movie_id'], $dataConnection);
                
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
        }
    }
    
    // Function to return directr names and ids
    function getDirectors($dataConnection) {
        // Query to select director
        $query = "SELECT * FROM director";
        
        //Execute query
        $result = $dataConnection->query($query);
        
        // Put query reults in array
        $directors = array();
        // check if result from query found
        if ($result->num_rows > 0) {
            // Loop through each result
            while ($row = $result->fetch_assoc()) {
                $directors[$row['director_name']] = $row['director_id'];
            }
        }
        
        return $directors;
    }
    
    // Function to return an array of actors for specific movie number
    function getActors($movie_id, $dataConnecton) {
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