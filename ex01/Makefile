# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 10:43:40 by mjourno           #+#    #+#              #
#    Updated: 2023/09/04 15:28:58 by mjourno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex01.exe
#Compiler
CC		=	c++
FLAG	=	-Wall -Wextra -Werror -std=c++98
#Source
FILES	=	main Bureaucrat Form
FFORMAT	=	cpp
SRC_DIR	=
OBJ_DIR	=	obj/
#Header
HFILES	=	Bureaucrat Form
HFORMAT	=	hpp
HEADER	=	$(addsuffix .$(HFORMAT), $(HFILES))

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .$(FFORMAT), $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF	=	.cache_exits

$(OBJF) :
	@mkdir -p $(OBJ_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o : %.$(FFORMAT) $(HEADER) Makefile | $(OBJF)
	$(CC) $(FLAG) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJF)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

# Color
DEF_COLOR	= \033[0;39m
GRAY		 = \033[0;90m
RED		 = \033[0;91m
GREEN		 = \033[0;92m
YELLOW		 = \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m