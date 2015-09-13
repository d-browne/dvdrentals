<?php
    // Include random movie function
    include 'random_movie.inc';
    
    $randomMovie = getRandomMovie();
    
    // Include user session globals
    include 'user_session_globals.inc';
    
    // Check for search string
    if (!isset($_GET['search']))
    {
        // Page not searched
        // Set search type to new releases
        $searchType = "new_release";
    }
    else
    {
        $searchType = strtolower($_GET['search']);
    }
    
    // Set page title according to search type
    switch ($searchType) {
        case "all_movies":
            // Code to display all movies
            $pageTitle = "All Movies";                      // Set page title
            $includeFileName = "all_movies.inc";            // Include name
            break;
        case "new_releases":
            // Code to display new releases
            $pageTitle = "New Releases";                    // Set page title
            $includeFileName = "new_releases.inc";          // Include name
            break;
        case "actor":
            // Code to display search by actor
            $pageTitle = "Search by Actor";                 // Set page title
            $includeFileName = "actor.inc";                 // Include name
            break;
        case "genre":
            // Code to display search by genre
            $pageTitle = "Search by Genre";                 // Set page title
            $includeFileName = "genre.inc";                 // Include name
            break;
        case "director":
            // Code to display search by director
            $pageTitle = "Search by Director";
            $includeFileName = "director.inc";  
            break;
        case "classification":
            // Code to display search by director
            $pageTitle = "Search by Classification";
            $includeFileName = "classification.inc"; 
            break;
        default:
            // Unknown search type
            $pageTitle = "New Releases";
            $includeFileName = "new_releases.inc";
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
				<h2 id="mainHeader">Movie Zone - <?php echo $pageTitle; ?>
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
						// Call include
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