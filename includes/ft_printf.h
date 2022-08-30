/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:54:18 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/30 16:46:29 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

# define VALIDFORMAT "cspdiuxX%"
# define HEX_LOWERCHARSET "0123456789abcdef"
# define HEX_UPPERCASECHARSET "0123456789ABCDEF"
typedef struct	s_vars
{
	char	*format;
	int		pos_s;
	int		printcount;
//	char	*validformat;
	char	*strn;
	va_list	args;
	int		lastreturn;
	char	caseflag;
}				t_vars;

#endif
