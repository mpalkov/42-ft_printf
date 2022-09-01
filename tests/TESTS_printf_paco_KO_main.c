/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c_TEST_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:35:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/09/01 17:41:33 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *str, ...);

int	main(void)
{	int	a;

/*
	ft_printf("------ %%p --------\n\n");
	printf("%%p sys printf %%p = %p\n", NULL);
	ft_printf("%%p  ft_printf %%p = %p\n", NULL);
*/

	
/*	ft_printf("------ %%s ---------\n\n");
	a = printf("%s", NULL);
	printf("\n   printf return = %d\n", a);
	a = ft_printf("%s", NULL);
	printf("\nft_printf return = %d\n", a);
	printf("\n");
	a = printf(" NULL %s NULL ", NULL);
	printf("\n   printf return = %d\n", a);
	a = ft_printf(" NULL %s NULL ", NULL);
	printf("\nft_printf return = %d\n", a);


	ft_printf("------ %%p ---------\n\n");
	a = printf("%p", &a);
	printf("\n   printf return = %d\n", a);
	a = ft_printf("%p", &a);
	printf("\nft_printf return = %d\n", a);
	printf("\n");
	a = printf(" %p ", "");
	printf("\n   printf return = %d\n", a);
	a = ft_printf(" %p ", "");
	printf("\nft_printf return = %d\n", a);
*/


	ft_printf("------ %%x ---------\n\n");
	a = printf(" %lx ", LONG_MAX);
	printf("\n   printf return = %d\n", a);
	a = ft_printf(" %x ", LONG_MAX);
	printf("\nft_printf return = %d\n", a);
	a = printf(" %lx ", LONG_MIN);
	printf("\n   printf return = %d\n", a);
	a = ft_printf(" %x ", LONG_MIN);
	printf("\nft_printf return = %d\n", a);
	a = printf("%llx", 9223372036854775807LL);
	printf("\n   printf return = %d\n", a);
	a = ft_printf("%x", 9223372036854775807LL);
	printf("\nft_printf return = %d\n", a);
	a = printf("dgs%xxx", 10);
	printf("\n   printf return = %d\n", a);
	a = ft_printf("dgs%xxx", 10);
	printf("\nft_printf return = %d\n", a);

/*	ft_printf("------ %%x ---------\n\n");
	a = printf(" %x ", 1081101470);
	printf("\n   printf return = %d\n", a);
	a = ft_printf(" %x ", 1081101470);
	printf("\nft_printf return = %d\n", a);
*/

	ft_printf("------ RANDOM ---------\n\n");

	a = printf("+%pr%X%%^P&%d@$c6\fB0xr%x*M_/}KUWB%d\vkhd$", (void *)1822885846497357237, 1433406048, -980206522, 1081101470, 963657664) ;
	printf("\n   printf return = %d\n", a);
	a = ft_printf("+%pr%X%%^P&%d@$c6\fB0xr%x*M_/}KUWB%d\vkhd$", (void *)1822885846497357237, 1433406048, -980206522, 1081101470, 963657664) ;
	printf("\nft_printf return = %d\n", a);
	a = printf("wz;*GTQ$jx%%dK{A/*D;%s=-2%i%%\n+%pr%X%%^P&%d@$c6\fB0xr%x*M_/}KUWB%d\vkhd$", "\ndV>v<\tuaCPFs\r\\-y8%\\ p1F+&y6Mx|s2%2m&&'+|B2Z\rg58P]2,VfFBg)SE:S\t)m0", -308074711, (void *)1822885846497357237, 1433406048, -980206522, 1081101470, 963657664);
	printf("\n   printf return = %d\n", a);
	a = ft_printf("wz;*GTQ$jx%%dK{A/*D;%s=-2%i%%\n+%pr%X%%^P&%d@$c6\fB0xr%x*M_/}KUWB%d\vkhd$", "\ndV>v<\tuaCPFs\r\\-y8%\\ p1F+&y6Mx|s2%2m&&'+|B2Z\rg58P]2,VfFBg)SE:S\t)m0", -308074711, (void *)1822885846497357237, 1433406048, -980206522, 1081101470, 963657664);
	printf("\nft_printf return = %d\n", a);

// "wz;*GTQ$jx%%dK{A/*D;%s=-2%i%%\n+%pr%X%%^P&%d@$c6\fB0xr%x*M_/}KUWB%d\vkhd$", "\ndV>v<\tuaCPFs\r\\-y8%\\ p1F+&y6Mx|s2%2m&&'+|B2Z\rg58P]2,VfFBg)SE:S\t)m0", -308074711, (void *)1822885846497357237, 1433406048, -980206522,1081101470, 963657666

		
	return (0);
}
