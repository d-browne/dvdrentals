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
                	<h2>Edit/Delete Member</h2>
                    <form>
                    	<select>
                        	<option disabled="" selected="" value="">Select member...</option>
                            <option>John Doe</option>
                        </select>
                        <input type="submit" value="Edit Member">
                    </form>
                </div>
                <form>
                    <div class="controlPanelSection">
                        <fieldset>
                            <legend>Member ID: 22</legend>
                            <div class="memberDetailsField"><label>Surname: </label><input type="text" value="Armstrong" /></div>
                            <div class="memberDetailsField"><label>Other Names: </label><input type="text" value="Bruce" /></div>
                            <div class="memberDetailsField"><label>Username: </label><input type="text" value="BruceA" disabled/></div>
                            <div class="memberDetailsField"><label>Password: </label><input type="text" value="#1Bruce" /></div>
                            <div class="memberDetailsField"><label>Occupation: </label>
                                <select>
                                    <option>Student</option>
                                    <option>Manager</option>
                                    <option>Medical Worker</option>
                                    <option>Trades Worker</option>
                                    <option>Education</option>
                                    <option>Technician</option>
                                    <option>Clerical Worker</option>
                                    <option>Retail Worker</option>
                                    <option>Researcher</option>
                                    <option>Other...</option>
                                </select>
                            </div>
                            <div class="memberDetailsField"><label>Join date: </label><input type="text" value="2015-07-06" disabled/></div>
                        </fieldset>
                    </div>
                    <div class="controlPanelSection">
                        <fieldset>
                            <legend>Contact Details</legend>
                            <div class="memberDetailsField"><label>Contact Method: </label>
                                <select>
                                    <option>Email</option>
                                    <option>Lanline</option>
                                    <option>Mobile</option>
                                </select>
                            </div>
                            <div class="memberDetailsField"><label>Email: </label><input type="email" value="bruce.armstrong@scu.edu.au" /></div>
                            <div class="memberDetailsField"><label>Landline: </label><input type="text" value="" /></div>
                            <div class="memberDetailsField"><label>Mobile: </label><input type="text" value="" /></div>
                        </fieldset>
                    </div>
                    <div class="controlPanelSection">
                        <fieldset>
                            <legend>Magazine</legend>
                            <div class="memberDetailsField"><label>Email: </label><input type="checkbox" checked/ ></div>
                            <div class="memberDetailsField"><label>Street Address: </label><input type="text" value="" /></div>
                            <div class="memberDetailsField"><label>Postcode: </label><input type="text" value="" /></div>
                        </fieldset>
                    </div>
                </form>
			</div>

			<footer>
				<div class="horizontalRule"></div>

				<p id="copyright">Copyright © 2015 <a href="http://infotech.scu.edu.au/~dbrown31/">Dominic Browne - Infotech Site</a></p>
			</footer>

		</div>


	</div>

	

</body>
</html>