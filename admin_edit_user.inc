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

<h2 id="controlPanelHeading">Edit/Remove Member</h2>
<div id="editObjectSelectBox">
    <form id="editObjectSelectForm" action="admin.php?action" method="get">
        <input type="hidden" name="action" value="edit_user" />
        <select name="member_username">
            <option disabled="" selected="" value="blank">Select member...</option>
            <?php // Get a list of all members from database and populate select box
                // Query to get all members
                $query = "SELECT * FROM member";
                
                // Execute query
                $result = $dataConnection->query($query);
                
                // Check if there are results
                if ($result->num_rows > 0)
                {
                    // Loop through each row
                    while ($row = $result->fetch_assoc())
                    {
                        // Draw a listbox option
                        echo '<option value="'.$row['username'].'">'.$row['username'].' - '.$row['surname'].', '.$row['other_name'].'</option>';
                    }
                }
                else 
                {
                    // Display no users in database message
                    echo '<div id="resultsTag">There are no members in the database...</div>';
                }
                
            ?>
        </select>
        <input type="submit" value="Edit Member">
    </form>
</div>

<?php
    // Check if GET request submitted with member_username
    if (isset($_GET['member_username']))
    {
        // Display page body
        echo 'page for ' . $_GET['member_username'];
    }
?>