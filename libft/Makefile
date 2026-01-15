NAME    = libft.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I./include
AR      = ar -rcs
RM      = rm -f

SRC     = src/ft_atol.c \
          src/ft_bzero.c \
          src/ft_calloc.c \
          src/ft_isdigit.c \
          src/ft_memcpy.c \
          src/ft_memset.c \
          src/ft_split.c \
          src/ft_strchr.c \
          src/ft_strdup.c \
          src/ft_striteri.c \
          src/ft_strjoin.c \
          src/ft_strlcat.c \
          src/ft_strlcpy.c \
          src/ft_strlen.c \
          src/ft_strmapi.c \
          src/ft_strncmp.c \
          src/ft_strnstr.c \
          src/ft_strcmp.c\
          src/ft_strrchr.c \
          src/ft_strtrim.c \
          src/ft_substr.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re