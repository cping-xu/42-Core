<?php

ob_start();

// File paths for users and courses
$USERS_FILE = "test/users.txt";
$COURSES_FILE = "test/courses.txt";

// Function to parse field from HTTP request
function parse_field_from_http_request($request, $field_name) {
    if (strpos($request, 'name="' . $field_name . '"') !== false) {
        $start_index = strpos($request, 'name="' . $field_name . '"') + strlen('name="' . $field_name . '"' . "\r\n\r\n");
        $end_index = strpos($request, "\r\n", $start_index);
        // echo substr($request, $start_index, $end_index - $start_index);
        return substr($request, $start_index, $end_index - $start_index);
    }
    return null;
}

// Function to read users from file
function read_users() {
    return file($GLOBALS['USERS_FILE'], FILE_IGNORE_NEW_LINES);
}

// Function to read courses from file
function read_courses() {
    return file($GLOBALS['COURSES_FILE'], FILE_IGNORE_NEW_LINES);
}

// Function to handle GET requests
function handle_get_request() {
    $path_info = $_SERVER["PATH_INFO"];

    if ($path_info == "/users/list") {
        $users = read_users();
        header("Content-Type: text/plain");
        echo implode(", ", $users);
    } elseif ($path_info == "/courses/list") {
        $courses = read_courses();
        header("Content-Type: text/plain");
        echo implode(", ", $courses);
    } else {
        header("Content-Type: text/plain");
        echo "Normal GET request received. Boring, right?";
    }
}

// Function to handle POST requests
function handle_post_request($http_request) {
    $path_info = $_SERVER["PATH_INFO"];

    if ($path_info == "/users/list") {
        $username = parse_field_from_http_request($http_request, "username");
        file_put_contents($GLOBALS['USERS_FILE'], $username . "\n", FILE_APPEND);
        $confirmations = ["User added successfully!", "Hooray! You're now part of our system!", "Welcome aboard, $username!"];
        header("Content-Type: text/plain");
        echo $confirmations[array_rand($confirmations)];
    } elseif ($path_info == "/courses/list") {
        $course = parse_field_from_http_request($http_request, "course");
        file_put_contents($GLOBALS['COURSES_FILE'], $course . "\n", FILE_APPEND);
        $confirmations = ["Course added successfully!", "New course unlocked!", "Congratulations! You've just enrolled in $course!"];
        header("Content-Type: text/plain");
        echo $confirmations[array_rand($confirmations)];
    } else {
        header("Content-Type: text/plain");
        echo "Invalid request";
    }
}

// Main entry point
echo "Status: 200 OK\r\n";
echo "Content-Type: text/plain\r\n\r\n";


$request_method = $_SERVER["REQUEST_METHOD"];
if ($request_method === "GET") {
    handle_get_request();
} elseif ($request_method === "POST") {
    $content = $_SERVER["REQUEST"];
    handle_post_request($content);
}

ob_flush();
?>
