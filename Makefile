# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynacache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 10:53:49 by ynacache          #+#    #+#              #
#    Updated: 2018/05/12 15:06:46 by pmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace

ARG = "resources/test01.htr"

FILES = main.c \
		tree.c \
		ft_bzero.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_read_fd.c \
		ft_strncat.c \
		ft_realloc.c \
		ft_memcpy.c \
		ft_memcmp.c \
		hash.c

HFILES = includes/hotrace.h

CC = gcc
CFLAGS = -O3 -Wall -Wextra ########## -Werror

OBJS_DIR = objs/
SRCS_DIR = srcs/

INC_DIR =	includes/

INC := $(addprefix -I , $(INC_DIR))
SRCS := $(addprefix $(SRCS_DIR), $(FILES))
OBJS := $(addprefix $(OBJS_DIR), $(FILES:.c=.o))

NORMAL = "\x1B[0m"
RED = "\x1B[31m"
GREEN = "\x1B[32m"
YELLOW = "\x1B[33m"
BLUE = "\x1B[34m"
MAGENTA = "\x1B[35m"
CYAN = "\x1B[36m"
WHITE = "\x1B[37m"
BOLD = "\e[1m"
LIGHT = "\e[2m"
ITALIC = "\e[3m"
ULINE = "\e[4m"

START = @printf $(GREEN)$(BOLD)"HOTRACE\n--------------------\n"$(NORMAL)
END = @printf $(GREEN)$(BOLD)"--------------------\n"$(NORMAL)

all:
	$(START)
	@make $(NAME)
	$(END)

$(NAME): $(OBJS_DIR) $(OBJS)
	@printf $(CYAN)"-> create program : $(NAME)\n"$(NORMAL)
	@$(CC) -o $(NAME) $(OBJS) $(INC) $(CFLAGS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HFILES)
	@printf $(YELLOW)"-> $<\n"$(NORMAL)
	@$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJS_DIR):
	@mkdir -p $(dir $(OBJS))

clean:
	$(START)
	@printf $(RED)"-x remove .o files\n"$(NORMAL)
	@rm -rf $(OBJS_DIR)
	$(END)

fclean: clean
	$(START)
	@printf $(RED)"-x remove $(NAME)\n"$(NORMAL)
	@rm -f $(NAME)
	$(END)

re: fclean
	@make

exec:
	@clear
	@make
	@./$(NAME) < $(ARG)

.PHONY: all clean fclean re
