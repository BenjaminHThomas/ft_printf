# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 11:11:38 by bthomas           #+#    #+#              #
#    Updated: 2024/04/14 15:44:44 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES	= ft_bzero.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_toupper.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_memset.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstclear.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_lstdelone.c \
		  ft_tolower.c

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

COMPILER = gcc

$(NAME):
	$(COMPILER) $(CFLAGS) -c $(CFILES) -I./
	ar -rc $(NAME) $(OFILES)

all: $(NAME)

bonus: all

clean:
	rm -f $(NAME)
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, flcean, re
