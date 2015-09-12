<h2>Welcome <?php echo $_SESSION['adminUserName']; ?></h2>
<div id="adminControlBox">
    <fieldset id="adminControlsFieldSet">
        <legend>Admin Controls</legend>
        <div class="adminControl" id="editUserControl">
            <a href="admin.php?action=edit_user">
                <div class="adminControlIcon" id="editUserIcon"></div>
                <div class="adminControlCaption">Edit/Remove Member</div>
            </a>
        </div>
        <div class="adminControl" id="addUserControl">
            <a href="join.html">
                <div class="adminControlIcon" id="addUserIcon"></div>
                <div class="adminControlCaption">New user</div>
            </a>
        </div>
        <div class="adminControl" id="addMovieControl">
            <a href="admin.php?action=new_movie">
                <div class="adminControlIcon" id="addMovieIcon"></div>
                <div class="adminControlCaption">New Movie</div>
            </a>
        </div>
        <div class="adminControl" id="editMovieControl">
            <a href="admin.php?action=edit_movie">
                <div class="adminControlIcon" id="editMovieIcon"></div>
                <div class="adminControlCaption">Edit/Remove Movie</div>
            </a>
        </div>
        <div class="adminControl" id="logoutUserControl">
            <a href="admin.php?action=logout">
                <div class="adminControlIcon" id="logoutIcon"></div>
                <div class="adminControlCaption">Logout of control panel</div>
            </a>
        </div>
    </fieldset>
</div>
