<?php
    // use session
    //session_start();

    // Include database settings
    include 'database_settings.inc';    // Edit database_settings.inc to change database settings
    
    // Connect to database
    $dataConnection = new mysqli($servername, $username, $password, $databaseName);
    
    // Check if connection successful and stop execution if not.
    if ($dataConnection->connect_error) {
        die("Error connecting to database: " . $dataConnection->connect_error);
    }
    
    // query for all movies in the databse
    $query =    "SELECT * FROM movie 
                INNER JOIN genre 
                ON movie.genre_id=genre.genre_id
                INNER JOIN director
                ON movie.director_id=director.director_id
                INNER JOIN studio
                ON movie.studio_id=studio.studio_id";
    // Store query result in result
    $result = $dataConnection->query($query); 
    
    // If result found
    if ($result->num_rows > 0) {
        // Print number of results
        echo '<div id="resultsTag">Showing '.$result->num_rows.' results....</div>';
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
            // If logged in add cart button
            if ($_SESSION['isLoggedIn']) {
                echo '<form><input class="movieButton" type="submit" value="Add to Cart" /></form>';
            }
            
            echo '</fieldset>';
            echo '</div>';
        }   
    }
    
    // Function to return an array of actors for specific movie number
    function getActors($movie_id, $dataConnecton) {
        $query = "SELECT * FROM movie_actor_view WHERE movie_id = " . $movie_id; 
        $result = $dataConnecton->query($query);
        $actors = []; // Array to hold actor names
        
        // loop through results add directors to array
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                array_push($actors, $row['actor_name']);
            }
        }
        
        return $actors;
    }

?>