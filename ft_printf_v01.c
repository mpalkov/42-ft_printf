/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:38:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/11 17:40:52 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct	s_vars
{
	char	format;
	ssize_t	pos_s;
	int		printcount;
	char	*validformat;

}				t_vars;

int	ft_printf(const char *str, ...)
{
	t_vars	vars;

	vars.printcount = 0;
	vars.pos_s = 0;
	vars.validformat = "cspdiuxX%";
	while (str[vars.pos_s])
	{
		vars.format = str[vars.pos_s + 1];
		if (str[vars.pos_s] == '%' && vars.format);
		{
			if (!ft_strchr((const char *)vars.validformat, (int)vars.format));
				return (-1);

		}
			

	}
	
	return (vars.printcount);
}
