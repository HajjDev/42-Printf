# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/29 13:09:15 by cel-hajj          #+#    #+#              #
#    Updated: 2025/11/29 13:09:18 by cel-hajj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = src/ft_printf.c src/ft_printf_utils.c
OBJS = ${SRCS:.c=.o}
INCLUDES = includes

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

LIBFT_SRCS = $(LIBFTDIR)/ft_atoi.c $(LIBFTDIR)/ft_bzero.c $(LIBFTDIR)/ft_calloc.c \
    $(LIBFTDIR)/ft_isalnum.c $(LIBFTDIR)/ft_isalpha.c $(LIBFTDIR)/ft_isascii.c \
    $(LIBFTDIR)/ft_isdigit.c $(LIBFTDIR)/ft_isprint.c $(LIBFTDIR)/ft_memcpy.c \
    $(LIBFTDIR)/ft_memset.c $(LIBFTDIR)/ft_strchr.c $(LIBFTDIR)/ft_strdup.c \
    $(LIBFTDIR)/ft_strlen.c $(LIBFTDIR)/ft_strnstr.c $(LIBFTDIR)/ft_strrchr.c \
    $(LIBFTDIR)/ft_substr.c $(LIBFTDIR)/ft_tolower.c $(LIBFTDIR)/ft_toupper.c \
    $(LIBFTDIR)/ft_itoa.c $(LIBFTDIR)/ft_memchr.c $(LIBFTDIR)/ft_memmove.c \
    $(LIBFTDIR)/ft_putchar_fd.c $(LIBFTDIR)/ft_putendl_fd.c $(LIBFTDIR)/ft_putnbr_fd.c \
    $(LIBFTDIR)/ft_putstr_fd.c $(LIBFTDIR)/ft_split.c $(LIBFTDIR)/ft_striteri.c \
    $(LIBFTDIR)/ft_strjoin.c $(LIBFTDIR)/ft_strlcpy.c $(LIBFTDIR)/ft_strmapi.c \
    $(LIBFTDIR)/ft_strncmp.c $(LIBFTDIR)/ft_strtrim.c $(LIBFTDIR)/ft_memcmp.c \
    $(LIBFTDIR)/ft_strlcat.c $(LIBFTDIR)/ft_putunbr_fd.c $(LIBFTDIR)/ft_putunbr_base.c \
    $(LIBFTDIR)/ft_putulnbr_base.c $(LIBFTDIR)/ft_putptr.c \
    $(LIBFTDIR)/ft_lstnew.c $(LIBFTDIR)/ft_lstadd_front.c $(LIBFTDIR)/ft_lstsize.c \
    $(LIBFTDIR)/ft_lstlast.c $(LIBFTDIR)/ft_lstadd_back.c $(LIBFTDIR)/ft_lstdelone.c \
    $(LIBFTDIR)/ft_lstclear.c $(LIBFTDIR)/ft_lstiter.c $(LIBFTDIR)/ft_lstmap.c

LIBFT_HEADERS = $(LIBFTDIR)/libft.h
HEADERS = $(INCLUDES)/ft_printf.h $(LIBFT_HEADERS)

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

all: $(NAME)

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HEADERS)
	$(MAKE) -C $(LIBFTDIR) bonus

$(OBJS): $(HEADERS)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFTDIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re