/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c_TEST_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:35:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/31 12:34:28 by mpalkov          ###   ########.fr       */
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

	ft_printf("----- HEX  %%x %%X %%p ------\n\n");
	ft_printf("%%x of 999999 = %x\n%%x of 999999 = %X\n", 999999, 999999);


	ft_printf("------ %%p ---------\n\n");
	printf("%%p sys printf %%p = %p\n", NULL);
	ft_printf("%%p  ft_printf %%p = %p\n", NULL);
		
	return (0);
}
