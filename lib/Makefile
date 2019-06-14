##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## library
##

SRC 	=	write_fun.c		\
		strlen_tab.c		\
		free_tab.c		\
		get_next_line.c		\
		len_tab.c		\
		my_getnbr.c		\
		nbr_to_str.c		\
		strtoword_array.c	\
		clean_malloc.c		\
		isit_number.c		\
		put_tab.c		\
		my_strdup.c		\
		my_strcomp.c		\
		isit_alpha.c		\

OBJ 	= 	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra -W -I../include

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:
	fclean all

.PHONY: all clean fclean re
