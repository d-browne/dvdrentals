<?php



function getRandomMovie() {
    // Connect to database
    include 'connect_to_database.inc';

    // Get new releases
    // Query all movies from 2014 up
    $query = "SELECT * FROM movie 
                INNER JOIN genre 
                ON movie.genre_id=genre.genre_id
                INNER JOIN director
                ON movie.director_id=director.director_id
                INNER JOIN studio
                ON movie.studio_id=studio.studio_id
                WHERE year >= 2014";
    $result = $dataConnection->query($query);
    
    $movies = array();
    
    // check if there are results
    if ($result->num_rows > 0) {


        // Loop through each result and put them into array
        while ($row = $result->fetch_assoc()) {
            array_push($movies, $row);
        }

        // Select random number between 0 and max length of array
        $randomIndex = rand(0, count($movies)-1);
        
        return $movies[$randomIndex];
    }
    
    
}

?>
