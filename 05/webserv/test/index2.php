<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple Form</title>
</head>
<body>
    <h1>Simple Form</h1>
    
    <?php
    // Initialize variables to hold form data
    $name = "";
    $email = "";

    // Check if the form is submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Retrieve form data
        $name = $_POST["name"];
        $email = $_POST["email"];

        // Validate form data
        $errors = array();
        if (empty($name)) {
            $errors[] = "Name is required";
        }
        if (empty($email)) {
            $errors[] = "Email is required";
        } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $errors[] = "Invalid email format";
        }

        // If there are no errors, process the form data
        if (empty($errors)) {
            // Process the form (For this example, we're just echoing the submitted data)
            echo "<p>Thank you for submitting the form!</p>";
            echo "<p>Name: $name</p>";
            echo "<p>Email: $email</p>";
        } else {
            // If there are errors, display them to the user
            echo "<ul>";
            foreach ($errors as $error) {
                echo "<li>$error</li>";
            }
            echo "</ul>";
        }
    }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        <label for="name">Name:</label><br>
        <input type="text" id="name" name="name" value="<?php echo htmlspecialchars($name); ?>"><br>
        
        <label for="email">Email:</label><br>
        <input type="email" id="email" name="email" value="<?php echo htmlspecialchars($email); ?>"><br>
        
        <input type="submit" value="Submit">
    </form>
</body>
</html>


