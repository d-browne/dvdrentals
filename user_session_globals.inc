<?php
    session_start();
    
    // Set logged in flag to false if not yet set
    if (!isset($_SESSION['isLoggedIn'])) {
        $_SESSION['isLoggedIn'] = false;
    }
    
    // Session variable to track number of movies in cart
    if (!isset($_SESSION['numberInCart'])) {
        $_SESSION['numberInCart'] = 0;
    }
    
    if (!isset($_SESSION['cartMovies'])) {
        $_SESSION['cartMovies'] = array();
    }
?>