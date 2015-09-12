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
                	<h2 id="controlPanelHeading">Edit/Delete Member</h2>
                    <div id="editObjectSelectBox">
                        <form id="editObjectSelectForm">
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
                            <div class="memberDetailsField"><label>Surname: </label><input type="text" name="surname" /></div>
                            <div class="memberDetailsField"><label>Other Names: </label><input type="text" name="othername" /></div>
                            <div class="memberDetailsField"><label>Username: </label><input type="text" name="joinusername" disabled/></div>
                            <div class="memberDetailsField"><label>Password: </label><input type="text" name="userpass" /></div>
                            <div class="memberDetailsField"><label>Occupation: </label>
                                <select name="occupation">
                                    <option value="Student">Student</option>
                                   <option value="Manager">Manager</option>
                                   <option value="Healthcare">Medical worker</option>
                                   <option value="Trades">Trades worker</option>
                                   <option value="Educator">Education</option>
                                   <option value="Technician">Technician</option>
                                   <option value="Clerical">Clerical worker</option>
                                   <option value="Retail">Retail worker</option>
                                   <option value="Researcher">Researcher</option>
                                   <option value="Other">Other</option>
                                </select>
                            </div>
                            <div class="memberDetailsField"><label>Join date: </label><input type="text" value="2015-07-06" disabled/></div>
                        </fieldset>
                    </div>
                    <div class="controlPanelSection">
                        <fieldset>
                            <legend>Contact Details</legend>
                            <div class="memberDetailsField"><label>Contact Method: </label>
                                <select name="contactmethod">
                                    <option value="email">Email</option>
                                    <option value="landline">Lanline</option>
                                    <option value="mobile">Mobile</option>
                                </select>
                            </div>
                            <div class="memberDetailsField"><label>Email: </label><input type="email" name="email" /></div>
                            <div class="memberDetailsField"><label>Landline: </label><input type="text" name="phonenum" /></div>
                            <div class="memberDetailsField"><label>Mobile: </label><input type="text" name="mobilenum" /></div>
                        </fieldset>
                    </div>
                    <div class="controlPanelSection">
                        <fieldset>
                            <legend>Magazine</legend>
                            <div class="memberDetailsField"><label>Recieve Magazine: </label><input type="checkbox" name="magazine" checked/ ></div>
                            <div class="memberDetailsField"><label>Street Address: </label><input type="text" name="streetaddr" /></div>
                            <div class="memberDetailsField"><label>Suburb and State: </label><input type="text" name="suburbstate" /></div>
                            <div class="memberDetailsField"><label>Postcode: </label><input type="text" name="postcode" /></div>
                        </fieldset>
                    </div>
                </form>
                <input type="submit" class="controlPanelButton" value="Delete User" /><input type="submit" class="controlPanelButton" value="Update User" />
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