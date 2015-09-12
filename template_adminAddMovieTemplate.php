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
			<h2 id="newReleasesHeader">New Releases</h2>

			<fieldset>
				<legend>Home (2015)</legend>
					


					<span class="newReleaseHeading">Title: </span>
					<span class="newReleaseBody">Home</span>

					<span class="newReleaseHeading">Runtime: </span>
					<span class="newReleaseBody">94 minutes</span>

					<span class="newReleaseHeading">Description: </span>
					<span class="newReleaseBody">Oh, an alien on the run from his own people, lands on Earth and makes friends with the adventurous Tip, who is on a quest of her own.</span>

					<span class="newReleaseHeading">Image:</span>
					<img src="images/home2015.jpg" alt="Home (2015)" />

			</fieldset>
			
		</div>

		<div id="centerColumn">
			
			<div class="section">
				<h2 id="mainHeader">
                	Admin - Control Panel
                    <a id="cartLink" href="booking.php">
                    	<div id="cartDiv"><span id="cartItems">1</span><img src="images/cartIcon.png" alt="cart" width="27"/></div>
                    </a>
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
                    <div class="moviezoneUserOptionButton">Login</div>
                    <div class="moviezoneUserOptionButton">Admin</div>
                </div>
                
                <div id="moviesBox">
                	<h2 id="controlPanelHeading">Add Movie</h2>
                    <div id="starMeaning">* = Compulsory</div>
                    <form>
                    <div class="controlPanelSection">
                        <fieldset>
                            <legend>New Movie</legend>
                            <div class="memberDetailsField"><label>Title: </label><input type="text" name="movie_title" /> *</div>
                            <div class="memberDetailsField"><label>Year: </label><input type="text" name="movie_year" /> *</div>
                            <div class="memberDetailsField"><label>Tag Line: </label><input type="text" name="movie_tagline" /> *</div>
                            <div class="memberDetailsField"><label>Plot: </label><textarea maxlength="256" cols="60" rows="4" name="movie_plot"></textarea> *</div>
                            <div class="memberDetailsField"><label>Poster: </label><input type="file" name="movie_poster" accept="image/*"> *</div>
                            <div class="memberDetailsField"><label>Director: </label>
                            	<select name="director_name"> 
                                	<option value="blank">Select...</option>
                                    <option value="Val Kilmer">Val Kilmer</option>
                                </select> *
                            </div>
                            <div class="memberDetailsField"><label>New Director: </label><input type="text" name="new_director" /></div>
                            <div class="memberDetailsField"><label>Studio:</label>
                            	<select name="studio_name"> 
                                	<option value="blank">Select...</option>
                                    <option value="Marvel">Marvel</option>
                                </select> *
                            </div>
                            <div class="memberDetailsField"><label>New Studio: </label><input type="text" name="new_studio" /></div>
                            <div class="memberDetailsField"><label>Genre: </label>
                            	<select name="genre_name"> *
                                	<option value="blank">Select...</option>
                                    <option value="Fantasy">Fantasy</option>
                                </select> *
                            </div>
                            <div class="memberDetailsField"><label>New Genre: </label><input type="text" name="new_genre" /></div>
                            <div class="memberDetailsField"><label>Classification:</label>
                            	<select name="classification_name"> *
                                	<option value="blank">Select...</option>
                                    <option value="M">M</option>
                                </select> *
                            </div>
                            <div class="memberDetailsField"><label>New Classification: </label><input type="text" name="new_classification" /></div>
                        </fieldset>
                    </div>
                    <div class="controlPanelSection">
                        <fieldset>
                            <legend>Stars and Co Stars</legend>
                            <div class="memberDetailsField"><label>First star:</label>
                            	<select name="first_star_name">
                                	<option value="blank">Select...</option>
                                    <option value="Val Kilmer">Val Kilmer</option>
                                </select> *
                            </div>
                            <div class="memberDetailsField"><label>New First Star: </label><input type="text" name="new_first_star" /></div>
                            <div class="memberDetailsField"><label>Second Star:</label>
                            	<select name="second_star_name">
                                	<option value="blank">Select...</option>
                                    <option value="Val Kilmer">val Kilmer</option>
                                </select> *
                            </div>
                            <div class="memberDetailsField"><label>New Second Star: </label><input type="text" name="new_second_star" /></div>
                            <div class="memberDetailsField"><label>Third Star: </label>
                            	<select name="third_star_name">
                                	<option value="blank">Select...</option>
                                    <option value="Val Kilmer">Val Kilmer</option>
                                </select>
                            </div>
                            <div class="memberDetailsField"><label>New Third Star: </label><input type="text" name="new_third_star" /></div>
                            <div class="memberDetailsField"><label>First Costar</label>
                            	<select name="first_costar_name">
                                	<option value="blank">Select...</option>
                                    <option value="M">M</option>
                                </select>
                            </div>
                            <div class="memberDetailsField"><label>New First Costar: </label><input type="text" name="new_first_costar" /></div>
                            <div class="memberDetailsField"><label>Second Costar:</label>
                            	<select name="second_costar_name">
                                	<option value="blank">Select...</option>
                                    <option value="M">M</option>
                                </select>
                            </div>
                            <div class="memberDetailsField"><label>New Second Costar: </label><input type="text" name="new_second_costar" /></div>
                            <div class="memberDetailsField"><label>Third Costar:</label>
                            	<select name="third_costar_name">
                                	<option value="blank">Select...</option>
                                    <option value="M">M</option>
                                </select>
                            </div>
                            <div class="memberDetailsField"><label>New Third Costar: </label><input type="text" name="new_third_costar" /></div>
                        </fieldset>
                    </div>
                    <div class="controlPanelSection">
                        <fieldset>
                            <legend>Stock Information</legend>
                            <div class="memberDetailsField"><label>Rental Period: </label>
                                <select name="rental_period">
                                    <option value="3 Day">3 Day</option>
                                    <option value="Weekly">Weekly</option>
                                    <option value="Overnight">Overnight</option>
                                </select> *
                            </div>
                            <fieldset>
                            	<legend>DVD</legend>
                                <div class="memberDetailsField"><label>Rental Price: </label><input type="text" name="dvd_rental_price" /> *</div>
                                <div class="memberDetailsField"><label>Purchase Price: </label><input type="text" name="dvd_purchase_price" /> *</div>
                                <div class="memberDetailsField"><label>In-Stock: </label><input type="text" name="numDVD" /> *</div>
                                <div class="memberDetailsField"><label>Rented out: </label><input type="text" name="outDVD" /> *</div>
                            </fieldset>
                            <fieldset id="BluRayFieldSet">
                            	<legend>BluRay</legend>
                                <div class="memberDetailsField"><label>Rental Price: </label><input type="text" name="bluray_rental_price" /> *</div>
                                <div class="memberDetailsField"><label>Purchase Price: </label><input type="text" name="bluray_purchase_price" /> *</div>
                                <div class="memberDetailsField"><label>In-Stock: </label><input type="text" name="numBluRay" /> *</div>
                                <div class="memberDetailsField"><label>Rented out: </label><input type="text" name="numBluRayOut" /> *</div>
                            </fieldset>
                        </fieldset>
                    </div>
                </form>
                <input type="submit" class="controlPanelButton" name="submit_create" value="Create Movie" />
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