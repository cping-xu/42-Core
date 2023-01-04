
# ------------------------------ Sources ------------------------------

# Files
MANDATORY	=	Mandatory/dfs.c \
				Mandatory/error.c \
				Mandatory/getmap.c \
				Mandatory/move.c \
				Mandatory/putimage.c \
				Mandatory/checkav.c \
				Mandatory/so_long.c	\
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

BONUS		=	Bonus/dfs_bonus.c \
				Bonus/error_bonus.c \
				Bonus/getmap_bonus.c \
				Bonus/move_bonus.c \
				Bonus/putimage_bonus.c \
				Bonus/checkav_bonus.c	\
				Bonus/so_long_bonus.c	\
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

LIBFT		=	cd libft && make

LIB			=	libft/libft.a

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

LBX			=	-lmlx -framework OpenGL -framework AppKit -lz 

INCLUDE		=	-I include

MAN_NAME	=	so_long

BONUS_NAME	=	so_long_bonus

NAME		=	so_long

# Sources and objects
MAN_SRC		=	$(MANDATORY)

MAN_OBJS	=	$(MAN_SRC:.c=.o)

BONUS_SRC	=	$(BONUS)

BONUS_OBJS	=	$(BONUS_SRC:.c=.o)

OBJS		=	$(MAN_OBJS) \
				$(BONUS_OBJS)

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

BOLD_GREEN	=	\033[1;32m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

MAN_READY	=	echo "\n📥 $(BOLD_GREEN)Mandatory ready!\n"

BONUS_READY	=	echo "\n📟 $(BOLD_GREEN)Bonus ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------

.c.o:
	@$(GCC) $(FLAGS) $(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): comp_start mandatory

all: $(NAME)

comp_start:
	@$(COMP_START)

mandatory: $(MAN_OBJS)
	@$(LIBFT)
	@$(GCC) $(FLAGS) $(LBX) $(MAN_OBJS) $(LIB) -o $(MAN_NAME)
	@$(MAN_READY)

bonus: $(BONUS_OBJS)
	@$(LIBFT)
	@$(GCC) $(FLAGS) $(LBX) $(BONUS_OBJS) $(LIB) -o $(BONUS_NAME)
	@$(BONUS_READY)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean
	@$(CLEANED)

fclean: clean
	@rm -rf $(MAN_NAME) $(BONUS_NAME)
	@cd libft && make fclean
	@$(FCLEANED)

re:	fclean all

.PHONY: all so_long mandatory bonus clean fclean re libft