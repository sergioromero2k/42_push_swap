AR= ar -rcs					
RM=rm -f

CC = cc 							
CCFLAGS = -Wall -Werror -Wextra		
INCLUDE = libft.h

NAME = libft.a						
SRC=ft_calloc.c ft_isascii.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c Makefile\
ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c\
ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c
OBJ_SRC=$(SRC:.c=.o)				

SRC_BONUS= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ_BONUS=$(SRC_BONUS:.c=.o)

all: $(NAME)						

$(NAME):$(OBJ_SRC) $(INCLUDE)
	$(AR) $(NAME) $(OBJ_SRC)

bonus: $(OBJ_SRC) $(OBJ_BONUS) $(INCLUDE)
	$(AR) $(NAME) $(OBJ_BONUS) $(OBJ_SRC)

%.o:%.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re	bonus	