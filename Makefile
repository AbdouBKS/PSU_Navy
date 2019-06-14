##
## EPITECH PROJECT, 2018
## navy
## File description:
## Make file
##

SRC     =	main.c								\
			./systeme_handler/helper.c			\
			./systeme_handler/error.c			\
			./handler_file/read_pos_file.c		\
			./handler_file/handle_pos_tab.c		\
			./handler_file/check_pos_file.c		\
			./handler_file/check_pos_file2.c	\
			./map/player_map.c					\
			./map/ennemy_map.c					\
			./map/update_map.c					\
			./systeme_handler/free.c			\
			./signal/connexion.c				\
			./signal/signals_connexion.c  		\
			./game/game_loop.c					\
			./game/input.c						\
			./game/check_boat.c					\
			./signal/signals.c					\
			./signal/signals_boat.c

NAME    =	navy

OBJ	=	$(addprefix src/,$(SRC:.c=.o))

CFLAGS = -Wall -Wextra -W -g -Iinclude

$(NAME):	$(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) -L./lib/ -lmy

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
