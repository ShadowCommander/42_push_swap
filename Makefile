# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 09:44:30 by jtong             #+#    #+#              #
#    Updated: 2021/10/18 12:28:37 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
FILENAMES := test
LIBS := ft
LIBNAMES := libft.a
LIBFULL := libft/libft.a #$(addprefix $(LIBDIR)/,$(LIBNAME))
LIB_INCLUDES := $(LIBS)
LIBDIRS := libft
HEADERDIRS := . $(LIBDIRS) bonus

OBJ := $(addsuffix .o,$(FILENAMES))

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

$(LIBFULL):
	$(MAKE) -C libft $(MODE)

%.o: %.c
	$(CC) $(OFLAGS) -c $<

clean:
	/bin/rm -f $(NAME)

fclean: clean
	/bin/rm -f $(OBJ)
	$(MAKE) -C libft clean

re: fclean all

cleanobj:
	/bin/rm -f $(OBJ)

.PHONY: all env debug test clean fclean cleanobj re mlx
