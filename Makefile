NAME = fractol
SRC =   julia.c mandelbrot.c  fractol.c utils.c  main_m_j.c       
OBJ = $(SRC:.c=.o)
HEADER = fractol.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
		@$(CC) $(OBJ) -o $(NAME) -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
	@echo "Compiling up..."
clean : 
		@rm -rf $(OBJ)
		@echo "Cleaning up..."

fclean : clean
		@rm -rf  $(NAME)
		@echo "Cleaning up..."

re : fclean all

.PHONY : all fclean clean re
