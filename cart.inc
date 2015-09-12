<div id="cartInformation">
    <?php echo $_SESSION['numberInCart'] ?>/5 Items in cart! - Warning this module currently under construction and there is no facility to check out yet.
    <br/>
    <a href="booking.php?clear">Clear</a></div>
    <?php
        // Include database settings
        include 'database_settings.inc';    // Edit database_settings.inc to change database settings

        // Connect to database
        $dataConnection = new mysqli($servername, $username, $password, $databaseName);

        // Check if connection successful and stop execution if not.
        if ($dataConnection->connect_error) {
            die("Error connecting to database: " . $dataConnection->connect_error);
        }
        
        // check to see if number of movies is great than 0
        if ($_SESSION['numberInCart'] > 0) {
            // Build query to get each movie in cart
            $query =            "SELECT * FROM movie
                                INNER JOIN genre 
                                ON movie.genre_id=genre.genre_id
                                INNER JOIN director
                                ON movie.director_id=director.director_id
                                INNER JOIN studio
                                ON movie.studio_id=studio.studio_id
                                WHERE movie_id = 0";
            foreach ($_SESSION['cartMovies'] as $title=>$id) {
                $query .= " OR movie_id = " . $id;
            }
            
            // Execute query
            $result = $dataConnection->query($query);
            
            // Check if result > 0
            if ($result->num_rows > 0) {
                // Loop through each row
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
                    // Add remove from cart button
                    echo '<form action="booking.php" method="post">';
                    echo '<input type="hidden" name="title" value="'.$row['title'].'" />'; // Hidden field to contain title of movie
                    echo '<input type="hidden" name="movie_id" value="'.$row['movie_id'].'" />'; // Hidden field to contain id of movie
                    echo '<input class="movieButton" name="remove" type="submit" value="Remove" />';
                    
                    echo '</form>';
                    echo '</fieldset>';
                    echo '</div>';
                }
            }
        } else {
            echo "There is nothing in the cart...";
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