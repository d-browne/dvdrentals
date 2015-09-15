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
	<script type="text/javascript" src="scripts/formValidate.js"></script>
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
                            
                                
                            
				<h2 id="mainHeader">Join us now and reserve your DVD rentals!</h2>
                                
                                <?php
                                    //If the access method was post then process the form
                                    if(isset($_POST['submit'])){

                                       // For DEBUG
                                       //print "<h2>POST result</h2>";
                                       //$formdata = $_POST;
                                       //foreach ($formdata as $element => $value)
                                       //  print "$element : $value <br />\n";

                                       print "<h3>Status</h3>";
                                       include_once 'validateUser.php';
                                       if(ValidateUserForm($_POST)) { // all entered data good
                                          include_once 'createUser.php';
                                          $queryResult = createUser($_POST); // add time to this    
                                          //See if the creation worked.
                                          if($queryResult['succeeded']){
                                             //Success message
                                             print "<p class = 'centre'>Congratulations $_POST[othername] 
                                                    you have successfully signed up at the DVD Emporium and can 
                                                    now book movies!<br><a href='moviezone.php'>Would you like to
                                                    go to the MovieZone page and Log In?</a></p>";

                                          }
                                          else {
                                             //Failure message
                                             print "<p class = 'centre'>There was a database failure while 
                                                   creating your user account. Please contact the site administrator.
                                                   </p> <p class = 'centre'>Error message: $queryResult[error]</p>";
                                          }
                                       } 
                                    }         
                                 ?>
                                
					<form action="join.php" method="post" id="joinForm">

						<div id="personalDetailsSection">
							<h3>Personal details</h3>
							<label>Surname:</label>
							<input id="surname" type="text" maxlength="50" name="surname" 
							placeholder="Enter Surname" pattern="[^\d\s]{2,50}" required/>
							<span class="compulsoryStar">x</span>
							<br/>
							<label>Other names:</label>
							<input id="otherNames" type="text" maxlength="60" name="othername" placeholder="Enter other names" pattern="[^\d]{2,60}" required/><span class="compulsoryStar">x</span>
							<br />
							<label>Mobile:</label>
							<input id="mobile" type="text" maxlength="50" name="mobilenum" placeholder="0[4 or 5]XX XXX XXX"
							pattern="0[4-5]\d{2} \d{3} \d{3}"/><span id="mobileStar" class="compulsoryStar">x</span>
							<br />
							<label>Landline:</label>
							<input id="landLine" type="text" maxlength="50" name="phonenum" placeholder="(0[2,3,6,7,8,or 9]) XXXXXXXX" pattern="\(0[2,3,6,7,8,9]\)\s\d\d\d\d\d\d\d\d" /><span id="landlineStar" class="compulsoryStar">x</span>
							<br />
							<label>Email:</label>
							<input id="email" type="email" maxlength="50" name="email" placeholder="Enter valid email" required/><span id="emailStar" class="compulsoryStar">x</span>
							<br />
							<label>Receve Magazine:</label>
							<input id="recieveMagazine" type="checkbox" name="magazine" checked="checked" /><span class="compulsoryStar">x</span>
							<br />
							<label>Street Address:</label>
							<input id="streetAddress" type="text" maxlength="50" name="streetaddr" placeholder="Street number, name" /><span id="streetStar" class="compulsoryStar">x</span>
							<br />
							<label>State:</label>
							<input id="sate" type="text" maxlength="50" name="suburbstate" placeholder="Suburb, State"/><span id="stateStar" class="compulsoryStar">x</span>
							<br />
							<label>Post Code:</label>
							<input id="postCode" type="text" maxlength="50" name="postcode" placeholder="XXXX" pattern="\d{4}"/><span id="postStar" class="compulsoryStar">x</span>
							<br />
							<label>Occupation:</label>
							<select id="occupation" name="occupation">
								<option value="blank" disabled>Select... </option>                        
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
							</select><span class="compulsoryStar">x</span>
							<br/>
							<label>Preffered Contact:</label>
							Mobile: 	<input id="contactMobile" type="radio" value="contactMobile" name="contactmethod">
							Email:		<input id="contactEmail" type="radio" value="contactEmail" checked="checked" name="contactmethod">
							Landline: 	<input id="contactLandline" type="radio" value="contactLandline" name="contactmethod">

							<input id="joinDate" name="joinDate" type="hidden" value="unset">

							<!-- set hidden filed join date to current date as YYYY-MM-DD -->
							<script type="text/javascript">
							{
								joinDate.value = generateDateString();
							}
								
							</script>

						</div>

						<div id="userDetailsSection">

							<h3>User details</h3>

							<label>Username:</label>
							<input id="userName" type="text" maxlength="50" name="joinusername" placeholder="6 chars, no whitespace" pattern="[^\s]{6,}" required/><span class="compulsoryStar">x</span>
							<br />
							<label>Password:</label>
							<input id="passWord" type="password" maxlength="10" name="userpass" placeholder="6 to 10 chars" required/><span class="compulsoryStar">x - 6-10 chars and contain least one uppercase, lowercase, number and special character</span>
							<br />
							<label>Verify password:</label>
							<input id="verifyPassWord" type="password" maxlength="10" name="verifypass" placeholder="type password again" required/><span class="compulsoryStar">x</span>
							<br /><br />
							<input id="submit" type="submit" value="Submit" name="submit" onClick="return submitButtonClicked()" >
							<input id="resetButton" type="reset" onClick="defaultContacts()">

							<p id="compulsoryStarHelp">x = compulsory field</p>

						</div>

					</form>
					
					<!-- Script to hide compulsory stars -->
					<script type ="text/javascript">
						defaultContacts();
					</script>

					<!-- Script to register form event handlers -->
					<script type ="text/javascript" src ="scripts/formEvents.js"></script>


			</div>



			<footer>
				<div class="horizontalRule"></div>

				<p id="copyright">Copyright © 2015 <a href="http://infotech.scu.edu.au/~dbrown31/">Dominic Browne - Infotech Site</a></p>
			</footer>

		</div>



	</div>

	

</body>
</html>