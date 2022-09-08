/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:38:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/08 12:44:46 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_print_unsint(t_vars *vars, long nbr);
int	ft_print_hex_case(t_vars *vars, unsigned long long nbr);
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
	if (!s)
	{
		if (ft_print_str(vars, "(null)") == -1)
			return (-1);
		else
			return (vars->lastreturn);
	}
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
	long	nbr;

	nbr = va_arg(vars->args, unsigned int);
	return (ft_print_unsint(vars, nbr));
}

int	ft_print_unsint(t_vars *vars, long nbr)
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
	unsigned int	nbr;

	nbr = va_arg(vars->args, unsigned int);
	if (ft_print_hex_case(vars, (unsigned long long)nbr) == -1)
		return (-1);
	return (vars->lastreturn);
}	

// This is a recursive function. This way I can print number directly
// in the right order wihout the need to save number by number in a 
// intermediate string and then print it in reverse order.
// vars->caseflag is char 'a' or 'A' so I can use the same funcion for %x and %X
int	ft_print_hex_case(t_vars *vars, unsigned long long nbr)
{
	if (nbr >= 16)
	{
		if (ft_print_hex_case(vars, nbr / 16) == -1)
			return (-1);
		if (ft_print_hex_case(vars, nbr % 16) == -1)
			return (-1);
	}
	else
	{
		if (nbr <= 9)
		{
			if (ft_print_char(vars, '0' + nbr) == -1)
				return (-1);
		}
		else if (nbr <= 15)
		{
			if (ft_print_char(vars, vars->caseflag + nbr - 10) == -1)
				return (-1);
		}
	}
	return (vars->lastreturn);
}

int	ft_pf_p(t_vars *vars)
{
	unsigned long long	nbr;

	nbr = va_arg(vars->args, unsigned long long);
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
		if (ft_print_hex_case(vars, nbr) == -1)
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

// This function goes through the string char by char and prints char by char
// from the string, or checks the format modifier if '%' found in the string.
// ft_strchr returns NULL if no match found or &str[i] if a match is found.
static int	ft_gothrough(t_vars *vars)
{
	while (vars->strn[vars->pos_s])
	{
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
	vars->strn = (char *)str;
}

// sys printf returns -1 if (!str)
int	ft_printf(const char *str, ...)
{
	t_vars	vars;

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
// Another goal was to make things more human-readable. Using NULL,
// macros like STDOUT_FILENO, etc. instead of bare numbers, for example.
//
// Error Handling:
// Eevery function returns int, so I can control errors by returning -1
// and calling the functions in a
//  if (ft_function(args) == -1)
//  	return (-1);
//
//	vars->validformat = "cspdiuxX%"
//	validformat is defined in ft_printf.h now
