/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:48:34 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/14 12:14:12 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include "ft_printf.h"

# define HEXFLAGS "#"
# define DECFLAGS " +"

int			ft_print_hex_bonus(t_vars *vars);
int			ft_print__d(t_vars *vars);
int			ft_print_plus_d(t_vars *vars);

#endif
