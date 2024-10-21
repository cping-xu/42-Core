#!/bin/bash

service mariadb start
sleep 5

mariadb -e "CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;"
mariadb -e "CREATE USER IF NOT EXISTS \`${DB_ADMIN_USER}\`@'%' IDENTIFIED BY '${DB_ADMIN_PASS}';"
mariadb -e "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO \`${DB_ADMIN_USER}\`@'%';"
mariadb -e "FLUSH PRIVILEGES;" # Flush privileges to apply changes

mysqladmin -u root -p$DB_ROOT_PASS shutdown

# mysqld will start MariaDB in safe mode, and store files in '/var/lib/mysql' 
mysqld_safe --port=3306 --bind-address=0.0.0.0 # Restart in background
