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
                	Movie Zone - Booking
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
                
                   <div id="loginBox">
                   		<fieldset id="loginFieldSet">
                        	<legend>Login</legend>
                            <form>
                            	<div class="loginField"><label>Username: </label>
                                	<span class="inputSpan"><input type="text" name="userName" placeholder="Username" required /></span>
                                </div>
                                <div class="loginField"><label>Password: </label>
                                	<span class="inputSpan"><input type="text" name="password" placeholder="Password" required />
                                </div>
                                <input id="loginButton" type="submit" value="Login" />
                            </form>
                        </fieldset>
                   </div>
                   <div id="infoBox">Not registered yet? Click <a href="join.html">here</a> to join.</div>
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