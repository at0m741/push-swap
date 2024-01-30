NAME =	push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c \
	   push_swap.c \
	   sort.c \
	   push.c \
	   reverse.c \
	   rotate.c \
	   swap.c \
	   utils.c \
	   utils2.c \
	   utils3.c \
	   utils4.c \
	   utils5.c \
	   utils6.c \
	   sort2.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: 
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re