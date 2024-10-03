#!/usr/local/bin/python3

import cgi
import os

# Mimic database queries for users and courses
def get_users():
    return ["User1", "User2", "User3"]

def get_courses():
    return ["Course1", "Course2", "Course3"]

# Function to handle GET requests
def handle_get_request():
    path_info = os.environ["PATH_INFO"]

    if path_info == "/users/list":
        users = get_users()
        print("Content-Type: text/plain")
        print()
        print("Users list here:", ", ".join(users))
    elif path_info == "/courses/list":
        courses = get_courses()
        print("Content-Type: text/plain")
        print()
        print("Courses list here:", ", ".join(courses))
    else:
        print("Content-Type: text/plain")
        print()
        print("Normal GET request received")

# Main CGI entry point
if __name__ == "__main__":
    print("Status: 200 OK", end="\r\n")  # HTTP status code for success
    print("Content-Type: text/plain")  # Set content type as plain text
    print("\r\n\r\n")

    if os.environ["REQUEST_METHOD"] == "GET":
        handle_get_request()
