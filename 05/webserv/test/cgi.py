import os
import random
import sys

# File paths for users and courses
USERS_FILE = "test/users.txt"
COURSES_FILE = "test/courses.txt"

# Function to parse field from HTTP request
def parse_field_from_http_request(request, field_name):
    if f'name="{field_name}"' in request:
        start_index = request.index(f'name="{field_name}"') + len(f'name="{field_name}"\r\n\r\n')
        end_index = request.index('\r\n', start_index)
        return request[start_index:end_index]
    return None

# Function to read users from file
def read_users():
    with open(USERS_FILE, "r") as file:
        return [line.strip() for line in file]

# Function to read courses from file
def read_courses():
    with open(COURSES_FILE, "r") as file:
        return [line.strip() for line in file]

# Function to handle GET requests
def handle_get_request():
    path_info = os.environ["PATH_INFO"]

    if path_info == "/users/list":
        users = read_users()
        greetings = ["Hey awesome people!", "Greetings fellow humans!", "Welcome to the user zone!"]
        print("Content-Type: text/plain")
        print()
        print(random.choice(greetings))
        print("Here are the fantastic users:", ", ".join(users))
    elif path_info == "/courses/list":
        courses = read_courses()
        descriptions = ["Courses hotter than the sun!", "Knowledge galore! Dive in!", "Unlock the secrets of the universe!"]
        print("Content-Type: text/plain")
        print()
        print(random.choice(descriptions))
        print("Behold! The majestic courses:", ", ".join(courses))
    else:
        print("Content-Type: text/plain")
        print()
        print("Normal GET request received. Boring, right?")

# Function to handle POST requests
def handle_post_request(http_request):
    path_info = os.environ["PATH_INFO"]

    if path_info == "/users/list":
        username = parse_field_from_http_request(http_request, "username")
        print(username)
        with open(USERS_FILE, "a") as file:
            file.write(username + "\n")
        confirmations = ["User added successfully!", "Hooray! You're now part of our system!", "Welcome aboard, {}!".format(username)]
        print("Content-Type: text/plain")
        print()
        print(random.choice(confirmations))
    elif path_info == "/courses/list":
        course = parse_field_from_http_request(http_request, "course")
        # Add course to the file
        with open(COURSES_FILE, "a") as file:
            file.write(course + "\n")
        confirmations = ["Course added successfully!", "New course unlocked!", "Congratulations! You've just enrolled in {}!".format(course)]
        print("Content-Type: text/plain")
        print()
        print(random.choice(confirmations))
    else:
        print("Content-Type: text/plain")
        print()
        print("Invalid request")

# Main CGI entry point
if __name__ == "__main__":
    print("Status: 200 OK")  # HTTP status code for success
    print("Content-Type: text/plain")  # Set content type as plain text
    print("\r\n\r\n")
    request_method = os.environ["REQUEST_METHOD"]
    if request_method == "GET":
        handle_get_request()
    elif request_method == "POST":
        content = os.environ["REQUEST"]
        handle_post_request(content)


    
