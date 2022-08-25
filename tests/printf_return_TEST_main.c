/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_return_TEST_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:37:18 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/24 12:12:46 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{	
	int a;
	a = printf("%%s..%s..\n", NULL);
	printf("%d\n", a);
	a = printf("%%c..%c..\n", 90);
	printf("%d\n", a);
	a = printf("%%p..%p..\n", NULL);
	printf("%d\n", a);
	return (a);
}
