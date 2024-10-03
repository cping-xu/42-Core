# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 16:28:22 by cping-xu          #+#    #+#              #
#    Updated: 2024/04/19 19:01:06 by cping-xu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= convert
	
CC			= c++ -std=c++98 -pedantic
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR 		= .objFiles

FILES		= main Scalar

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Scalar.hpp

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

re: fclean all
