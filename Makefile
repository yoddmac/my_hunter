##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -rf

NAME	=	my_hunter

CFLAGS	=	-W -Wall -Wextra

CFLAGS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

SRC	=	open_window.c \
		create_sprite.c \
		malloc.c \
		move_perso.c \
		text.c \
		shoot.c \
		main.c \
		displayhit.c \
		readme.c \
		my_putstr.c \
		my_putchar.c
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
