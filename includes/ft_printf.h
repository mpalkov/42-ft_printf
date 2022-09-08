/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:54:18 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/08 12:56:27 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

# define VALIDFORMAT "cspdiuxX%"

typedef struct s_vars
{
	char	*format;
	int		pos_s;
	int		printcount;
	char	*strn;
	va_list	args;
	int		lastreturn;
	char	caseflag;
}				t_vars;

int	ft_printf(const char *str, ...);
int	ft_print_char(t_vars *vars, char c);

#endif
