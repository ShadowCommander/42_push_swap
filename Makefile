# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 09:44:30 by jtong             #+#    #+#              #
#    Updated: 2021/11/06 06:03:13 by jtong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
FILENAMES := $(wildcard *.c)
LIBS := ft
LIBNAMES := libft.a
LIBFULL := libft/libft.a #$(addprefix $(LIBDIR)/,$(LIBNAME))
LIB_INCLUDES := $(LIBS)
LIBDIRS := libft
HEADERDIRS := . $(LIBDIRS) bonus

OBJ := $(FILENAMES:.c=.o)

CC := clang
HEADERFLAGS := $(addprefix -I,$(HEADERDIRS))
LIBFLAGS := $(addprefix -L,$(LIBDIRS)) $(addprefix -l,$(LIB_INCLUDES))
OFLAGS := $(HEADERFLAGS)
CCFLAGS := -Wall -Werror -Wextra $(HEADERFLAGS) $(LIBFLAGS)
MODE =

all: $(NAME)

debug: CCFLAGS += -g
debug: OFLAGS += -g
debug: MODE = debug
debug: cleanobj $(NAME)

leaks: CCFLAGS += -fsanitize=address
leaks: cleanobj $(NAME)

$(NAME): $(OBJ) $(LIBFULL)
	$(CC) $(notdir $(OBJ)) $(CCFLAGS) -o $@

$(LIBFULL): libft/*.c
	$(MAKE) -C libft $(MODE)

%.o: %.c
	$(CC) $(OFLAGS) -c $< -o $@

test: $(NAME)
	@-/bin/rm -f out.txt
	@echo "Run $(NAME)"
	./$(NAME) ~/42/pipex/test/in.txt /bin/cat /bin/cat ~/42/pipex/test/out.txt
	@echo "\nCheck $(NAME) permissions"
	@/bin/ls -l ~/42/pipex/test/out.txt
	@echo "\nContents:"
	@cat ~/42/pipex/test/out.txt

clean:
	/bin/rm -f $(NAME)
	$(MAKE) -C libft $(or $(MODE),clean)

fclean: MODE = fclean
fclean: clean
	/bin/rm -f $(OBJ)

re: fclean all

cleanobj:
	/bin/rm -f $(OBJ)

.PHONY: all env debug test clean fclean cleanobj re mlx
