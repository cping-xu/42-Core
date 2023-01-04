
# ------------------------------ Sources ------------------------------

# Files
SERVER		=	ft_server/ft_server.c

CLIENT		=	ft_client/ft_client.c

B_SERVER	=	ft_server_bonus/ft_server_bonus.c 

B_CLIENT	=	ft_client_bonus/ft_client_bonus.c 

LIBFT		=	cd libft && make

LIB			=	libft/libft.a

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

INCLUDE		=	-I include

SERVER_NAME	=	server

CLIENT_NAME	=	client

BOSER_NAME	=	server_bonus

BOCLI_NAME	=	client_bonus

NAME		=	server

# Sources and objects
SERVER_SRC	=	$(SERVER)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	$(CLIENT)

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

BOSER_SRC	=	$(B_SERVER)

BOSER_OBJS	=	$(BOSER_SRC:.c=.o)

BOCLI_SRC	=	$(B_CLIENT)

BOCLI_OBJS	=	$(BOCLI_SRC:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS) \
				$(BOSER_OBJS) \
				$(BOCLI_OBJS)

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

BOLD_GREEN	=	\033[1;32m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

SERV_READY	=	echo "\n📥 $(BOLD_GREEN)Server ready!\n"

CLI_READY	=	echo "\n📟 $(BOLD_GREEN)Client ready!\n"

BO_READY	=	echo "\n $(BOLD_GREEN)Bonus ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------

.c.o:
	@$(GCC) $(FLAGS) $(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): comp_start ft_server ft_client

all: $(NAME)

comp_start:
	@$(COMP_START)
	@$(LIBFT)

ft_server: $(SERVER_OBJS)
	@$(LIBFT)
	@$(GCC) $(FLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER_NAME)
	@$(SERV_READY)

ft_client: $(CLIENT_OBJS)
	@$(LIBFT)
	@$(GCC) $(FLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT_NAME)
	@$(CLI_READY)

bonus: $(BOSER_OBJS) $(BOCLI_OBJS)
	@$(LIBFT)
	@$(GCC) $(FLAGS) $(BOSER_OBJS) $(LIB) -o $(BOSER_NAME)
	@$(GCC) $(FLAGS) $(BOCLI_OBJS) $(LIB) -o $(BOCLI_NAME)
	@$(BO_READY)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean
	@$(CLEANED)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME) $(BOSER_NAME) $(BOCLI_NAME)
	@cd libft && make fclean
	@$(FCLEANED)

re:	fclean all

.PHONY: all minitalk ft_server ft_client bonus clean fclean re libft