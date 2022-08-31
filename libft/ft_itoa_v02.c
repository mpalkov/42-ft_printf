/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:27:38 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/16 16:20:18 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void *ft_calloc0(size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = 0;
	i = 0;
	ptr = malloc(nmbyte * size);
	if (ptr == 0)
		return (0);
	while (i < nmbyte * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

static	void ft_ifnegative(long *d, int *sign)
{
	*sign = 0;
	
	if (*d < 0)
	{
		*sign = 1;
		*d *= -1;
	}
	return ;
}

/* static	void ft_makeitoa(int len, char *num, int *sign, char *ptrres)
{
	int	i;

	i = len;
	while (len >= 0)
	{
		num[i - len + *sign] = ptrres[len];
		len--;
	}
} */

char	*ft_itoa(int n)
{
	int		len;
	char	res[10];
	char	*ptrres;
	char	*num;
	int		*sign;
	long	*d;

	len = 0;
	*sign = 0;
	ptrres = res;
	ft_ifnegative(d, sign);
	while (*d >= 10)
	{
		res[len++] = (char)(*d % 10 + '0');
		*d /= 10;
	}
	res[len] = (char)(*d % 10 + '0');
	num = (char *)ft_calloc0(sizeof(char), (size_t)(len + *sign) + 2);
	if (!num)
		return (0);
//	ft_makeitoa(len, num, sign, ptrres);
n = len;
	while (len >= 0)
	{
		num[n - len + *sign] = res[len];
		len--;
	}
	if (*sign == 1)
		num[0] = '-';
	return (num);
}
