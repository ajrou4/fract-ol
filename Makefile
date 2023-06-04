NAME = fractol
SRC = fractol.c test.c
OBJ = $(SRC:.c=.o)
HEADER = fractol.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
		$(RM)$(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all fclean clean re