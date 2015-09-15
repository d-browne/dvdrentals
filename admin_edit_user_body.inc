<?php
    $member = $result->fetch_assoc(); // Get row data to variable member
    
    // Put button processing code here
?>

<form action="admin.php?action=edit_user&member_username=<?php echo $member['username'] ?>" method="POST">
    
    <div class="controlPanelSection">
        <fieldset>
            <legend>Member ID: <?php echo $member['member_id'] ?></legend>
            <div class="memberDetailsField"><label>Surname: </label><input type="text" name="surname" value="<?php echo $member['surname'] ?>" /></div>
            <div class="memberDetailsField"><label>Other Names: </label><input type="text" name="othername" value="<?php echo $member['other_name'] ?>"/></div>
            <div class="memberDetailsField"><label>Username: </label><input type="text" value="<?php echo $member['username'] ?>" disabled/></div>
            <input type="hidden" name="joinusername" value="<?php echo $member['username'] ?>" />
            <div class="memberDetailsField"><label>Password: </label><input type="text" name="userpass" value="<?php echo $member['password'] ?>"/></div>
            <div class="memberDetailsField"><label>Occupation: </label>
                <select name="occupation">
                    <option value="Student" <?php if ($member['occupation'] == 'Student') { echo 'selected=""'; } ?>>Student</option>
                    <option value="Manager" <?php if ($member['occupation'] == 'Manager') { echo 'selected=""'; } ?>>Manager</option>
                    <option value="Healthcare" <?php if ($member['occupation'] == 'Healthcare') { echo 'selected=""'; } ?>>Medical worker</option>
                    <option value="Trades" <?php if ($member['occupation'] == 'Trades') { echo 'selected=""'; } ?>>Trades worker</option>
                    <option value="Educator" <?php if ($member['occupation'] == 'Educator') { echo 'selected=""'; } ?>>Education</option>
                    <option value="Technician" <?php if ($member['occupation'] == 'Technician') { echo 'selected=""'; } ?>>Technician</option>
                    <option value="Clerical" <?php if ($member['occupation'] == 'Clerical') { echo 'selected=""'; } ?>>Clerical worker</option>
                    <option value="Retail" <?php if ($member['occupation'] == 'Retail') { echo 'selected=""'; } ?>>Retail worker</option>
                    <option value="Researcher" <?php if ($member['occupation'] == 'Researcher') { echo 'selected=""'; } ?>>Researcher</option>
                    <option value="Other" <?php if ($member['occupation'] == 'Other') { echo 'selected=""'; } ?>>Other</option>
                </select>
            </div>
            <div class="memberDetailsField"><label>Join date: </label><input type="text" value="<?php echo $member['join_date'] ?>" disabled/></div>
        </fieldset>
    </div>
    <div class="controlPanelSection">
        <fieldset>
            <legend>Contact Details</legend>
            <div class="memberDetailsField"><label>Contact Method: </label>
                <select name="contactmethod">
                    <option value="email" <?php if ($member['contact_method'] == 'email') { echo 'selected=""'; } ?>>Email</option>
                    <option value="landline" <?php if ($member['contact_method'] == 'landline') { echo 'selected=""'; } ?>>Lanline</option>
                    <option value="mobile" <?php if ($member['contact_method'] == 'mobile') { echo 'selected=""'; } ?>>Mobile</option>
                </select>
            </div>
            <div class="memberDetailsField"><label>Email: </label><input type="email" name="email" value="<?php echo $member['email'] ?>" /></div>
            <div class="memberDetailsField"><label>Landline: </label><input type="text" name="phonenum" value="<?php echo $member['landline'] ?>" /></div>
            <div class="memberDetailsField"><label>Mobile: </label><input type="text" name="mobilenum" value="<?php echo $member['mobile'] ?>" /></div>
        </fieldset>
    </div>
    <div class="controlPanelSection">
        <fieldset>
            <legend>Magazine</legend>
            <div class="memberDetailsField"><label>Recieve Magazine: </label><input type="checkbox" name="magazine"  value="yes" <?php if ($member['magazine'] == 1) { echo 'checked'; } ?> /></div>
            <div class="memberDetailsField"><label>Street Address: </label><input type="text" name="streetaddr" value="<?php echo $member['street'] ?>" /></div>
            <div class="memberDetailsField"><label>Suburb and State: </label><input type="text" name="suburbstate" value="<?php echo $member['suburb'] ?>" /></div>
            <div class="memberDetailsField"><label>Postcode: </label><input type="text" name="postcode" value="<?php echo $member['postcode'] ?>" /></div>
        </fieldset>
    </div>
    <input type="submit" class="controlPanelButton" name="submit" value="Update User" /><input type="submit" class="controlPanelButton" name="submit" value="Remove User" />
</form>