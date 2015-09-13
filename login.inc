<?php
    // Check if login form submitted
    if (isset($_POST['submit'])) {
        // Check username and password against database
        
        $loginUserName = $_POST['userName'];
        $loginPassword = $_POST['password'];
        
        // Connect to database
        // Include database settings
        include 'database_settings.inc';    // Edit database_settings.inc to change database settings

        // Connect to database
        $dataConnection = new mysqli($servername, $username, $password, $databaseName);

        // Check if connection successful and stop execution if not.
        if ($dataConnection->connect_error) {
            die("Error connecting to database: " . $dataConnection->connect_error);
        }
        
        // Query database for password
        $query = "SELECT password FROM member WHERE username = '".$loginUserName."'";
        
        // Execute query
        $result = $dataConnection->query($query);
        // check for matches
        if ($result->num_rows > 0) {
            // Get row
            $row = $result->fetch_assoc();
            
            // Compare pasword value
            if ($row['password'] == $loginPassword) {
                // User and password match
                // Set is logged in flag to true
                $_SESSION['isLoggedIn'] = true;
                
                // Redirect to moviezone.php
                header('Location: moviezone.php');
                die(); // Terminate script execution
            } else {
                echo '<div id="loginMessage">Invalid password...</div>';    // Bad password message
            }
        } else {
            echo '<div id="loginMessage">User not found...</div>';          // User not in database message
        }
    }
?>

<div id="loginBox">
    <fieldset id="loginFieldSet">
        <legend>Login</legend>
        <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
            <div class="loginField"><label>Username: </label>
                <span class="inputSpan"><input type="text" name="userName" placeholder="Username" required /></span>
            </div>
            <div class="loginField"><label>Password: </label>
                <span class="inputSpan"><input type="password" name="password" placeholder="Password" required />
            </div>
            <input id="loginButton" type="submit" name="submit" value="Login" />
        </form>
    </fieldset>
</div>
<div id="infoBox">Not registered yet? Click <a href="join.php">here</a> to join.</div>