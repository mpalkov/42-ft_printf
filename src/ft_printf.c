/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:38:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/31 17:15:34 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>

int	ft_print_unsint(t_vars *vars, long nbr);
int	ft_print_HEX_case(t_vars *vars, long nbr);
int	ft_putchar(char c);

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

int	ft_print_str(t_vars *vars, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_print_char(vars, str[i++]) == -1)
			return (-1);
	}
	return (vars->lastreturn);
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

int	ft_pf_x(t_vars *vars)
{
	long	nbr;

	nbr = va_arg(vars->args, long);
	if (ft_print_HEX_case(vars, nbr) == -1)
		return (-1);

	return(vars->lastreturn);
}	

int	ft_print_HEX_case(t_vars *vars, long nbr)
{

	if (nbr > 16)
	{
		ft_print_HEX_case(vars, nbr / 16);
		ft_print_HEX_case(vars, nbr % 16);
	}
	else
	{
		if (nbr <= 9)
		{
			if (ft_print_char(vars, '0' + nbr) == -1)
				return (-1);
		}
		else
		{
			// vars->caseflag is char 'A' or 'a' so I can use it directly 
			if (ft_print_char(vars, vars->caseflag + nbr - 10))
				return (-1);
		}
	}
	return (vars->lastreturn);
}

int	ft_pf_p(t_vars *vars)
{
	long	nbr;

	nbr  = va_arg(vars->args, long);
	if (nbr == 0)
	{
		if (ft_print_str(vars, "0x0") == -1)
			return (-1);
	}
	else
	{
		vars->caseflag = 'a';
		if (ft_print_str(vars, "0x") == -1)
			return (-1);
		if (ft_print_HEX_case(vars, nbr) == -1)
			return (-1);
	}
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
	else if (*vars->format == 'x')
	{
		vars->caseflag = 'a';		
		return (ft_pf_x(vars));
	}
	else if (*vars->format == 'X')
	{
		vars->caseflag = 'A';
		return (ft_pf_x(vars));
	}
	else if (*vars->format == 'p')
		return (ft_pf_p(vars));
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

// The main function is ft_print_char which basically prints single char
// and handles errors and final length to be returned by ft_printf.
//
// The aim was to make the code modular (within my actual capacities),
// not repeating code so if a change needs to be done,
// it can be done in a single place.
// Another goal was make things more human-readable. Using NULL,
// macros like STDOUT_FILENO, etc. instead of bare numbers, for example.

