/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:38:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/20 16:49:42 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

typedef struct	s_vars
{
	char	*format;
	ssize_t	pos_s;
	int	printcount;
	char	*validformat;
	char	*strn;
}		t_vars;

int static	ft_gothrough(int *count, t_vars *vars)
{
	while (vars->strn[vars->pos_s])
        {
                vars->format = ft_strchr((const char *)vars->validformat, (int)strn[vars->pos_s + 1])
                if (vars->strn[vars->pos_s] == '%' && !vars->format)
		{
                        return(-1);
                }
		if (vars->strn[vars->pos_s] == '%' && vars->format)
                        ft_printit();
                if (vars->strn[vars->pos_s] != '%')
                        ft_putchar_fd(*(vars->strn[vars->pos_s]), STDOUT_FILENO);
        }
}

int static	ft_printit(t_vars *vars)
{
// int *count, char *format, char *strn, size_t pos_s
}

int	ft_printf(const char *str, ...)
{
	if (!str)
		return (-1);
	t_vars	vars;
	va_list	ap;

	va_start(ap, str);
	vars.printcount = 0;
	vars.pos_s = 0;
	vars.validformat = "cspdiuxX%";
//revisar si puedo hacerlo asi (siguiente linea de codigo)  o tengo que usar ft_strcpy.
//en principio si se puede hacer y te leva a la misma direccion del string original.
	vars.strn = (char *)str;
	while (strn[vars.pos_s])
	{
		if (vars.strn[vars.pos_s++] != '%')
			ft_putchar_fd(

		vars.format = ft_strchr((const char *)vars.validformat, (int)strn[vars.pos_s + 1]) 
		if (strn[vars.pos_s] == '%' && !vars.format)
			return(-1);
		if (strn[vars.pos_s] == '%' && vars.format)
			ft_printit();
		if (strn[vars.pos_s] != '%')
			ft_putchar(*(strn[vars.pos_s]));
	}
	
	return (vars.printcount);
}
