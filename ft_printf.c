/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:38:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/23 18:00:28 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h/ft_printf.h"
#include "libft/h/libft.h"
#include <unistd.h>
#include <stdio.h>

int static	ft_gothrough(t_vars *vars)
{
	while (vars->strn[vars->pos_s])
	{
		// ft_strchr returns NULL if no match found or &str[i] if a match is found.
	//	vars->format = ft_strchr((const char *)vars->validformat, (int)strn[vars->pos_s + 1])
		if (vars->strn[vars->pos_s] == '%' && !vars->format)
			return(-1);
		else if (vars->strn[vars->pos_s] == '%' && vars->format)
			ft_printit(&vars);
		else if (vars->strn[vars->pos_s] != '%')
		{
			ft_putchar_fd(vars->strn[vars->pos_s], STDOUT_FILENO);
			vars->printcount++;
		}	
		vars->pos_s++;
	}
	return (0);
}

void static	ft_initvars(t_vars *vars, const char *str)
{
	vars->printcount = 0;
	vars->pos_s = 0;
	vars->validformat = "cspdiuxX%"
	vars.strn = (char *)str;
}

int static	ft_printit(t_vars *vars)
{
	if (vars->format == '%')
		return (ft_putchar_fd('%' ,STDOUT_FILENO) == -1)
	else if (vars->format == 'c')
		return (ft_putchar_fd(
	return (0);
}

int	ft_printf(const char *str, ...)
{
	// sys printf returns -1 if !str
	if (!str)
		return (-1);
	t_vars	vars;
	ft_initvars(&vars, &str);
	va_start(vars.args, str);
	
	ft_gothrough(&vars);
	va_end(ap);
	return (vars.printcount);
}
