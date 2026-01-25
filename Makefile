NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c parsing.c handel_error.c swap.c rotate.c rrotate.c push.c \
			  small_sort.c large1.c large2.c large3.c main_sort.c large1_norm.c large2_norm.c large3_norm.c

BONUS_SRC	= checker.c checker_read.c checker_ops.c \
			  parsing.c handel_error.c swap.c rotate.c rrotate.c push.c \
			  small_sort.c large1.c large2.c large3.c  main_sort.c large1_norm.c large2_norm.c large3_norm.c\
			  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ			= $(SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)

LIBFT		= libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C libft
	make bonus -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	make fclean -C libft

re: fclean all