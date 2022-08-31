/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:17:03 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/16 13:49:40 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	source[] = "jnfdknndjkdfnkdjn";
	char	destin[] = "oooooo";

	memcpy(destin, source, 2);
	printf("memcpy: %s\n", destin);
	ft_memcpy(destin, source, 2);
	printf("ft_memcpy: %s\n", destin);
	return (0);
}
