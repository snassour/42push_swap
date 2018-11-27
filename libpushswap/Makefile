#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snassour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 14:53:41 by snassour          #+#    #+#              #
#    Updated: 2018/08/30 14:53:46 by snassour         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_PATH = ./src/

OBJ_PATH = ./obj/

SRC_NAME = action_pa.c\
action_pb.c\
action_ra.c\
action_rb.c\
action_rr.c\
action_rra.c\
action_rrb.c\
action_rrr.c\
action_sa.c\
action_sb.c\
action_ss.c\
check_error_pile.c\
ps_init.c\
ps_display_stacks.c\
push_s_endinit.c\
display_actions.c


OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./includes/\
../libft/includes/

LIB_PATH = ../libft/

LIB_NAME = -lft

NAME = libpushswap.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))

all:libft $(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean: 
	rm -rfv $(OBJ_PATH)

fclean: clean
	rm -fv $(NAME)

re: fclean all

libft:
	make -C $(LIB_PATH)

cleanlib:
	make clean -C $(LIB_PATH)

fcleanlib:
	make fclean -C $(LIB_PATH)

relib:
	make re -C $(LIB_PATH)

gitupdate:fclean libfclean
	git add $(SRC)

gitupload:gitupdate
	git push
