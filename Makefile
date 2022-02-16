NAME = so_long

MINILIBX =	-L. -lmlx

LIBFT =	libft/libft.a

SRCS =	so_long.c \
		parsing.c \
		print_map.c \
		hook.c \
		remplissage.c \

OBJS = $(SRCS:.c=.o)

HEADER =	so_long.h \
			minilibx/mlx.h \
			libft/libft.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -fstack-protector-all -O3
#FLAGS += -fsanitize=address -g3

all: lib libx $(NAME)

lib:
	make -C libft

libx:
	make -C minilibx
	cp minilibx/libmlx.dylib .

%.o : %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MINILIBX)
 
clean:
	rm -f $(OBJS)
	make -C minilibx clean
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	rm -f libmlx.dylib

re: fclean all

.PHONY:	all lib libx clean fclean re
