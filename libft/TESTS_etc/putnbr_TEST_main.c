/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_TEST_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:13:40 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/15 13:34:28 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_test(int n)
{
	printf("--------TEST %d-------\n", n);
	ft_putnbr_fd(n, 1);
	printf("\n\n\n");

	return ;
}

int	main()
{
	int	n = 0;
	ft_test(n);
	
	n = 42;
	ft_test(n);

	n = -2147483648;
	ft_test(n);

	n = -2147483647;
	ft_test(n);

	n = 2147483647;
	ft_test(n);

	n = -2147483648LL;
	ft_test(n);

	n = 7;
	ft_test(n);
/*	n = ;
	ft_test(n);
	n = ;
	ft_test(n);
	n = ;
	ft_test(n); */
return (0);
}
