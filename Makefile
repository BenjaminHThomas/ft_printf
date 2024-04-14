# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 14:29:18 by bthomas           #+#    #+#              #
#    Updated: 2024/04/14 15:33:00 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ./*.c

OFILES = ./*.o

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

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

.PHONY: all bonus clean fclean re
