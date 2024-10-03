# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 15:42:55 by cping-xu          #+#    #+#              #
#    Updated: 2024/04/19 17:09:26 by cping-xu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = PmergeMe

CC          = c++
FLAGS       = -Wall -Wextra -Werror -std=c++98 -g
RM          = rm -rf

OBJDIR      = .objFiles

FILES       = main PmergeMe

SRC         = $(FILES:=.cpp)
OBJ         = $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER      = PmergeMe.hpp

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
