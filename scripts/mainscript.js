function greetUser()
{
	alert("Welcome to the Kings Music Store - Newsletter Signup");
}

function clearForm()
{
	//Reset the from
	document.getElementById("newsletterForm").reset();
}

function validateInput()
{
	//This function checks to see if the firstname lastname and email were entered

	//Get value of firstName
	var firstName = document.getElementById("firstName").value;
	//Check if firstname is empty
	if (firstName==null || firstName=="")
	{
		//Complain and return false
		alert("You must enter your first name, you didn't forget it did you?");
		return false;
	}

	//get value of lastName
	var lastName = document.getElementById("lastName").value;
	//Check if lastname is empty
	if (lastName==null || lastName=="")
	{
		//Complain and return false
		alert("You must enter your last name silly.");
		return false;
	}

	//get the value of the emailAddress
	var emailAddress = document.getElementById("emailAddress").value;
	//check if email address is empty
	if (emailAddress==null || emailAddress=="")
	{
		//Complain the return flase
		alert("You need to enter you email address, otherwise how are we to know where to send your newsletter?");
		return false;
	}

}