<?php
    $adminPassword = 'webdev2';
    
    // Check if login attempted
    if (isset($_POST['submit'])) {
        // Check if password matches 
        if ($_POST['password'] == $adminPassword) {
            echo '<div id="loginMessage">Login Successful!</div>';
        } else
        {
            echo '<div id="loginMessage">Invalid admin password...</div>';
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
                <span class="inputSpan"><input type="text" name="password" placeholder="Password" required />
            </div>
            <input id="loginButton" type="submit" name="submit" value="Login" />
        </form>
    </fieldset>
</div>
<div id="infoBox">Not an admin? click <a href="booking.php">here</a> for member login</div>