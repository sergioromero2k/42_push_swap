NAME        = push_swap
NAME_BONUS  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
# INC ahora solo necesita include y libft, ya no usamos la carpeta externa de gnl
INC         = -I./include -I$(LIBFT_DIR)/include

# Archivos comunes (Lógica, Reglas y Utils)
SRC_COMMON  = src/operations/stack_ops_1.c \
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
              src/utils/stack_utils.c \
              src/utils/stack_check.c    

# Objetos para la parte obligatoria
SRC_MAND    = src/main.c $(SRC_COMMON)
OBJ_MAND    = $(SRC_MAND:.c=.o)

# Objetos para el Bonus (Usando el GNL mini que creamos en src_bonus)
SRC_BONUS   = src_bonus/checker.c \
              src_bonus/get_next_line_bonus.c \
              $(SRC_COMMON)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_MAND)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ_MAND) $(LIBFT) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

# Regla de compilación genérica
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_MAND) $(OBJ_BONUS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus