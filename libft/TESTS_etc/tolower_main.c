/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toilower_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:38:02 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/20 20:01:39 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	main(void)
{
	int a = 'A';
	int b;

	while (a <= 'Z')
	{
		write(1, &a, 1);
		b = ft_tolower(a);
		write(1, &b, 1);
		a++;
	}
	write(1, "\n", 1);
}
