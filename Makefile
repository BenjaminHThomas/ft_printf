# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 14:29:18 by bthomas           #+#    #+#              #
#    Updated: 2024/05/26 16:18:15 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CFILES			= ft_printf.c \
				  buff_mgmt.c \
				  ft_utils1.c \
				  ft_utils2.c \
				  parse_fmt.c \
				  print_cs.c \
				  print_p.c \
				  print_u.c \
				  print_x.c \
				  print_di.c

OBJ_DIR			= objs
OFILES			= $(addprefix $(OBJ_DIR)/,$(CFILES:.c=.o))

CFLAGS			= -Wall -Werror -Wextra -g3
COMPILER		= cc
AR				= ar
ARFLAGS			= rcs

LIBFT_LIB		= libft.a
LIBFT_PATH		= ./libft/
LIBFT			= $(LIBFT_PATH)$(LIBFT_LIB)

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(LIBFT):
	echo "Making libft..."
	@$(MAKE) -C $(LIBFT_PATH)

$(OBJ_DIR)%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES) $(LIBFT)
	$(AR) $(ARFLAGS) $(NAME) $(OFILES) $(LIBFT)

clean:
	echo "Cleaning objects..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	echo "Removing program..."
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
