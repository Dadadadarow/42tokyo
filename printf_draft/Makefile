SRCS = srcs/ft_print_utils.c srcs/ft_print_utils2.c srcs/ft_printf.c lib/ft_putnbr_int.c lib/ft_putnbr_pointer.c lib/ft_putnbr_uint.c lib/ft_putstr.c lib/ft_strchr.c lib/ft_strlen.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all:$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: fclean
	$(CC) $(CFLAGS) main.c $(SRCS)