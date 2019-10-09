# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/05 11:39:15 by amalsago          #+#    #+#              #
#    Updated: 2019/10/09 17:20:57 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General

NAME		= minishell
LIBNAME		= libft.a

# **************************************************************************** #
# GNU Compiler Collection

GCC			= /usr/bin/clang
WOPT		= -Wall -Wextra -Werror
OOPT		= #-O2
IOPT		= -I $(INCDIR)

# **************************************************************************** #
# System commands

AR			= /usr/bin/ar -rc
MAKE		= /usr/bin/make -C
RANLIB		= /usr/bin/ranlib
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p
RM			= /bin/rm -rf

# **************************************************************************** #
# Directories of source and object files

LIBDIR		= ./libft
SRCDIR		= ./sources
OBJDIR		= ./objects
INCDIR		= ./includes

# **************************************************************************** #
# List of source files

SRCNAME		= main.c	\
			  display_prompt.c\
			  tools/clear_console.c

# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))
LFT			= $(addprefix $(LIBDIR)/, $(LIBNAME))
LFTOBJ		= $(LIBDIR)/objects/*/*.o

# **************************************************************************** #
# Extra

CR			= "\r"$(CLEAR)
CLEAR       = "\\033[0K"
EOC			= "\033[0;0m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
BASENAME	= `basename $(PWD)`

# **************************************************************************** #
# Rules

all: $(NAME) $(LFT)

$(NAME): $(LFT) $(OBJ)
	@$(GCC) $(OBJ) $(LFT) -o $(NAME)
	@printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(GCC) $(WOPT) $(OOPT) $(IOPT) -c $< -o $@
	@printf $(CR)"[ ./$(BASENAME)/%s ]"$(CLEAR) $@

$(LFT):
	@$(MAKE) $(LIBDIR)

clean:
	@if [ -d $(OBJDIR) ]; then \
		$(RM) $(OBJ) $(OBJDIR) \
		&& printf $(CR)$(RED)"✗ The objects files of ft_ls are cleaned\n"$(EOC) \
		&& $(MAKE) $(LIBDIR) clean; \
	fi

fclean: clean
	@if [ -e $(NAME) ]; then \
		$(RM) $(NAME) \
		&& printf $(CR)$(RED)"✗ $(NAME) is cleaned\n"$(EOC) \
		&& $(MAKE) $(LIBDIR) fclean; \
	fi

re: fclean all

norm:
	@$(NORMINETTE) $(SRCDIR) $(INCDIR) $(LIBDIR)/sources | /usr/bin/less

.PHONY: all clean fclean re norm
