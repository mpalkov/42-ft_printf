/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:09:04 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/13 14:15:27 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	text1[35] = "Life is great ofddmfdm";

	printf("Before bzero: %s\n", text1);
	ft_bzero(text1, 10 * sizeof(char));
	printf("After bzero: %s\n", text1);
	return(0);
}
