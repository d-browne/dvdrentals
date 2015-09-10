function defaultContacts()
{
	//Hide mobile and landline compulsory star
	//don't hide email because it's default
	mobileStar.style.visibility = "hidden";
	landlineStar.style.visibility = "hidden";
	emailStar.style.visibility = "visible";
}

function contactChange(event)
{
	// Hide all the red stars for the contact methods
	emailStar.style.visibility = "hidden";
	mobileStar.style.visibility = "hidden";
	landlineStar.style.visibility = "hidden";

	//Turn on the appropriate compulsory star
	switch (event.currentTarget.value)
	{
		case "contactMobile": 
			mobileStar.style.visibility = "visible";
			break;
		case "contactEmail":
			emailStar.style.visibility = "visible";
			break;
		case "contactLandline": 
			landlineStar.style.visibility = "visible";
			break;

	}
}

function changeRecieveMagazine(event)
{
	if (recieveMagazine.checked == true)
	{
		enableAddressFields(true);
	}
	else
	{
		enableAddressFields(false);
	}
}

function enableAddressFields(enable)
{
	if (enable == true)
	{
		streetStar.style.visibility = "visible";
		stateStar.style.visibility = "visible";
		postStar.style.visibility = "visible";
	}
	else
	{
		streetStar.style.visibility = "hidden";
		stateStar.style.visibility = "hidden";
		postStar.style.visibility = "hidden";
	}
}

function passwordIsValid()
{
	passwordString = passWord.value;
	
	var matches = passwordString.match(/\d/g);
	if (matches == null)
	{
		// No number found, invalid password
		alert("Your password must contain a number!");
		return false;
	}

	var matches = passwordString.match(/[A-Z]/g);
	if (matches == null)
	{
		// No captial found, invalid password
		alert("Your password must contain a capital letter!");
		return false;
	}

	var matches = passwordString.match(/[a-z]/g);
	if (matches == null)
	{
		// No lower case found, invalid password
		alert("Your password must contain a lower case letter!");
		return false;
	}

	var matches = passwordString.match(/\s/g);
	if (matches != null)
	{
		// Whitespace character found, invalid password
		alert("Your password must not contain a whitespace character!");
		return false;
	}

	// Password appears to be valid, return true
	return true;
}

function submitButtonClicked()
{
	// check if password is invalid
	if (passwordIsValid() != true)
	{
		// Show error to user
		alert("Invalid password: Your password must contain at least one uppercase letter, lowercase letter and one special character with no whitespace");
		
		//return false and don't submit form
		return false;
	}

	//Check if passwords match
	if (checkPasswordsMatch())
	{
		return true; // Return true submit form
	}
	else
	{
		// Display error message to user
		alert("Warning your passwords don't match!");
		return false; // return false don't submit form
	}
}

// Function to check if passwords match
function checkPasswordsMatch()
{
	if (passWord.value == verifyPassWord.value)
	{
		//Passwords match return true
		return true;
	}
	else
	{
		//Passwords don't match return false
		return false;
	}
}

function padNumber(number)
{
	// This function addes a leading zero to any number less than 10
	if (number < 10)
		return "0" + number;
}

function generateDateString()
{
	// Returns a date string as YYYY-MM-DD
	var dateObject = new Date();
	var year = dateObject.getFullYear();
	var month = dateObject.getMonth()+1;
	var day = dateObject.getUTCDate();

	return year + '-' + padNumber(month) + '-' + padNumber(day);
}