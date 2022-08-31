/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:02:45 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/13 11:43:35 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Esto me da:
 mpalkov@cbr8s1 01-Libft % gcc -Wall -Werror -Wextra ft* isalnum_main.c | ./a.out
y = input
1 = resullt
mpalkov@cbr8s1 01-Libft % gcc -Wall -Werror -Wextra ft* isalnum_main.c | ./a.out
/ = input
0 = resullt
*/

#include "libft.h"
#include <unistd.h>

int	main(void)
{
	int	c;
	int	result;

	c = '9';
	result = ft_isalnum(c) + '0';
	write(1, &c, 1);
	write(1, " = input\n", 9);
	write(1, &result, 1);
	write(1, " = resullt\n", 11);
	return (0);
}
