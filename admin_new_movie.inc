<?php
    // Include database settings
    include 'database_settings.inc';    // Edit database_settings.inc to change database settings

    // Connect to database
    $dataConnection = new mysqli($servername, $username, $password, $databaseName);
    
    // Check if connection successful and stop execution if not.
    if ($dataConnection->connect_error) {
        die("Error connecting to database: " . $dataConnection->connect_error);
    }

    // Check if user attempted to create new movie
    if (isset($_POST['submit_create'])) // Check if create movie button clicked
    {
        // Process new movie request
        include 'add_movie_to_database.inc';
        addMovieToDatabase($dataConnection, $_POST);
    }
    
    // Get get array of directors to populate select box
    $directors = getDirectors($dataConnection);
    // Get array of studios to populate select box
    $studios = getStudios($dataConnection);
    // Get array of genres to populate select box
    $genres = getGenres($dataConnection);
    // Get array of classifications to populate select box
    $classifications = getClassifications($dataConnection);
    // Get array of actors to populate list box
    $actors = getActors($dataConnection);
    
    // Function to return array of directors
    function getDirectors($dataConnection)
    {
        // Query to get all directors
        $query =    "SELECT director_name FROM director
                    ORDER BY director_name";
        // Execute query 
        $result = $dataConnection->query($query);
        
        // Create array to hold directors
        $directors = array();
        
        // check if query results found
        if ($result->num_rows > 0)
        {
            // loop through each result and put director in array
            while ($row = $result->fetch_assoc())
            {
                array_push($directors, $row['director_name']);
            }
        }
        
        // Return directors array
        return $directors;
        
    }
    // Function to return array of studios
    function getStudios($dataConnection)
    {
        // Query to get all studios
        $query =    "SELECT studio_name FROM studio
                    ORDER BY studio_name";
        
        //execute query
        $result = $dataConnection->query($query);
        
        // create array to hold studios
        $studios = array();
        
        // Check if result returned any values
        if ($result->num_rows > 0)
        {
            // Loop through each result and put it in array
            while ($row = $result->fetch_assoc())
            {
                array_push($studios, $row['studio_name']);
            }
        }
        
        // Return array data
        return $studios;
    }
    
    // Function to return array of genres
    function getGenres($dataConnection)
    {
        // Query to get all genres
        $query =    "SELECT genre_name FROM genre
                    ORDER BY genre_name";
        // Execute query
        $result = $dataConnection->query($query);
        
        // Create array to hold genres
        $genres = array();
        
        // Check if results in query 
        if ($result->num_rows > 0)
        {
            // loop through each genre and insert into array
            while ($row = $result->fetch_assoc())
            {
                array_push($genres, $row['genre_name']);
            }
        }
        
        // Return genres array
        return $genres;
    }
    
    // Function to return an array of classifications
    function getClassifications($dataConnection)
    {
        // Query to get all classifications
        $query =    "SELECT classification FROM movie
                    GROUP BY classification
                    ORDER BY classification";
        // Execute query
        $result = $dataConnection->query($query);
        
        // Create array to hold classifications
        $classifications = array();
        
        // Check if results from query
        if ($result->num_rows > 0 )
        {
            // Loop through each result and add classification to array
            while ($row = $result->fetch_assoc())
            {
                array_push($classifications, $row['classification']);
            }
        }
        
        // Return classifications array
        return $classifications;
    }
    
    // Function to return an array of actors
    function getActors($dataConnection)
    {
        // Query to get all actors
        $query =    "SELECT actor_name FROM actor
                    ORDER BY actor_name";
        // Execute query
        $result = $dataConnection->query($query);
        
        // array to hold all actors
        $actors = array();
        
        // check if results in query
        if ($result->num_rows > 0)
        {
            // loop through results and add each actor to array
            while ($row = $result->fetch_assoc())
            {
                array_push($actors, $row['actor_name']);
            }
        }
        
        // Return array of actors
        return $actors;
    }

?>
<div id="starMeaning">* = Compulsory</div>
<form action="admin.php?action=new_movie" method="POST">
    <div class="controlPanelSection">
        <fieldset>
            <legend>New Movie</legend>
            <div class="memberDetailsField"><label>Title: </label><input type="text" name="movie_title" /> *</div>
            <div class="memberDetailsField"><label>Year: </label><input type="text" name="movie_year" /> *</div>
            <div class="memberDetailsField"><label>Tag Line: </label><input type="text" name="movie_tagline" /> *</div>
            <div class="memberDetailsField"><label>Plot: </label><textarea maxlength="256" cols="60" rows="4" name="movie_plot"></textarea> *</div>
            <div class="memberDetailsField"><label>Poster: </label><input type="file" name="movie_poster" accept="image/*"> *</div>
            <div class="memberDetailsField"><label>Director: </label>
                <select name="director_name"> 
                    <option value="blank">Select...</option>
                    <?php
                        // For each director in directors array create option for director
                        foreach ($directors as $director)
                        {
                            echo '<option value="'.$director.'">'.$director.'</option>';
                        }
                    ?>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New Director: </label><input type="text" name="new_director" /></div>
            <div class="memberDetailsField"><label>Studio:</label>
                <select name="studio_name"> 
                    <option value="blank">Select...</option>
                    <?php
                        // Loop through each studio in array and create list item for each
                        foreach ($studios as $studio)
                        {
                            echo '<option value="'.$studio.'">'.$studio.'</option>';
                        }
                    ?>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New Studio: </label><input type="text" name="new_studio" /></div>
            <div class="memberDetailsField"><label>Genre: </label>
                <select name="genre_name"> *
                    <option value="blank">Select...</option>
                    <?php
                        // Loop through each genre in array and create list item for each
                        foreach ($genres as $genre)
                        {
                            echo '<option value="'.$genre.'">'.$genre.'</option>'; 
                        }
                    ?>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New Genre: </label><input type="text" name="new_genre" /></div>
            <div class="memberDetailsField"><label>Classification:</label>
                <select name="classification_name"> *
                    <option value="blank">Select...</option>
                    <?php
                        // Loop through each classification in array and add option
                        foreach ($classifications as $classification)
                        {
                            echo '<option value="'.$classification.'">'.$classification.'</option>'; 
                        }
                    ?>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New Classification: </label><input type="text" name="new_classification" /></div>
        </fieldset>
    </div>
    <div class="controlPanelSection">
        <fieldset>
            <legend>Stars and Co Stars</legend>
            <div class="memberDetailsField"><label>First star:</label>
                <select name="first_star_name">
                    <option value="blank">Select...</option>
                    <?php
                        // Populate list box with options of all actor in array
                        foreach ($actors as $actor)
                        {
                            echo '<option value="'.$actor.'">'.$actor.'</option>';
                        }
                    ?>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New First Star: </label><input type="text" name="new_first_star" /></div>
            <div class="memberDetailsField"><label>Second Star:</label>
                <select name="second_star_name">
                    <option value="blank">Select...</option>
                    <?php
                        // Populate list box with options of all actor in array
                        foreach ($actors as $actor)
                        {
                            echo '<option value="'.$actor.'">'.$actor.'</option>';
                        }
                    ?>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New Second Star: </label><input type="text" name="new_second_star" /></div>
            <div class="memberDetailsField"><label>Third Star: </label>
                <select name="third_star_name">
                    <option value="blank">Select...</option>
                    <?php
                        // Populate list box with options of all actor in array
                        foreach ($actors as $actor)
                        {
                            echo '<option value="'.$actor.'">'.$actor.'</option>';
                        }
                    ?>
                </select>
            </div>
            <div class="memberDetailsField"><label>New Third Star: </label><input type="text" name="new_third_star" /></div>
            <div class="memberDetailsField"><label>First Costar</label>
                <select name="first_costar_name">
                    <option value="blank">Select...</option>
                    <?php
                        // Populate list box with options of all actor in array
                        foreach ($actors as $actor)
                        {
                            echo '<option value="'.$actor.'">'.$actor.'</option>';
                        }
                    ?>
                </select>
            </div>
            <div class="memberDetailsField"><label>New First Costar: </label><input type="text" name="new_first_costar" /></div>
            <div class="memberDetailsField"><label>Second Costar:</label>
                <select name="second_costar_name">
                    <option value="blank">Select...</option>
                    <?php
                        // Populate list box with options of all actor in array
                        foreach ($actors as $actor)
                        {
                            echo '<option value="'.$actor.'">'.$actor.'</option>';
                        }
                    ?>
                </select>
            </div>
            <div class="memberDetailsField"><label>New Second Costar: </label><input type="text" name="new_second_costar" /></div>
            <div class="memberDetailsField"><label>Third Costar:</label>
                <select name="third_costar_name">
                    <option value="blank">Select...</option>
                    <?php
                        // Populate list box with options of all actor in array
                        foreach ($actors as $actor)
                        {
                            echo '<option value="'.$actor.'">'.$actor.'</option>';
                        }
                    ?>
                </select>
            </div>
            <div class="memberDetailsField"><label>New Third Costar: </label><input type="text" name="new_third_costar" /></div>
        </fieldset>
    </div>
    <div class="controlPanelSection">
        <fieldset>
            <legend>Stock Information</legend>
            <div class="memberDetailsField"><label>Rental Period: </label>
                <select name="rental_period">
                    <option value="3 Day">3 Day</option>
                    <option value="Weekly">Weekly</option>
                    <option value="Overnight">Overnight</option>
                </select> *
            </div>
            <fieldset>
                <legend>DVD</legend>
                <div class="memberDetailsField"><label>Rental Price: </label><input type="text" name="dvd_rental_price" /> *</div>
                <div class="memberDetailsField"><label>Purchase Price: </label><input type="text" name="dvd_purchase_price" /> *</div>
                <div class="memberDetailsField"><label>In-Stock: </label><input type="text" name="numDVD" /> *</div>
                <div class="memberDetailsField"><label>Rented out: </label><input type="text" name="outDVD" /> *</div>
            </fieldset>
            <fieldset id="BluRayFieldSet">
                <legend>BluRay</legend>
                <div class="memberDetailsField"><label>Rental Price: </label><input type="text" name="bluray_rental_price" /> *</div>
                <div class="memberDetailsField"><label>Purchase Price: </label><input type="text" name="bluray_purchase_price" /> *</div>
                <div class="memberDetailsField"><label>In-Stock: </label><input type="text" name="numBluRay" /> *</div>
                <div class="memberDetailsField"><label>Rented out: </label><input type="text" name="numBluRayOut" /> *</div>
            </fieldset>
        </fieldset>
    </div>
    <input type="reset" class="controlPanelButton" value="Reset" /><input type="submit" class="controlPanelButton" name="submit_create" value="Create Movie" />
</form>