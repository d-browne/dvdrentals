<?php
    session_cache_limiter('private_no_expire');
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
    
    // Initialize admin logged in variable to false
    if (!isset($_SESSION['adminLoggedIn'])) {
        $_SESSION['adminLoggedIn'] = false;
    }
?>