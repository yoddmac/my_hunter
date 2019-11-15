CC	=	gcc

RM	=	rm -rf

NAME	=	my_hunter

CFLAGS	=	-W -Wall -Wextra

CFLAGS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system

SRC	=	open_window.c \
		create_sprite.c \
		malloc.c \
		move_perso.c

OBJ	=$(SRC:.c=.o)

all: compil

compil: $(SRC)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

valgrind: $(SRC)
	$(CC) -g -o $(NAME) $(SRC) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: re all clean fclean
