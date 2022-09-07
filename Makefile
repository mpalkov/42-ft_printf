# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 16:12:00 by mpalkov           #+#    #+#              #
#    Updated: 2022/09/07 17:26:03 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

# ---- FILES -------------------------------------------------------------------

SRC_PRINTF	=	ft_printf.c
#			utils/ft_putchar.c \
#			utils/ft_putchar_fd.c \
#			utils/ft_strchr.c \
			
#			utils/libft.h
#			includes/ft_printf.h

# ---- DIRECTORIES -------------------------------------------------------------

LIBFT_DIR	=	libft/

OBJ_DIR		=	obj/

INCL_DIR	=	includes/

SRC_DIR		=	src/

LIBFT		=	$(LIBFT_DIR)libft.a

OBJ			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

INCLUDE		=	-I$(INCL_DIR)

DEPS		=	$(addsuffix .d,$(basename $(OBJ)))

SRCS		=	$(addprefix $(SRC_DIR),$(SRC_PRINTF))

# ---- COMMANDS  ---------------------------------------------------------------

# DEPS		=	$(SRCS:%.c=%.d)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -MMD -MP -MT $@ 

RM			=	rm -f

CP			=	cp -f

# ---- RULES -------------------------------------------------------------------

all: make_libft $(NAME)

make_libft:
	make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

-include $(DEPS)
$(NAME): $(OBJ) $(LIBFT) $(INCL_DIR)
	$(CP) $(LIBFT) ./$(NAME)
	ar -crs $(NAME) $(OBJ)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
