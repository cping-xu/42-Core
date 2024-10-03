# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cping-xu <cping-xu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 16:38:45 by cping-xu          #+#    #+#              #
#    Updated: 2024/04/23 08:27:56 by cping-xu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Bureaucrat
	
CC			= c++ -std=c++98 -pedantic
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR 		= .objFiles

FILES		= main Bureaucrat AForm PresidentialPardonForm RobotomyRequestForm ShrubberyCreationForm Intern

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

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
	@$(RM) $(NAME) *_shrubbery

re: fclean all