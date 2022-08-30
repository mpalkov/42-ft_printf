/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c_TEST_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:35:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/30 11:36:43 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int ft_printf(const char *str, ...);

int	main(void)
{	int	a;
//	printf("...%c...\n", 'X');
//	a = ft_printf("..%%..%c..%s..", 'X', "Hola42");
	
	ft_printf("----- numbers %%d %%i %%n ------\n");
	a = ft_printf("424242 = %d\n0 = %i\n2147483647 = %d\n-2147483648 = %i\n2147483649 = %d", 424242, 0, 2147483647, -2147483648, 2147483649);
	printf("\n%d\n", a);

	ft_printf("----- HEX  %%x %%X %%p ------\n");
	
	return (0);
}
