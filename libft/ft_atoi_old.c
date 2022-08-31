/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:59:17 by mpalkov           #+#    #+#             */
/*   Updated: 2022/06/23 13:09:21 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	ifnegative;
	int	c;
// d borrar
	int	d;

	i = 0;
	ifnegative = 1;
	c = 0;
	j = 0;
	d = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] < '0' || '9' < str[i]) && str[i] != '+' &&  str[i] != '-')
		return (0);
	else
	{
	if (str[i] == '-' && (str[i + 1] >= '0' || str[i + 1] <= '9'))
	{
		ifnegative = -1;
		i++;
	}
	else if (str[i] == '+' && (str[i + 1] >= '0' || str[i + 1] <= '9'))
		i++;
	else if (str[i] < '0' || '9' < str[i])
		return (0);
	while (str[i + j] >= '0' && '9' >= str[i + j] && str[i + j] != 0)
			j++;
		while (--j > 0)
		{
//aqui me deja de cuadrar la posicion etc.
			d = (int)(str[i + j + 1]);
			c = c + ((int)(str[i + j + 1]) - '0') * (10 * j);
		}
		if (--j >= -1)
			c = (c + ((int)(str[i + j + 1]) - '0')) * ifnegative;
		return (c);
	}
}
