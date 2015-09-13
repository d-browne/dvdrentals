<?php
    // Include random movie function
    include 'random_movie.inc';
    
    $randomMovie = getRandomMovie();

    // Include user session globals
    include 'user_session_globals.inc';
    
    // If not logged in display admin login page
    if (!$_SESSION['adminLoggedIn']) {
        $includeFileName = 'admin_login.inc';
        $pageTitle = "Login";
    } else {
        // Display relevant admin page
        // Check if admin action specified
        if (isset($_GET['action'])) {
            // Perform action specified
            switch ($_GET['action']) {
                case 'logout':
                    // Log admin out
                    $_SESSION['adminLoggedIn'] = false;
                    header('Location: admin.php');
                    die(); // Terminate script execution
                    break;
                case 'edit_user':
                    $includeFileName = 'admin_edit_user.inc';
                    $pageTitle = "Control Panel - Edit User";
                    break;
                case 'edit_movie': 
                    $includeFileName = 'admin_edit_movie.inc';
                    $pageTitle = "Control Panel - Edit Movie";
                    break;
                case 'new_movie':
                    $includeFileName = 'admin_new_movie.inc';
                    $pageTitle = 'Control Panel - New Movie';
                    break;
                
            }
        } else {
            // Display admin control panel
            $includeFileName = 'admin_control_panel.inc';
            $pageTitle = "Control Panel";
        }
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<title>DVD Rentals</title>
	<meta charset="utf-8" />
	<link rel="stylesheet" href="css/styles_main.css" type="text/css">
</head>
<body>
	<div id="content">

		<a href="index.php" id="headerBox">
			<h1 id="pageHeader">DVD Rentals</h1>
		</a>

		<div id="menuBar">
			<h3 id="menuHeader">Menu</h3>
			<a href="index.php">Home</a>
			<a href="join.php">Join</a>
			<a href="techzone.php">Tech Zone</a>
			<a href="moviezone.php">Movie Zone</a>
			<a href="contact.php">Contact</a>
		</div>

		<div id="rightColumn">
			<h2 id="newReleasesHeader"><a href="moviezone.php">New Releases</a></h2>

			<fieldset>
				<legend><?php echo $randomMovie['title'].' ('.$randomMovie['year'].')' ?> </legend>
					


					<span class="newReleaseHeading">Title: </span>
					<span class="newReleaseBody"><?php echo $randomMovie['title']; ?></span>

					<span class="newReleaseHeading">Genre: </span>
					<span class="newReleaseBody"><?php echo $randomMovie['genre_name']; ?></span>

					<span class="newReleaseHeading">Description: </span>
					<span class="newReleaseBody"><?php echo $randomMovie['plot']; ?></span>

					<span class="newReleaseHeading">Image:</span>
					<img width="140" src="images/movie_images/<?php echo $randomMovie['thumbpath']; ?>" alt="<?php echo $randomMovie['title']; ?> (<?php echo $randomMovie['year']; ?>)" />

			</fieldset>
			
		</div>

		<div id="centerColumn">
			
			<div class="section">
				<h2 id="mainHeader">Admin - <?php echo $pageTitle; ?>
                                    <?php
                                        // If logged in display cart
                                        if ($_SESSION['isLoggedIn']) {
                                           echo '<a id="cartLink" href="booking.php">';
                                            echo '<div id="cartDiv"><span id="cartItems">'.$_SESSION['numberInCart'].'</span><img src="images/cartIcon.png" alt="cart" width="27"/></div>';
                                            echo '</a>'; 
                                        }
                                    ?>
                                </h2>
                
                <div id="moviezoneOptionsbar">
                	<a href="moviezone.php?search=all_movies">
                		<div class="moviezoneOptionButton">All Movies</div>
                    </a>
                    <a href="moviezone.php?search=new_releases">
                    	<div class="moviezoneOptionButton">New Releases</div>
                    </a>
                    <a href="moviezone.php?search=actor">
                    	<div class="moviezoneOptionButton">By Actor</div>
                    </a>
                    <a href="moviezone.php?search=genre">
                    	<div class="moviezoneOptionButton">By Genre</div>
                    </a>
                    <a href="moviezone.php?search=director">
                    	<div class="moviezoneOptionButton">By Director</div>
                    </a>
                    <a href="moviezone.php?search=classification">
                    	<div class="moviezoneOptionButton">By Classification</div>
                    </a>
                    <a href="booking.php<?php if ($_SESSION['isLoggedIn']) { echo '?logout';} ?>"> 
                        <div class="moviezoneUserOptionButton"><?php if ($_SESSION['isLoggedIn']) { echo 'Logout';} else { echo 'Login'; } ?></div>
                    </a>
                    <a href="admin.php">
                        <div class="moviezoneUserOptionButton">Admin</div>
                    </a>
                </div>
                
                <div id="moviesBox">
                    <?php
                        include $includeFileName;
                    ?>
                </div>
			</div>

			<footer>
				<div class="horizontalRule"></div>

				<p id="copyright">Copyright © 2015 <a href="http://infotech.scu.edu.au/~dbrown31/">Dominic Browne - Infotech Site</a></p>
			</footer>

		</div>


	</div>

	

</body>
</html>