/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:38:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/25 17:26:56 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "utils/libft.h"
#include <unistd.h>
#include <stdio.h>

int	ft_print_c(t_vars *vars)
{
	int	c;

	c = va_arg(vars->args, int);
	vars->lastreturn = ft_putchar((char)c); 
	if (vars->lastreturn == -1)
		return (-1);
	else
		vars->printcount += vars->lastreturn;
	return (vars->lastreturn);
}

int	ft_print_perc(t_vars *vars)
{
	vars->lastreturn = ft_putchar('%'); 
	if (vars->lastreturn == -1)
		return (-1);
	else
		vars->printcount += vars->lastreturn;
	return (vars->lastreturn);
}


static int	ft_printit(t_vars *vars)
{
	if (*vars->format == '%')
		return (ft_print_perc(vars));
	else if (*vars->format == 'c')
		return (ft_print_c(vars)); 
	return (0);
}

static int	ft_gothrough(t_vars *vars)
{
	while (vars->strn[vars->pos_s])
	{
		// ft_strchr returns NULL if no match found or &str[i] if a match is found.
		vars->format = ft_strchr((const char *)VALIDFORMAT, (int)vars->strn[vars->pos_s + 1]);
		if (vars->strn[vars->pos_s] == '%' && !vars->format)
			return(-1);
		else if (vars->strn[vars->pos_s] == '%' && vars->format)
		{
			if (ft_printit(vars) == -1)
				return (-1);
			vars->pos_s++;
		}
		else if (vars->strn[vars->pos_s] != '%')
		{
			if (ft_putchar(vars->strn[vars->pos_s]) == -1)
				return (-1);
			vars->printcount++;
		}	
		vars->pos_s++;
	}
	return (0);
}

static void	ft_initvars(t_vars *vars, const char *str)
{
	vars->printcount = 0;
	vars->pos_s = 0;
//	vars->validformat = "cspdiuxX%"
	vars->strn = (char *)str;
}

int	ft_printf(const char *str, ...)
{
	// sys printf returns -1 if !str
	if (!str)
		return (-1);
	t_vars	vars;
	ft_initvars(&vars, str);
	va_start(vars.args, str);
	if (ft_gothrough(&vars) == -1)
	{
		va_end(vars.args);
		return (-1);
	}
	va_end(vars.args);
	return (vars.printcount);
}
