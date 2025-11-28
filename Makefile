# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 00:13:06 by cel-hajj          #+#    #+#              #
#    Updated: 2025/11/28 10:17:34 by cel-hajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = src/ft_printf.c src/ft_printf_utils.c
OBJS = ${SRCS:.c=.o}
INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFTDIR) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTDIR) all
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: clean all

.PHONY: all clean fclean re