# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/05 11:39:15 by amalsago          #+#    #+#              #
#    Updated: 2020/01/18 18:12:51 by amalsago         ###   ########.fr        #
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
OOPT		= -O3
IOPT		= -I $(INCDIR)

# **************************************************************************** #
# System commands

AR			= /usr/bin/ar -rc
LESS		= /usr/bin/less
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
			  builtins/builtin_builtins.c	\
			  builtins/builtin_cd.c			\
			  builtins/builtin_echo.c		\
			  builtins/builtin_env.c		\
			  builtins/builtin_exit.c		\
			  builtins/builtin_pwd.c		\
			  builtins/builtin_setenv.c		\
			  builtins/builtin_unsetenv.c	\
			  builtins/ft_setenv.c			\
			  builtins/ft_unsetenv.c		\
			  execution/execute.c			\
			  execution/execute_builtin.c	\
			  execution/execute_command.c	\
			  execution/find_executable.c	\
			  output/display_logtime.c		\
			  output/display_prompt.c		\
			  output/errors.c				\
			  output/print_commands.c		\
			  predicates/is_builtin.c		\
			  predicates/is_var_exist.c		\
			  tools/check_access.c			\
			  tools/expansion.c				\
			  tools/get_input.c				\
			  tools/history.c				\
			  tools/increment_level.c		\
			  tools/parse_input.c			\
			  tools/total_environ_rows.c	\
			  tools/setup_environ.c

# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))
LFT			= $(addprefix $(LIBDIR)/, $(LIBNAME))

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
	@$(GCC) $(WOPT) $(OBJ) $(LFT) -o $(NAME)
	@printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(GCC) $(WOPT) $(OOPT) $(IOPT) -c $< -o $@
	@printf $(CR)"[ ./$(BASENAME)/%s ]"$(CLEAR) $@

$(LFT): FORCE
	@$(MAKE) $(LIBDIR)

clean:
	@if [ -d $(OBJDIR) ]; then \
		$(RM) $(OBJ) $(OBJDIR) \
		&& printf $(CR)$(RED)"✗ The objects files of $(NAME) are cleaned\n"$(EOC)\
		&& $(MAKE) $(LIBDIR) clean; \
	fi

fclean: clean
	@$(RM) minishell.dSYM
	@if [ -e $(NAME) ]; then \
		$(RM) $(NAME) \
		&& printf $(CR)$(RED)"✗ $(NAME) is cleaned\n"$(EOC) \
		&& $(MAKE) $(LIBDIR) fclean; \
	fi

re: fclean all

norm:
	@$(NORMINETTE) $(SRCDIR) $(INCDIR) $(LIBDIR)/sources | $(LESS)

.PHONY: all clean fclean re norm

FORCE:
