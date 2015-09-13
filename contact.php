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
				<h2 id="mainHeader">Contact</h2>

				<p>Our e-shop does not have a physical premises but our warehouse is located at <span style="font-weight:bold;">Southern Cross University</span> in Lismore and all DVD’s will be shipped from there. </p>

				<p><label class="contactHeading">Phone: </label>0448-538-345</p>
				<p><label class="contactHeading">Address: </label>Military Road, East Lismore NSW 2480</p>
				<p><label class="contactHeading">Email: </label>info@dvdeshop.com.au</p>
			</div>

			<div class="section">
				<h3>Map</h3>

				<!-- google map snippit -->
				<script type="text/javascript" src="http://maps.google.com/maps/api/js?sensor=false"></script><div style="overflow:hidden;height:500px;width:600px;margin:auto;"><div id="gmap_canvas" style="height:500px;width:600px;"></div></div><div style="text-align:right;width:600px;font-family:arial;font-size:10px;color:#555">© <a style="text-decoration:none;color:#555;cursor:default;" href="http://www.themecircle.net" id="get-map-data" class="google-map-code">SCU</a></div><script type="text/javascript"> function init_map(){var myOptions = {zoom:14,center:new google.maps.LatLng(-28.8249601,153.2983223),mapTypeId: google.maps.MapTypeId.ROADMAP};map = new google.maps.Map(document.getElementById("gmap_canvas"), myOptions);marker = new google.maps.Marker({map: map,position: new google.maps.LatLng(-28.8249601, 153.2983223)});infowindow = new google.maps.InfoWindow({content:"<b>SCU</b><br/>Military Road, East Lismore NSW 2480<br/> New York" });google.maps.event.addListener(marker, "click", function(){infowindow.open(map,marker);});infowindow.open(map,marker);}google.maps.event.addDomListener(window, 'load', init_map);</script>

			</div>

			<footer>
				<div class="horizontalRule"></div>

				<p id="copyright">Copyright © 2015 <a href="http://infotech.scu.edu.au/~dbrown31/">Dominic Browne - Infotech Site</a></p>
			</footer>

		</div>



	</div>

	

</body>
</html>