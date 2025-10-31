# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 10:47:03 by wshou-xi          #+#    #+#              #
#    Updated: 2025/10/31 11:50:32 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./headers -I./libft/includes
LIB = -lreadline -lhistory -Llibft -lft
RM = rm -rf

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

SRCDIR = src
SRCFILES = main.c
SRC = $(addprefix $(SRCDIR)/, $(SRCFILES))

NAME = minishell

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -s -C libft
	@$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)
	@echo Minishell successfully compiled

all: $(NAME)

clean:
	@$(MAKE) -s -C libft clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C libft fclean
	@echo successfully full cleaned

re: fclean all

.PHONY: all clean fclean re