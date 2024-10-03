#!/usr/bin/php

<?php
if ($_SERVER['REQUEST_METHOD'] == 'GET') {
    if ($_SERVER['PATH_INFO'] == "/users/list")
    {
        echo "Status: 200 OK\r\n";  # HTTP status code for success
        echo "Content-Type: text/plain";  # Set content type as plain text
        echo "\r\n\r\n";
        echo "User1, User2, User3";
    }
   else if ($_SERVER['PATH_INFO'] == "/courses/list")
    {
        echo "Status: 200 OK\r\n";  # HTTP status code for success
        echo "Content-Type: text/plain";  # Set content type as plain text
        echo "\r\n\r\n";
        echo "Course101, Course102, Course103";
    }
    else
    {
        echo "Status: 200 OK\r\n";  # HTTP status code for success
        echo "Content-Type: text/plain";  # Set content type as plain text
        echo "\r\n\r\n";
        echo "Normal GET request received";
    }
}
?>