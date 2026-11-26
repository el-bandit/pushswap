NAME	= push_swap.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I includes

SRC		= convert_input.c input_utils.c list_init.c sort_complex.c sort_operations.c sort_operations2.c sort_operations3.c sort_simple.c sort_small.c compute_disorder.c sort_adaptive.c sort_medium_utils.c sort_medium.c

OBJ		= $(SRC:.c=.o)

RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re