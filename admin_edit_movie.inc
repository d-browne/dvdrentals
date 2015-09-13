<?php // php to connect to database
    // Include database settings
    include 'database_settings.inc';    // Edit database_settings.inc to change database settings

    // Connect to database
    $dataConnection = new mysqli($servername, $username, $password, $databaseName);
    
    // Check if connection successful and stop execution if not.
    if ($dataConnection->connect_error) {
        die("Error connecting to database: " . $dataConnection->connect_error);
    }
    
    
?>

<h2 id="controlPanelHeading">Edit/Remove Movie</h2>
<div id="editObjectSelectBox">
    <form id="editObjectSelectForm" action="admin.php?action" method="get">
        <input type="hidden" name="action" value="edit_movie" />
        <select name="movie_title">
            <option disabled="" selected="" value="">Select movie...</option>
            <?php // get a list of all movies to populate teh list box
                $query =    "SELECT * FROM movie
                            ORDER BY title"; // Order by title for alphabetical listing
                // Execute query
                $result = $dataConnection->query($query);
                
                // Check if there is more than 1 result 
                if ($result->num_rows > 0)
                {
                    // Loop through each row and populate select box
                    while ($row = $result->fetch_assoc())
                    {
                        // Draw select option
                        echo '<option value="'.$row['title'].'">'.$row['title'].'</option>';
                    }
                }
                else 
                {
                    // Display no movies in database error
                    echo '<div id="resultsTag">There are no movies in the database...</div>';
                }
            ?>
        </select>
        <input type="submit" value="Edit Movie">
    </form>
</div>

<?php
    // Check if get request with movie_title recieved
    if (isset($_GET['movie_title']))
    {
        // Query database for movie
        $movie_title = mysqli_real_escape_string($dataConnection, $_GET['movie_title']); // Escape input
        
        $query = "SELECT * FROM movie WHERE title = '".$movie_title."'";
        // Execute query
        $result = $dataConnection->query($query);

        // Check if movie is in database
        if ($result->num_rows > 0)
        {
            // Display edit movie page body
            include 'admin_edit_movie_body.inc';
        }
        else
        {
            echo '<div id="resultsTag">There are no movie titled '.$_GET['movie_title'].' in the database...</div>';
        }
    }

?>