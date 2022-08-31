/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:33:16 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/13 14:06:43 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	text1[35] = "Life is great";

	printf("before memset: %s\n", text1);
	ft_memset(text1, 'X', 5 * sizeof(char));
	printf("after memset: %s\n", text1);
	return (0);
}
