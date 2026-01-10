NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
INC         = -I./include -I$(LIBFT_DIR)

# He ajustado los nombres según tu captura de pantalla
SRC         = src/main.c \
              src/operations/stack_ops_1.c \
              src/operations/stack_ops_2.c \
              src/rules/pa.c src/rules/pb.c \
              src/rules/ra.c src/rules/rb.c src/rules/rr.c \
              src/rules/rra.c src/rules/rrb.c src/rules/rrr.c \
              src/rules/sa.c src/rules/sb.c src/rules/ss.c \
              src/sorting/sort_large.c \
              src/sorting/sort_small.c \
              src/sorting/turk_engine.c \
              src/sorting/utils_sort.c \
              src/utils/arg_parsing.c \
              src/utils/error_handling.c \
              src/utils/stack_utils.c

OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re