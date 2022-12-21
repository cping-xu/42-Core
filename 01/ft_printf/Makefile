NAME	= libftprintf.a
OBJS	= $(SRCS:.c=.o)
SRCS	= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_unsignednbr.c ft_putptr.c ft_putuphex.c
INCS	= ft_printf.h
LIBC	= ar rc
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
