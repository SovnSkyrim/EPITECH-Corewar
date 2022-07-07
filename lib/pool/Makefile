##
## EPITECH PROJECT, 2022
## B-PSU-200-LIL-2-1-tetris-bauchart.loic
## File description:
## Makefile
##

SRC = 	my_nbrtostr.c \
		my_put_in_terminal.c \
		my_revstr.c \
		my_str_to_word_array.c \
		my_strcat.c \
		my_strlen.c \
		my_strtonbr.c \
		my_arrayheight.c \
		my_strxdup.c \
		my_strcompare.c \
		my_array_to_str.c \
		my_add_to_str.c \
		my_arraycpy.c \

OBJ = $(SRC:.c=.o)

NAME = ../libpool.a

PROTOTYPE = libpool.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(PROTOTYPE) ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../${NAME}

re: fclean all

