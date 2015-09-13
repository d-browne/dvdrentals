<form>
    <div class="controlPanelSection">
        <fieldset>
            <legend>New Movie</legend>
            <div class="memberDetailsField"><label>Title: </label><input type="text" name="movie_title" /> *</div>
            <div class="memberDetailsField"><label>Year: </label><input type="text" name="movie_year" /> *</div>
            <div class="memberDetailsField"><label>Tag Line: </label><input type="text" name="movie_tagline" /> *</div>
            <div class="memberDetailsField"><label>Plot: </label><textarea maxlength="256" cols="60" rows="4" name="movie_plot"></textarea> *</div>
            <div class="memberDetailsField"><label>Poster: </label><input type="file" name="movie_poster" accept="image/*"> *</div>
            <div class="memberDetailsField"><label>Director: </label>
                <select name="director_name"> 
                    <option value="blank">Select...</option>
                    <option value="Val Kilmer">Val Kilmer</option>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New Director: </label><input type="text" name="new_director" /></div>
            <div class="memberDetailsField"><label>Studio:</label>
                <select name="studio_name"> 
                    <option value="blank">Select...</option>
                    <option value="Marvel">Marvel</option>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New Studio: </label><input type="text" name="new_studio" /></div>
            <div class="memberDetailsField"><label>Genre: </label>
                <select name="genre_name"> *
                    <option value="blank">Select...</option>
                    <option value="Fantasy">Fantasy</option>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New Genre: </label><input type="text" name="new_genre" /></div>
            <div class="memberDetailsField"><label>Classification:</label>
                <select name="classification_name"> *
                    <option value="blank">Select...</option>
                    <option value="M">M</option>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New Classification: </label><input type="text" name="new_classification" /></div>
        </fieldset>
    </div>
    <div class="controlPanelSection">
        <fieldset>
            <legend>Stars and Co Stars</legend>
            <div class="memberDetailsField"><label>First star:</label>
                <select name="first_star_name">
                    <option value="blank">Select...</option>
                    <option value="Val Kilmer">Val Kilmer</option>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New First Star: </label><input type="text" name="new_first_star" /></div>
            <div class="memberDetailsField"><label>Second Star:</label>
                <select name="second_star_name">
                    <option value="blank">Select...</option>
                    <option value="Val Kilmer">val Kilmer</option>
                </select> *
            </div>
            <div class="memberDetailsField"><label>New Second Star: </label><input type="text" name="new_second_star" /></div>
            <div class="memberDetailsField"><label>Third Star: </label>
                <select name="third_star_name">
                    <option value="blank">Select...</option>
                    <option value="Val Kilmer">Val Kilmer</option>
                </select>
            </div>
            <div class="memberDetailsField"><label>New Third Star: </label><input type="text" name="new_third_star" /></div>
            <div class="memberDetailsField"><label>First Costar</label>
                <select name="first_costar_name">
                    <option value="blank">Select...</option>
                    <option value="M">M</option>
                </select>
            </div>
            <div class="memberDetailsField"><label>New First Costar: </label><input type="text" name="new_first_costar" /></div>
            <div class="memberDetailsField"><label>Second Costar:</label>
                <select name="second_costar_name">
                    <option value="blank">Select...</option>
                    <option value="M">M</option>
                </select>
            </div>
            <div class="memberDetailsField"><label>New Second Costar: </label><input type="text" name="new_second_costar" /></div>
            <div class="memberDetailsField"><label>Third Costar:</label>
                <select name="third_costar_name">
                    <option value="blank">Select...</option>
                    <option value="M">M</option>
                </select>
            </div>
            <div class="memberDetailsField"><label>New Third Costar: </label><input type="text" name="new_third_costar" /></div>
        </fieldset>
    </div>
    <div class="controlPanelSection">
        <fieldset>
            <legend>Stock Information</legend>
            <div class="memberDetailsField"><label>Rental Period: </label>
                <select name="rental_period">
                    <option value="3 Day">3 Day</option>
                    <option value="Weekly">Weekly</option>
                    <option value="Overnight">Overnight</option>
                </select> *
            </div>
            <fieldset>
                <legend>DVD</legend>
                <div class="memberDetailsField"><label>Rental Price: </label><input type="text" name="dvd_rental_price" /> *</div>
                <div class="memberDetailsField"><label>Purchase Price: </label><input type="text" name="dvd_purchase_price" /> *</div>
                <div class="memberDetailsField"><label>In-Stock: </label><input type="text" name="numDVD" /> *</div>
                <div class="memberDetailsField"><label>Rented out: </label><input type="text" name="outDVD" /> *</div>
            </fieldset>
            <fieldset id="BluRayFieldSet">
                <legend>BluRay</legend>
                <div class="memberDetailsField"><label>Rental Price: </label><input type="text" name="bluray_rental_price" /> *</div>
                <div class="memberDetailsField"><label>Purchase Price: </label><input type="text" name="bluray_purchase_price" /> *</div>
                <div class="memberDetailsField"><label>In-Stock: </label><input type="text" name="numBluRay" /> *</div>
                <div class="memberDetailsField"><label>Rented out: </label><input type="text" name="numBluRayOut" /> *</div>
            </fieldset>
        </fieldset>
    </div>
    <input type="reset" class="controlPanelButton" value="Reset" /><input type="submit" class="controlPanelButton" name="submit_create" value="Create Movie" />
</form>