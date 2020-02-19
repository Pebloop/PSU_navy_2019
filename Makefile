SRC	=	src/get_next_line.c		\
		src/math_tools.c 		\
		src/error_detection.c	\
		src/display_usage.c		\
		src/get_grid.c 			\
		src/detect_signal.c		\
		src/player_one.c		\
		src/player_two.c		\
		src/navy.c				\
		src/display_grid.c		\
		src/display_board.c		\
		src/you_play.c			\
		src/they_play.c			\

MAIN =	main.c

OBJ	=	$(SRC:.c=.o)

MAIN_OBJ = 	$(MAIN:.c=.o)

CFLAGS = -Iinclude/ -Llib/fae/ -lfae -Llib/list/ -llist

NAME =	navy

TEST =	navy.out

DEBUG =	navy.debug

all: $(NAME)

make_lib:
	make -C lib/fae/
	make -C lib/list/

$(NAME): make_lib $(OBJ) $(MAIN_OBJ)
	gcc -o $(NAME) $(MAIN_OBJ) $(OBJ) $(CFLAGS)

debug: make_lib $(OBJ) $(MAIN_OBJ)
	gcc -g3 -o $(NAME) $(MAIN_OBJ) $(OBJ) $(CFLAGS)

tests_run: make_lib
	gcc -o $(TEST) $(OBJ) $(CFLAGS)
	./$(TEST)

retest: fclean tests_run

clean:
	make clean -C lib/fae/
	make clean -C lib/list/
	rm -f $(OBJ) $(MAIN_OBJ)

fclean: clean
	make fclean -C lib/fae/
	make fclean -C lib/list/
	rm -f $(TEST) $(NAME)

re: fclean all
