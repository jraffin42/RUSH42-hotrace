# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 21:42:24 by agautier          #+#    #+#              #
#    Updated: 2021/12/11 17:20:08 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	hotrace

S			=	src/
O			=	obj/
I			=	header/
D			=	dep/

SRC			=	src/main.c						\
				src/ft_split.c					\
				src/ft_strjoin.c				\
				src/ft_strlcpy.c				\
				src/ft_strlen.c					\
				src/get_next_line.c				\
				src/ft_strncpy.c				\
				src/create_node.c				\
				src/buffer/buffer_add.c 		\
				src/buffer/buffer_print.c		\

OBJ			=	$(SRC:$S%.c=$O%.o)
DEP			=	$(SRC:$S%.c=$D%.d)

CC			=	cc

CFLAGS		+=	-I$I
CFLAGS		+=	-Wall -Wextra -Werror -g3 -fsanitize=address

LDFLAGS		+= -g3 -fsanitize=address	# TODO: remove

RM			=	/bin/rm -f
RMDIR		=	/bin/rm -Rf

.PHONY:	all clean fclean re

all: $(NAME)

$O:
	@mkdir -p $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$D:
	@mkdir -p $@

$(DEP): | $D

$(DEP): $D%.d: $S%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	$(RM) $(wildcard $(OBJ))
	$(RMDIR) $O
	$(RM) $(wildcard $(DEP))
	$(RMDIR) $D

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

-include $(DEP)
