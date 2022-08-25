/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c_TEST_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:35:21 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/25 16:59:19 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int ft_printf(const char *str, ...);

int	main(void)
{	int	a;
	printf("...%c...\n", 'X');
	a = ft_printf(".%c.%%.", 'X');
	printf("\n%d\n", a);
	return (0);
}
