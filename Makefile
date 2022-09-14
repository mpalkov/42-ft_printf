# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 16:12:00 by mpalkov           #+#    #+#              #
#    Updated: 2022/09/14 12:08:02 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

BONUS		=	.bonus

# ---- FILES -------------------------------------------------------------------

SRC_PRINTF	=	ft_printf.c

BONUS_SRC	=	ft_printf_bonus.c

UTLS_PRINTF	=	ft_printf_char_functions.c \
				ft_printf_num_functions.c \
				ft_printf_hex_ptr_functions.c

BONUS_FILES	=	ft_printf_utils_bonus.c

# ---- DIRECTORIES -------------------------------------------------------------

LIBFT_DIR	=	libft/

OBJ_DIR		=	obj/

INCL_DIR	=	includes/

SRC_DIR		=	src/

UTLS_DIR	=	utils/

# ---- COMMANDS  ---------------------------------------------------------------

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g -MMD -MP -MT $@ 

RM			=	rm -f

CP			=	cp -f

AR			=	ar -crs

# ---- RULES -------------------------------------------------------------------

LIBFT		=	$(LIBFT_DIR)libft.a

OBJ			=	$(addprefix $(OBJ_DIR),$(UTLS:.c=.o))

OBJ_NOBONUS	=	$(addprefix $(OBJ_DIR),$(SRC_NOBONUS:.c=.o))

OBJ_NOBONUS	+=	$(OBJ)

OBJ_BONUS	=	$(addprefix $(OBJ_DIR),$(SRC_BONUS:.c=.o))

OBJ_BONUS	+=	$(OBJ)

INCLUDE		=	-I$(INCL_DIR)

DEPS		=	$(addsuffix .d,$(basename $(OBJ)))

DEP_NOBONUS	=	$(addsuffix .d,$(basename $(OBJ_NOBONUS)))

DEP_BONUS	=	$(addsuffix .d,$(basename $(OBJ_BONUS)))

DEPS		+=	$(DEP_NOBONUS)

DEPS		+=	$(DEP_BONUS)

UTLS		=	$(addprefix $(UTLS_DIR),$(UTLS_PRINTF))

UTLS_BONUS	=	$(addprefix $(UTLS_DIR),$(BONUS_FILES))

SRC_NOBONUS	+=	$(addprefix $(SRC_DIR),$(SRC_PRINTF))

SRC_BONUS	+=	$(addprefix $(SRC_DIR),$(BONUS_SRC))

SRC_BONUS	+=	$(UTLS_BONUS)

SRC_BONUS	+=	$(UTLS)

all: make_libft $(NAME)

$(BONUS): $(OBJ_BONUS) $(LIBFT) $(INCL_DIR)
	$(RM) $(NAME)
	$(CP) $(LIBFT) ./$(NAME)
	$(AR) $(NAME) $(OBJ_BONUS) 

bonus: make_libft $(BONUS)
	touch $(BONUS)

make_libft:
	make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: %.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

-include $(DEPS)
$(NAME): $(OBJ) $(LIBFT) $(INCL_DIR) $(OBJ_NOBONUS)
	$(RM) $(NAME)
	$(CP) $(LIBFT) ./$(NAME)
	$(AR) $(NAME) $(OBJ_NOBONUS)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(BONUS) 

re: fclean all

cleantest:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME) $(BONUS) 

test: cleantest $(OBJ_BONUS) $(INCL_DIR)
	
.PHONY: all, clean, fclean, re
