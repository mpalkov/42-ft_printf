/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_TEST_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:12:02 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/06 14:07:58 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"
#include <limits.h>

int	main(void)
{
	int a = 0;




	printf("----Strict-----\n\n");
	a = printf("%x", -10);
	printf("\nprintf returned: %d\n", a);
	a = ft_printf("%x", -10);
	printf("\nft_printf returned: %d\n", a);

/*
	printf("-------\n\n");	
	a = printf("%c(Je%cQL\nX%cw.$\.Tw&s%XLPVL+].;\r}%xp95%%b\n>Uq\fIq<@%xO%uTz)z2~]U)z", -393713348, -794307569, 1498073839, 1403461169, 801550109, 123796988, -595412577);
	printf("\nprintf returned: %d\n", a);
	a = ft_printf("%c(Je%cQL\nX%cw.$\.Tw&s%XLPVL+].;\r}%xp95%%b\n>Uq\fIq<@%xO%uTz)z2~]U)z", -393713348, -794307569, 1498073839, 1403461169, 801550109, 123796988, -595412577);
	printf("\nft_printf returned: %d\n", a);

	printf("-------\n\n");	
	a = printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0,
-42);
	printf("\nprintf returned: %d\n", a);
	a = ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0,
-42);
	printf("\nft_printf returned: %d\n", a);

	printf("-------\n\n");	
	a = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42,
42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\nprintf returned: %d\n", a);
	a =ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42,
42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\nft_printf returned: %d\n", a);

	printf("-------\n\n");	
	a = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", 42, 42 ,42 ,42,
42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\nprintf returned: %d\n", a);
	a =ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", 42, 42 ,42 ,42,
42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\nft_printf returned: %d\n", a);

*/
/*	
	printf("-------\n\n");	
	a = printf();
	printf("\nprintf returned: %d\n", a);
	ft_printf();
	printf("\nft_printf returned: %d\n", a);

	printf("-------\n\n");	
	a = printf();
	printf("\nprintf returned: %d\n", a);
	ft_printf();
	printf("\nft_printf returned: %d\n", a);

	printf("-------\n\n");	
	a = printf();
	printf("\nprintf returned: %d\n", a);
	ft_printf();
	printf("\nft_printf returned: %d\n", a);

	printf("-------\n\n");	
	a = printf();
	printf("\nprintf returned: %d\n", a);
	ft_printf();
	printf("\nft_printf returned: %d\n", a);
	
	printf("-------\n\n");	
	a = printf();
	printf("\nprintf returned: %d\n", a);
	ft_printf();
	printf("\nft_printf returned: %d\n", a);
*/

/*	
	printf("-------\n\n");	
	a = printf();
	printf("\nprintf returned: %d\n", a);
	ft_printf();
	printf("\nft_printf returned: %d\n", a);
*/
	return (0);
}
