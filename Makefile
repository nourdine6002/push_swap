NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= main.c parsing.c handel_error.c swap.c rotate.c rrotate.c push.c ft_putstr_fd.c ft_split.c norm1.c\
			  small_sort.c large1.c large2.c large3.c main_sort.c large1_norm.c large3_norm.c

BONUS_SRC	= checker_bonus.c checker_read_bonus.c checker_ops_bonus.c norm1.c\
			  parsing.c handel_error.c swap.c rotate.c rrotate.c push.c \
			  get_next_line_bonus.c get_next_line_utils_bonus.c ft_putstr_fd.c ft_split.c

OBJ			= $(SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)


%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all