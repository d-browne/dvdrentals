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
    // Check POST submited (to delete or edit user)
    if(isset($_POST['submit']))
    {
        // Check if user delete requested delete username from database
        if ($_POST['submit'] == 'Remove User')
        {
            // Get username, escape to avoid sql injection
            $username = mysqli_real_escape_string($dataConnection, $_POST['joinusername']);
            
            // Query to delete user
            $query =  "DELETE FROM member WHERE username = '".$username."'";
            $result = $dataConnection->query($query); // Execute query
            
            // Show member deleted
            echo '<div id="resultsTag">Member "'.$username.'" deleted!</div>';
        }
        
        if ($_POST['submit'] == 'Update User')
        {
            // Update user
            include 'admin_edit_user_update.inc';
        }
    }
        
    
    // Check if GET request submitted with member_username
    if (isset($_GET['member_username']))
    {
        // Escape input
        $member_username = mysqli_real_escape_string($dataConnection, $_GET['member_username']); // Escpae input
        //
        // Query database for username
        $query = "SELECT * FROM member WHERE username = '".$member_username."'";
        $result = $dataConnection->query($query);
      
        // Check if username matches a member in the database
        if ($result->num_rows > 0)
        {
            // Display page body
            include 'admin_edit_user_body.inc';
        }
        else
        {
            // Display error
            echo '<div id="resultsTag">No user named '.$_GET['member_username'].' in the database...</div>';
        }
        
        
    }
?>