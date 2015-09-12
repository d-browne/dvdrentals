<?php
    $movie = $result->fetch_assoc(); // Get movie values into movie variable
    
    // Code here to handle post
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
    <input type="submit" class="controlPanelButton" name="submit_delete" value="Remove Movie" /><input type="submit" class="controlPanelButton" name="submit_update" value="Update Movie" />
</form>