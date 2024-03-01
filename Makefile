NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c ultra_split.c stacking.c sort_moves.c stack_info.c set_stack.c set_stack_utils.c sort_moves_advance.c sorter.c
SRC_B = checker_bonus.c stacking.c ultra_split.c primary_movements_bonus.c swap_moves_bonus.c push_moves_bonus.c rotate_moves_bonus.c rev_rot_moves_bonus.c moves_interpreter_bonus.c execute_moves_bonus.c
OBJ = ${SRC:.c=.o}
OBJ_B = ${SRC_B:.c=.o}
LIB_B = bonus.a
LIB = push_swap.a

all: ${NAME}

${NAME}: ${LIB}
	${CC} ${CFLAGS} ${LIB} -o ${NAME}

bonus: ${LIB_B}
	${CC} ${CFLAGS} ${LIB_B} -o checker
	touch bonus

${LIB}: ${OBJ}
	ar rc ${LIB} ${OBJ}

${LIB_B}: ${OBJ_B}
	ar rc ${LIB_B} ${OBJ_B}

%.o: %.c Makefile
	${CC} ${CFLAGS} -MMD -c $<

clean:
	rm -rf ${LIB} ${LIB_B} ${OBJ} ${OBJ_B} *.d bonus

fclean: clean
	rm -rf ${LIB} ${LIB_B} ${NAME} checker

re: fclean all

-include *.d

.PHONY: all clean fclean re
