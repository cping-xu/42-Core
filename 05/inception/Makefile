MARIADB		= mariadb-database
NGINX		= nginx-server
WORDPRESS	= wordpress-app

COMPOSE		= sudo docker compose -f srcs/docker-compose.yml

include srcs/.env

all:
	sudo mkdir -p $(VOLUMES_PATH)/mysql $(VOLUMES_PATH)/wordpress
	$(COMPOSE) up -d

start:
	$(COMPOSE) up -d

stop:
	$(COMPOSE) stop

clean:
	$(COMPOSE) down --rmi all --volumes

fclean: clean
	sudo rm -rf $(VOLUMES_PATH)
	docker system prune -a --volumes -f

re: fclean all
