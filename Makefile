CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror


SRCS = main.c validations.c stacks.c push.c rotate.c swap.c reverse_rotate.c push_swap.c
OBJ = $(SRCS:.c=.o)
NAME = push_swap
LIBFT_DIR = ./libft

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(NAME)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f libft.a

re: fclean all