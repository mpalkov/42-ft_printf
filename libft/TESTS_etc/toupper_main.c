/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:38:02 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/20 19:59:48 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	main(void)
{
	int a = 'a';
	int b;

	while (a <= 'z')
	{
		write(1, &a, 1);
		b = ft_toupper(a);
		write(1, &b, 1);
		a++;
	}
	write(1, "\n", 1);
}
