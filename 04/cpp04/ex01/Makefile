# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 18:20:51 by cping-xu          #+#    #+#              #
#    Updated: 2024/02/03 16:40:53 by cping-xu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= zoo
	
CC			= c++ -std=c++98 -pedantic
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OBJDIR		= .objFiles

FILES		= main Animal Cat Dog WrongAnimal WrongCat Brain

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

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
