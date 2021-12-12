# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 14:25:17 by jraffin           #+#    #+#              #
#    Updated: 2021/12/12 17:09:21 by jraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh

NAME		=	hotrace

INCLUDEDIR	=	./inc

SRCDIR		=	./src
OBJDIR		=	./obj
DEBUGDIR	=	./debugdir

SRCFILES	=	main.c			\
				utils.c			\
				gnl.c			\
				hash.c			\
				hashtable.c		\

SRCDEBUG	=	DEBUG_main.c	\
				utils.c			\
				gnl.c			\
				hash.c			\
				hashtable.c		\

OBJS		=	$(addprefix $(OBJDIR)/,$(SRCFILES:.c=.o))
DEBUGOBJS	=	$(addprefix $(DEBUGDIR)/,$(SRCDEBUG:.c=.o))

CC			=	cc
RM			=	rm

CFLAGS		=	-Wall -Wextra -Werror

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -Ofast $(addprefix -I ,$(INCLUDEDIR)) -c $< -o $@

$(DEBUGDIR)/%.o	:	$(SRCDIR)/%.c | $(DEBUGDIR)
	$(CC) $(CFLAGS) -g -Og $(addprefix -I ,$(INCLUDEDIR)) -c $< -o $@

all				:	$(NAME)

debug			:	$(NAME).debug

$(NAME)			:	$(OBJS)
	$(CC) $(CFLAGS) -Ofast -o $(NAME) $(OBJS)

$(NAME).debug	:	$(DEBUGOBJS)
	$(CC) $(CFLAGS) -g -Og -o $(NAME).debug $(DEBUGOBJS)

$(DEBUGDIR)		:
	mkdir $(DEBUGDIR)

$(OBJDIR)		:
	mkdir $(OBJDIR)

clean			:
	$(RM) -rf $(OBJDIR) $(DEBUGDIR)

fclean			:	clean
	$(RM) -f $(NAME) $(NAME).debug

re				:	fclean all

.PHONY			:	all clean fclean re
