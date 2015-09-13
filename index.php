<?php
    // Include random movie function
    include 'random_movie.inc';
    
    $randomMovie = getRandomMovie();
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
			<a href="index.html">Home</a>
			<a href="join.html">Join</a>
			<a href="techzone.html">Tech Zone</a>
			<a href="moviezone.php">Movie Zone</a>
			<a href="contact.html">Contact</a>
		</div>

		<div id="rightColumn">
			<h2 id="newReleasesHeader">New Releases</h2>

			<fieldset>
				<legend><?php echo $randomMovie['title'].' ('.$randomMovie['year'].')' ?> </legend>
					


					<span class="newReleaseHeading">Title: </span>
					<span class="newReleaseBody"><?php echo $randomMovie['title']; ?></span>

					<span class="newReleaseHeading">Genre: </span>
					<span class="newReleaseBody"><?php echo $randomMovie['genre_name']; ?></span>

					<span class="newReleaseHeading">Description: </span>
					<span class="newReleaseBody"><?php echo $randomMovie['plot']; ?></span>

					<span class="newReleaseHeading">Image:</span>
					<img width="150" src="images/movie_images/<?php echo $randomMovie['thumbpath']; ?>" alt="<?php echo $randomMovie['title']; ?> (<?php echo $randomMovie['year']; ?>)" />

			</fieldset>

		</div>

		<div id="centerColumn">
			
			<div class="section">
				<h2 id="mainHeader">Welcome to DVD Rentals</h2>
			</div>

			<div class="section">
				
				<a href="images/fearAndLoathingDvd.jpg" target="_blank"><img src="images/fearAndLoathingDvd.jpg" alt="DVD Box" width="200" height="200" class="bodyImage"/></a>

				<p>Welcome to our online DVD-rental shop. You might be wondering what the heck a DVD is… good question! A DVD is an archaic optical disc once used by the ancient movie goers to watch their favorite movies back before we invented digital Piracy… uh, I mean <em>Netflix</em>.</p>

				<p>Anyway if you’ve decided you wanted to take a trip back through time, dust off the old DVD player and impress your friends by watching some movies old-school style, this is the shop for you!</p>
			</div>

			<div class="section">
				<h3>What we do</h3>
				<p>We allow you to sort through our vast catalogue of movies of all genres to entertain, thrill and scare you on all occasions. Our shop has possibly the greatest selection of DVD’s and the newer blu-rays of any online store out there. We also often 5 star customer satisfaction and if you aren’t satisfied than we’ll work with your personally to make your experiences here on DVD rentals a positive one!</p>

			</div>

			<div class="section">
				<h3>Why we do what we do</h3>
				<p>As more and more people prefer to do their shopping online rather than having to physically go to the store to do their shopping it makes sense that people should want to rent their DVD’s online too. There was nothing worse than going to the old DVD rental place and not being sure what movies to rent – when all you had to go off was the bored teenager’s advice as he idly manned the front counter. </p>

				<p>Now you can finally browse DVD’s and Blu-Rays available for rent form the privacy of your own computer and have access to additional information such as IMDB to help you select the best movie and have it delivered directly to your door at the click of a button!</p>

				

			</div>
			<footer><div class="horizontalRule"></div>

				<p id="copyright">Copyright © 2015 <a href="http://infotech.scu.edu.au/~dbrown31/">Dominic Browne - Infotech Site</a></p>
			</footer>
		</div>



	</div>

	

</body>
</html>