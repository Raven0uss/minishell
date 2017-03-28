#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 20:16:27 by sbelazou          #+#    #+#              #
#    Updated: 2017/03/28 13:34:11 by sbelazou         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	minishell
DIRSRC		=	./srcs/
DIROBJ		=	./objs/
BINDIR		=	.
INC_LIB		=	./includes/libft/libft.a
SRC			=	main.c exec.c ft_echo.c ft_cd.c ft_env.c\
				ft_setenv.c ft_unsetenv.c

OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(DIROBJ)%)
FLAGS		=	yes

ifdef FLAGS
	ifeq ($(FLAGS), yes)
CFLAGS		=	-Wall -Wextra -Werror
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
	else
CFLAGS		=
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	echo

all:			$(BINDIR)/$(NAME)

$(BINDIR)/$(NAME):	$(OBJ)
					-@make -C includes/libft/
					-@$(CC) $(INC_LIB) $(CFLAGS) -o $(NAME) $(OBJS)
					@$(ECHO) "\033[32mAll sources are compiled. "
					@$(ECHO) "$(NAME) has been created.\033[0m"

clean	:
				-@make clean -C includes/libft/
				@(cd $(DIROBJ) && $(RM) $(OBJ))
				@$(ECHO) "\033[31mObjects of $(NAME) has been removed.\033[0m"

fclean	:		clean
				-@make fclean -C includes/libft/
				-@$(RM) $(NAME)
				@$(ECHO) "\033[31m$(NAME) has been removed.\033[0m"

re		:		fclean all

zen		:		clean
				-@find . \( -name "*~" -o -name "#*#" \) -delete
				@$(ECHO) "\033[31mBack-up files has been removed.\033[0m"

git		:	zen fclean
			git add -f *
			git commit -am "Push with Makefile"
			git push

.PHONY	:		all clean fclean re

%.o		:		$(DIRSRC)/%.c
				$(CC) $(CFLAGS) -o $(DIROBJ)/$@ -c $<
