// This script creates the event listeners on the join page

//Change contact
joinForm.contactEmail.addEventListener("change", contactChange);
joinForm.contactMobile.addEventListener("change", contactChange);
joinForm.contactLandline.addEventListener("change", contactChange);

//Recieve magazine checkbox changed
joinForm.recieveMagazine.addEventListener("change", changeRecieveMagazine);