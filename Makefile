# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 14:25:17 by jraffin           #+#    #+#              #
#    Updated: 2021/12/13 00:03:50 by jraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh

NAME		=	hotrace

INCLUDEDIR	=	.

SRCDIR		=	.
OBJDIR		=	./obj

SRCFILES	=	main.c			\
				utils.c			\
				buffer.c		\
				gnl.c			\
				hash.c			\
				hashtable.c		\

OBJS		=	$(addprefix $(OBJDIR)/,$(SRCFILES:.c=.o))

CC			=	cc
RM			=	rm

CFLAGS		=	-Wall -Wextra -Werror

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -Ofast -fno-builtin $(addprefix -I ,$(INCLUDEDIR)) -c $< -o $@

all				:	$(NAME)

$(NAME)			:	$(OBJS)
	$(CC) $(CFLAGS) -Ofast -fno-builtin -o $(NAME) $(OBJS)

$(OBJDIR)		:
	mkdir $(OBJDIR)

clean			:
	$(RM) -rf $(OBJDIR)

fclean			:	clean
	$(RM) -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
