CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
#-fsanitize=address
SRC_PATH = ./src/
OBJ_PATH = ./obj/
SRC_NAME = choose_algo.c\
new_small.c\
new_sort_first_try.c\
push_swap.c\
sort_array_all_sizes.c

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./includes/\
../libft/includes/\
../libpushswap/includes/

LIB_PATH1 = ../libft/
LIB_PATH2 = ../libpushswap/

LIB_PATH = $(LIB_PATH1) $(LIB_PATH2)


LIB_LINKS = -lft -lpushswap

NAME = push_swap

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))

all: lib $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIB_LINKS) $(INC) -o $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -rfv $(OBJ_PATH)

fclean: clean
	rm -fv $(NAME)

re: fclean all

lib:
	make -C $(LIB_PATH1)
	make -C $(LIB_PATH2)

cleanlib:
	make clean -C $(LIB_PATH1)
	make clean -C $(LIB_PATH2)

fcleanlib:
	make fclean -C $(LIB_PATH1)
	make fclean -C $(LIB_PATH2)

relib:
	make re -C $(LIB_PATH1)
	make re -C $(LIB_PATH2)

reall: fcleanlib re

realmost:
	make fclean -C $(LIB_PATH2)
	make fclean
	make re

gitupdate:fclean fcleanlib
	git add $(SRC)

gitupload:gitupdate
	git push
