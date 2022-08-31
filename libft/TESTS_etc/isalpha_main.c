/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:13:04 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/12 16:58:35 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <unistd.h>

int	main(void)
{
	int	c;
//	int	result;

	c = 'y';
//	result = ft_isalpha(c);
	write(1, &c, 1);
	write(1, " = input\n", 9);
//	write(1, " = resullt\n", 11);
	return (0);
}
