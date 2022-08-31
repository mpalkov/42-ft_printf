/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoaTEST.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:47:00 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/18 14:59:20 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_itoatest(int n)
{ 
	char	*num;

	printf("----- TEST\n\nn = %d\n", n);
	num = ft_itoa(n);			
	printf("ft_toa = %s\n\n", num);
	return (num);
}

int	main ()
{
	char	*num;

	num = ft_itoatest(42);
	num = ft_itoatest(0);
	num = ft_itoatest(-42);
	num = ft_itoatest(-2147483648);
	num = ft_itoatest(2147483647);

	return (0);
}
