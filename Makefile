# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 14:29:18 by bthomas           #+#    #+#              #
#    Updated: 2024/04/15 10:52:55 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CFILES			= ft_printf.c \
				  ft_fmtparse.c \
				  ft_utils.c

OBJ_DIR			= objs
OFILES			= $(addprefix $(OBJ_DIR)/,$(CFILES:.c=.o))

CFLAGS			= -Wall -Werror -Wextra
COMPILER		= gcc
AR				= ar
ARFLAGS			= rcs

LIBFT_PATH		= ./libft
LIBFT			= $(LIBFT_PATH)/libft.a
LIBFT_OBJ_DIR	= $(LIBFT_PATH)/$(OBJ_DIR)
LIBFT_CFILES	= $(wildcard $(LIBFT_PATH)/*.c)
LIBFT_OFILES	= $(addprefix $(LIBFT_OBJ_DIR)/,$(notdir $(LIBFT_CFILES:.c=.o)))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(LIBFT_OBJ_DIR)/%.o: $(LIBFT_PATH)/%.c
	@mkdir -p $(@D)
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES) $(LIBFT)
	$(AR) $(ARFLAGS) $@ $^

$(LIBFT): $(LIBFT_OFILES)
	@mkdir -p $(LIBFT_OBJ_DIR)
	$(AR) $(ARFLAGS) $@ $^

all: $(NAME)

bonus: all

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBFT_OBJ_DIR)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re
