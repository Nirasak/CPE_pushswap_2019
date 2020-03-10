##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/pushswap.c	\
		src/set_list.c	\
		src/my_atoi.c	\
		src/my_putstr.c	\

TESTS	=	tests/test_my_pushswap.c	\
		src/pushswap.c	\
		src/set_list.c	\
		src/my_atoi.c	\
		src/my_putstr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

CFLAGS	=	-W -Wall -g3

CPPFLAGS	=	-I include/

UNITFLAGS	=	-lcriterion --coverage

EXECTESTS	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

tests_run:
	$(CC) $(TESTS) $(CFLAGS) $(CPPFLAGS) $(UNITFLAGS) -o $(EXECTESTS)
	./$(EXECTESTS) && gcovr

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)
	rm -f $(EXECTESTS);

re:	fclean all

.PHONY:	all clean fclean re
