/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:53:04 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/09 15:54:33 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_flagcheck(t_vars *vars)
{
	if (*vars->format == '#' && (vars->strn[vars->pos_s + 2] == 'x'))
	{
		vars->caseflag = 'a';
		return (ft_print_hex_bonus(vars));
	}
	else if (*vars->format == '#' && (vars->strn[vars->pos_s + 2] == 'X'))
	{
		vars->caseflag = 'A';
		return (ft_print_hex_bonus(vars));
	}
	else if (*vars->format == ' ' && (vars->strn[vars->pos_s + 2] == 'd' \
				|| vars->strn[vars->pos_s + 2] == 'i'))
		return (ft_print__d(vars));
	else if (*vars->format == '+' && (vars->strn[vars->pos_s + 2] == 'd' \
				|| vars->strn[vars->pos_s + 2] == 'i'))
		return (ft_print_plus_d(vars));
	else if ((*vars->format == ' ' && vars->strn[vars->pos_s + 2] == '+' && \
			vars->strn[vars->pos_s + 3] == 'd') || (*vars->format == ' ' && \
			vars->strn[vars->pos_s + 2] == '+' && vars->strn[vars->pos_s + 3] \
			== 'i') || (*vars->format == '+' && vars->strn[vars->pos_s + 2] == \
			' ' && vars->strn[vars->pos_s + 3] == 'd') || (*vars->format == '+' \
			&& vars->strn[vars->pos_s + 2] == ' ' \
			&& vars->strn[vars->pos_s + 3] == 'i'))
		return (ft_print_plus_d(vars));
	return (vars->lastreturn);
}

int	ft_print_hex_bonus(t_vars *vars)
{
	unsigned int	nbr;

	nbr = va_arg(vars->args, unsigned int);
	if (ft_print_char(vars, '0') == -1)
		return (-1);
	if (nbr == 0)
		return (vars->lastreturn);
	else
	{
		//esto imprime X o x segun caseflag
		if (ft_print_char(vars, vars->caseflag + 23) == -1)
			return (-1);
		if (ft_print_hex_case(vars, (unsigned long long)nbr) == -1)
			return (-1);
		return (vars->lastreturn);
	}
	return (vars->lastreturn);
}

int	ft_print__d(t_vars *vars)
{
	long	nbr;

	nbr = va_arg(vars->args, int);
	if (nbr >= 0)
	{
		if (ft_print_char(vars, ' ') == -1)
			return (-1);
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		if (ft_print_char(vars, '-') == -1)
			return (-1);
	}
	if (ft_print_unsint(vars, nbr) == -1)
		return (-1);
	return (vars->lastreturn);
}

int	ft_print_plus_d(t_vars *vars)
{
	long	nbr;

	nbr = va_arg(vars->args, int);
	if (nbr >= 0)
	{
		if (ft_print_char(vars, '+') == -1)
			return (-1);
	}
	else if (nbr < 0)
	{
		if (ft_print_char(vars, '-') == -1)
			return (-1);
		nbr *= -1;
		if (ft_print_unsint(vars, nbr) == -1)
			return (-1);
	}
	return (vars->lastreturn);
}
