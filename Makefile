##
## EPITECH PROJECT, 2021
## makefile evalexpr
## File description:
## makefile for evalxpr
##

SRC = 	asm.c \
		src/cus_lib/my_memset.c \
		src/cus_lib/cus_mal.c\
		src/cus_lib/int_to_byte.c \
		src/print/print_help.c \
		src/print/write_cor.c \
		src/print/write_types.c \
		src/print/get_program_size.c \
		src/parsing/fun_starts.c \
		src/parsing/init_struct.c \
		src/parsing/is_label.c \
		src/parsing/opt_fun.c \
		src/parsing/init_types.c \
		src/command/getcommand.c \
		src/command/getfilename.c \
		src/parsing/check_types.c \
		src/parsing/label_handling.c \

OBJ =	$(SRC:.c=.o)

NAME = 	asm

CFLAGS += -Wall -Wextra

all:	$(NAME)

$(NAME):	${OBJ}
	make -C ./lib/c_malloc
	make -C ./lib/pool
	gcc -o ${NAME} ${OBJ} -L ./lib -lpool -lc_malloc

clean:
	make -C ./lib/pool clean
	make -C ./lib/c_malloc clean
	rm -f $(OBJ)

fclean: clean
	make -C ./lib/pool fclean
	make -C ./lib/c_malloc fclean
	rm -f ${NAME}

re: fclean all
	make -C ./lib/c_malloc fclean re
	make -C ./lib/pool fclean re

debug:     ${OBJ}
	make -C ./lib/c_malloc
	make -C ./lib/pool
	gcc -g -o $(NAME) $(SRC) -L ./lib -lpool -lc_malloc

# tests_run:
# 	@make -s -C ./lib/freeing
# 	@make -s -C tests
# 	@./unit_tests
# 	@make -s -C tests fclean
# 	@make -s -C ./lib/freeing fclean
