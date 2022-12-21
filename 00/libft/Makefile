# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cping-xu <cping-xu@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 16:23:36 by cping-xu          #+#    #+#              #
#    Updated: 2022/10/12 15:30:19 by cping-xu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BONUS:.c=.o)
SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
INCS	= libft.h
LIBC	= ar rc
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus : $(BOBJS)
	$(LIBC) $(NAME) $(BOBJS)

all : $(NAME)

clean : 
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
