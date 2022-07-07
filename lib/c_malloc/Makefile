##
## EPITECH PROJECT, 2022
## B-PSU-200-LIL-2-1-tetris-bauchart.loic
## File description:
## Makefile
##

SRC = 	my_malloc.c \

OBJ = $(SRC:.c=.o)

NAME = ../libc_malloc.a

PROTOTYPE = libc_malloc.h

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
