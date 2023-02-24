# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 23:28:08 by cping-xu          #+#    #+#              #
#    Updated: 2023/02/24 23:28:12 by cping-xu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	utils.c \
			init.c \
			philo.c \
			free.c \

CC		= 	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=thread
#FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
FLAGS 	=	-Wall -Wextra -Werror
RM 		=	rm -rf

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
