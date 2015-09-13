<?php
    $movie = $result->fetch_assoc(); // Get movie values into movie variable
    
    // Check if delete button clicked
    if (isset($_POST['submit_delete']))
    {
        // query database for filename of movie image
        $query = "SELECT thumbpath FROM movie WHERE movie_id ='".$movie['movie_id']."'";
        $result = $dataConnection->query($query);
        $row = $result->fetch_assoc();
        $imagePath = 'images/movie_images/'.$row['thumbpath'];
        
        // Delete image
        unlink($imagePath);
        
        // query DELETE movie from databse
        $query = "DELETE FROM movie WHERE movie_id ='".$movie['movie_id']."'";
        $dataConnection->query($query);
        
        echo '<div id="resultsTag">Deleted movie '.$movie['title'].'!</div><br><br>';
        echo '<script type="text/javascript">document.location = "admin.php?action=edit_movie";</script>"';
        die(); // Terminate script execution 
    }
    
    // Check if edit button pressed
    if (isset($_POST['submit_update']))
    {
        $rental_period = mysqli_real_escape_string($dataConnection, $_POST['rental_period']);
        $dvd_rental_price = mysqli_real_escape_string($dataConnection, $_POST['dvd_rental_price']);
        $dvd_purchase_price = mysqli_real_escape_string($dataConnection, $_POST['dvd_purchase_price']);
        $numDVD = mysqli_real_escape_string($dataConnection, $_POST['numDVD']);
        $numDVDout = mysqli_real_escape_string($dataConnection, $_POST['numDVDout']);
        $bluray_rental_price = mysqli_real_escape_string($dataConnection, $_POST['bluray_rental_price']);
        $bluray_purchase_price = mysqli_real_escape_string($dataConnection, $_POST['bluray_purchase_price']);
        $numBluRay = mysqli_real_escape_string($dataConnection, $_POST['numBluRay']);
        $numBluRayOut = mysqli_real_escape_string($dataConnection, $_POST['numBluRayOut']);
        
        $all_ok = true;
        
        if (!isValidRentalPeriod($rental_period))
            $all_ok = false;
        
        if (!isValidPrice($dvd_rental_price))
            $all_ok = false;
        
        if (!isValidPrice($dvd_purchase_price))
            $all_ok = false;
        
        if (!isValidStockQuantity($numDVD))
            $all_ok = false;
        
        if (!isValidStockQuantity($numDVDout))
            $all_ok = false;
        
        if (!isValidPrice($bluray_rental_price))
            $all_ok = false;
        
        if (!isValidPrice($bluray_purchase_price))
            $all_ok = false;
        
        if (!isValidStockQuantity($numBluRay))
            $all_ok = false;
        
        if (!isValidStockQuantity($numBluRayOut))
            $all_ok = false;
        
        // If all fields validate properly
        if ($all_ok)
        {
            // Query to update values in database
            $query = "UPDATE movie SET rental_period='".(float)$rental_period."', 
                DVD_rental_price='".(float)$dvd_rental_price."',
                DVD_purchase_price='".(float)$dvd_purchase_price."', 
                numDVD='".(int)$numDVD."', 
                numDVDout='".(int)$numDVDout."', 
                BluRay_rental_price='".(float)$bluray_rental_price."', 
                BluRay_purchase_price='".(float)$bluray_purchase_price."', 
                numBluRay='".(int)$numBluRay."', 
                numBluRayOut='".(int)$numBluRayOut."'
                WHERE movie_id = '".(int)$movie['movie_id']."'";
            //Execute query
            $dataConnection->query($query);
            
            echo '<script type="text/javascript">document.location = "admin.php?action=edit_movie&movie_title='.$movie['title'].'";</script>"';
        }
    }
    
    // Function to check if valid stock quantity
    // must be a number
    function isValidStockQuantity($quantity)
    {
        // Return true if value integer
        if (is_numeric($quantity))
        {
            return true;
        }
        // Not integer return false
        return false;
    }
    
    // Function to check if valid price
    // must be a number
    function isValidPrice($price) 
    {
        // return true if valid floating point number
        if (is_numeric($price))
        {
            return true;
        }
        
        // Not a valid float, return false
        return false;
    }
    
    // Function to check if valid rental period
    // Must be '3 Day', 'Weekly' or 'Overnight'
    function isValidRentalPeriod($rental_period)
    {
        $allowed_values = array('3 Day', 'Weekly', 'Overnight');
        
        // Check if rental period is an allowed value
        $isValid = in_array($rental_period, $allowed_values);
        if ($isValid)
        {
            return true;
        }
        
        return false; // Rental period not allowed
    }
?>

<form action="admin.php?action=edit_movie&movie_title=<?php echo $movie['title']; ?>" method="post">
    <div class="controlPanelSection">
        <fieldset>
            <legend>Movie Information:</legend>
            <div class="memberDetailsField"><label>Movie ID: </label><input type="text" name="movid_id" value="<?php echo $movie['movie_id']; ?>" disabled/></div>
            <div class="memberDetailsField"><label>Title: </label><input type="text" name="movie_title" value="<?php echo $movie['title']; ?>" disabled/></div>
            <div class="memberDetailsField"><label>Year: </label><input type="text" name="movie_year" value="<?php echo $movie['year']; ?>" disabled/></div>
            <div class="memberDetailsField"><label>Tag Line: </label><input type="text" name="movie_tagline" value="<?php echo $movie['tagline']; ?>" disabled/></div>
        </fieldset>
    </div>
    <div class="controlPanelSection">
        <fieldset>
            <legend>Stock Information</legend>
            <div class="memberDetailsField"><label>Rental Period: </label>
                <select name="rental_period">
                    <option value="3 Day" <?php if ($movie['rental_period'] == '3 Day') { echo 'selected=""'; } ?>>3 Day</option>
                    <option value="Weekly" <?php if ($movie['rental_period'] == 'Weekly') { echo 'selected=""'; } ?>>Weekly</option>
                    <option value="Overnight" <?php if ($movie['rental_period'] == 'Overnight') { echo 'selected=""'; } ?>>Overnight</option>
                </select>
            </div>
            <fieldset>
                <legend>DVD</legend>
                <div class="memberDetailsField"><label>Rental Price: </label><input type="text" name="dvd_rental_price" value="<?php echo $movie['DVD_rental_price']; ?>" /></div>
                <div class="memberDetailsField"><label>Purchase Price: </label><input type="text" name="dvd_purchase_price" value="<?php echo $movie['DVD_purchase_price']; ?>" /></div>
                <div class="memberDetailsField"><label>In-Stock: </label><input type="text" name="numDVD" value="<?php echo $movie['numDVD']; ?>" /></div>
                <div class="memberDetailsField"><label>Rented out: </label><input type="text" name="numDVDout" value="<?php echo $movie['numDVDout']; ?>" /></div>
            </fieldset>
            <fieldset id="BluRayFieldSet">
                <legend>BluRay</legend>
                <div class="memberDetailsField"><label>Rental Price: </label><input type="text" name="bluray_rental_price" value="<?php echo $movie['BluRay_rental_price']; ?>" /></div>
                <div class="memberDetailsField"><label>Purchase Price: </label><input type="text" name="bluray_purchase_price" value="<?php echo $movie['BluRay_purchase_price']; ?>" /></div>
                <div class="memberDetailsField"><label>In-Stock: </label><input type="text" name="numBluRay" value="<?php echo $movie['numBluRay']; ?>" /></div>
                <div class="memberDetailsField"><label>Rented out: </label><input type="text" name="numBluRayOut" value="<?php echo $movie['numBluRayOut']; ?>" /></div>
            </fieldset>
        </fieldset>
    </div>
    <input type="submit" class="controlPanelButton" name="submit_update" value="Update Movie" /><input type="submit" class="controlPanelButton" name="submit_delete" value="Remove Movie" />
</form>