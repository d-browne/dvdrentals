<?php
    // Include random movie function
    include 'random_movie.inc';
    
    $randomMovie = getRandomMovie();

    //Include user session globals
    include 'user_session_globals.inc';
    
    // Check if logout GET request recieved
    if (isset($_GET['logout'])) {
        // Set logged in flag to false
        $_SESSION['isLoggedIn'] = false;
        session_destroy(); // Destory session
    }
    
    // Check if clear GET request recieved
    if (isset($_GET['clear'])) {
        // Clear cart
        $_SESSION['cartMovies'] = array();
        $_SESSION['numberInCart'] = count($_SESSION['cartMovies']);
    }
    
    // Check for remove POST request
    if (isset($_POST['remove'])) {
        // Remove movie from array
        unset($_SESSION['cartMovies'][$_POST['title']]);
        $_SESSION['numberInCart'] = count($_SESSION['cartMovies']);
    }
    
    // book POST request recieved add movie to sesison variable
    if (isset($_POST['book'])) {
        if ($_SESSION['numberInCart'] < 5) {
            $_SESSION['cartMovies'][$_POST['title']] = $_POST['movie_id'];
            $_SESSION['numberInCart'] = count($_SESSION['cartMovies']);
            // Return to referring unless cart full, then proceed to cart page
            if ($_SESSION['numberInCart']< 5) {
                header('Location: ' . $_SERVER['HTTP_REFERER']);
                die();
            }
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
			<a href="join.html">Join</a>
			<a href="techzone.html">Tech Zone</a>
			<a href="moviezone.php">Movie Zone</a>
			<a href="contact.html">Contact</a>
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
				<h2 id="mainHeader">Movie Zone - Booking</h2>
                
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
                        // Display logged out message if logged out
                        if (isset($_GET['logout'])) {
                            echo '<div id="loginMessage">Logged out!</div>';
                        }
                   
                        // Check if logged in
                        if ($_SESSION['isLoggedIn']) {
                            // Display cart
                            include 'cart.inc';
                        }
                        else {
                            // Display login form
                            include 'login.inc';
                        }
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