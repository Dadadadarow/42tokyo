SERVER = server
CLIENT = client
LIBFT = libft
NAME = blank

S_SRCS = s_srcs/server.c
C_SRCS = c_srcs/client.c
S_OBJS = $(S_SRCS:.c=.o)
C_OBJS = $(C_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = --no-print-directory -C

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT) $(LIBFT)

$(SERVER) : $(S_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(S_OBJS) -L./libft -lft

$(CLIENT) : $(C_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(C_OBJS) -L./libft -lft

$(LIBFT) : FORCE
	make $(MFLAGS) libft

clean :
	rm -rf $(S_OBJS) $(C_OBJS)
	make clean $(MFLAGS) libft

fclean : clean
	rm -rf $(SERVER) $(CLIENT)
	make clean $(MFLAGS) libft

re : fclean all

FORCE : 

.PHONY : all clean fclean re FORCE
