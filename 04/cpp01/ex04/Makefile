# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 13:09:33 by cping-xu          #+#    #+#              #
#    Updated: 2024/02/02 16:11:42 by cping-xu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= sed

CC		= 	c++ -std=c++98 -pedantic
CFLAGS	=	-Wall -Wextra -Werror
RM			= rm -rf

OBJDIR 		= .objFiles

FILES		= main

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) *.replace

re: fclean all
