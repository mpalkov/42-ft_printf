# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 16:12:00 by mpalkov           #+#    #+#              #
#    Updated: 2022/09/09 15:54:30 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

# ---- FILES -------------------------------------------------------------------

SRC_PRINTF	=	ft_printf.c

SRC_BONUS	=	ft_printf_bonus.c

UTLS_PRINTF	=	ft_printf_char_functions.c \
				ft_printf_num_functions.c \
				ft_printf_hex_ptr_functions.c

UTLS_BONUS	=	ft_printf_utils_bonus.c

# ---- DIRECTORIES -------------------------------------------------------------

LIBFT_DIR	=	libft/

OBJ_DIR		=	obj/

INCL_DIR	=	includes/

SRC_DIR		=	src/

UTLS_DIR	=	utils/

# ---- COMMANDS  ---------------------------------------------------------------

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -MMD -MP -MT $@ 

RM			=	rm -f

CP			=	cp -f

# ---- RULES -------------------------------------------------------------------

LIBFT		=	$(LIBFT_DIR)libft.a

OBJ			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

INCLUDE		=	-I$(INCL_DIR)

DEPS		=	$(addsuffix .d,$(basename $(OBJ)))

UTLS		=	$(addprefix $(UTLS_DIR),$(UTLS_PRINTF))

SRCS		+=	$(addprefix $(SRC_DIR),$(SRC_PRINTF))

#SRCS		+=	$(addprefix $(UTLS_DIR),$(UTLS_PRINTF))
SRCS		+=	$(UTLS)

SRCS_BONUS	+=	$(SRCS)

SRCS_BONUS	+=	$(addprefix $(SRC_DIR),$(SRC_BONUS))

SRCS_BONUS	+=	$(addprefix $(UTLS_DIR),$(UTLS_BONUS))

all: make_libft $(NAME)



bonus:
ACABAR DE DEFINIR ESTO



make_libft:
	make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c Makefile
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
