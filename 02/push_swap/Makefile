NAME		= push_swap
SRCSDIR		= srcs
OBJSDIR		= objs
INCLUDES	= incs

SRCS		= pa.c pb.c ra.c rb.c rra.c rrb.c sa.c sb.c swap.c pushswap.c ft_error.c error.c ft_arraylen.c ft_atoi.c ft_calloc.c ft_split.c ft_strdup.c ft_intcmp.c swapless.c findmin.c ft_itoa.c order.c findsmall.c max.c

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror


OBJS	= $(SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Assembling $@"
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re test
