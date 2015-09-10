<?php
    // Connection details
    $servername = "localhost";
    $username = "root";
    $password = "";
    $databaseName = "dbrown31_moviezone_db";
    
    // Connect to database
    $dataConnection = new mysqli($servername, $username, $password, $databaseName);
    
    // Check if connection successful
    if ($dataConnection->connect_error) {
        die("Error connecting to database: " . $dataConnection->connect_error);
    }
    
    // Connected successfully
    echo "connected to database!<br>";
    
    // Query all movies from 2014 up
    $query =    "SELECT * FROM movie 
                INNER JOIN genre 
                ON movie.genre_id=genre.genre_id
                INNER JOIN director
                ON movie.director_id=director.director_id
                WHERE year >= 2014";
    $result = $dataConnection->query($query);
    
    
    // Loop through all grows
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            // Get an array of actors
            $actors = getActors($row['movie_id'], $dataConnection);
            
            // Crate html output from page
            echo '<div class="movieFieldSetContainer">';
            echo '<fieldset class="movieFieldSet">';
            echo '<legend>'.$row['title'].'</legend>';
            echo '<img class="movieThumbnail" src="images/movie_images/'.$row['thumbpath'].'" width="105" height="150"/>';
            echo '<div class="movieInfoField"><label id="rentalType">'.$row['rental_period'].' Rental</label></div>';
            echo '<div class="movieInfoField"><label>Genre: </label>'.$row['genre_name'].'</div>';
            echo '<div class="movieInfoField"><label>Year:</label> '.$row['year'].'</div>';
            echo '<div class="movieInfoField"><label>Director:</label> '.$row['director_name'].'</div>';
            echo '<div class="movieInfoField"><label>Classification:</label> '.$row['classification'].'</div>';
            echo '<div class="movieInfoField"><label>Starring:</label> '.join(', ', $actors).'</div>';
            echo '<div class="movieInfoField"><label>Studio:</label> Marvel Studios</div>';
            echo '<div class="movieInfoField"><label>Tagline:</label> In heroes we trust. </div>';
            echo '<div class="movieInfoField"><label>Description:</label></div>';
            echo '<div class="movieDescription">As Steve Rogers struggles to embrace his role in the modern world, he teams up with another super soldier, the black widow, to battle a new threat from old history: an assassin known as the Winter Soldier.</div>';
            echo '<div class="movieInfoField"><label>Rental:</label> DVD - $5.00  BluRay - $6.00</div>';
            echo '<div class="movieInfoField"><label>Purchase:</label> DVD - $24.95  BluRay - $35.95</div>';
            echo '<div class="movieInfoField"><label>Availability:</label> DVD - 0   BluRay - 0</div>';
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