/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:38:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/30 12:48:28 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "utils/libft.h"
#include <unistd.h>
#include <stdio.h>

int ft_print_unsint(t_vars *vars, long nbr);

int	ft_print_char(t_vars *vars, char c)
{
	vars->lastreturn = ft_putchar (c);
	if (vars->lastreturn == -1)
		return (-1);
	else
		vars->printcount += vars->lastreturn;
	return (vars->lastreturn);
}

int	ft_pf_c(t_vars *vars)
{
	int	c;

	c = va_arg(vars->args, int);
	return (ft_print_char(vars, (char)c));
}

int	ft_pf_perc(t_vars *vars)
{
	return (ft_print_char(vars, '%'));
}

int	ft_pf_s(t_vars *vars)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(vars->args, char *);
	while (s[i])
	{
		if (ft_print_char(vars, s[i]) == -1)
			return (-1);
		i++;
	}
	return (vars->lastreturn);
}

int	ft_pf_d(t_vars *vars)
{
	long	nbr;
	nbr = va_arg(vars->args, int);

	if (nbr < 0)
	{
		nbr *= -1;
		if (ft_print_char(vars, '-') == -1)
			return (-1);
	}
	return (ft_print_unsint(vars, nbr));
}

int	ft_pf_u(t_vars *vars)
{
	long nbr;

	nbr = va_arg(vars->args, unsigned int);
	return (ft_print_unsint(vars, nbr));
}

int ft_print_unsint(t_vars *vars, long nbr)
{
	int		pos;
	char	digit[10];

	pos = 0;
	while (nbr >= 10)
	{
		digit[pos++] = nbr % 10 + '0';
		nbr /= 10;
	}
	digit[pos] = nbr % 10 + '0';
	while (pos >= 0)
		if (ft_print_char(vars, digit[pos--]) == -1)
			return (-1);
	return (vars->lastreturn);
}


static int	ft_printcheck(t_vars *vars)
{
	if (*vars->format == '%')
		return (ft_pf_perc(vars));
	else if (*vars->format == 'c')
		return (ft_pf_c(vars));
	else if (*vars->format == 's')
		return (ft_pf_s(vars));
	else if (*vars->format == 'd' || *vars->format == 'i')
		return (ft_pf_d(vars));
	else if (*vars->format == 'u')
		return (ft_pf_u(vars));
	return (0);
}

static int	ft_gothrough(t_vars *vars)
{
	while (vars->strn[vars->pos_s])
	{
		// ft_strchr returns NULL if no match found or &str[i] if a match is found.
		vars->format = ft_strchr((const char *)VALIDFORMAT,
				(int)vars->strn[vars->pos_s + 1]);
		if (vars->strn[vars->pos_s] == '%' && !vars->format)
			return (-1);
		else if (vars->strn[vars->pos_s] == '%' && vars->format)
		{
			if (ft_printcheck(vars) == -1)
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
//	validformat is defined in ft_printf.h now
	vars->strn = (char *)str;
}

int	ft_printf(const char *str, ...)
{
	t_vars	vars;

	// sys printf returns -1 if !str
	if (!str)
		return (-1);
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

// The basic function is ft_print_char which basically prints single char
// and handles errors and final length to be returned.

