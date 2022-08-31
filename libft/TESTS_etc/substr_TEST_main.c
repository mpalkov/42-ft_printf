/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_TEST_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:51:51 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/07 13:49:02 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main()
{
	char str[] = "i just want this part #############";
 	size_t size = 20;
 	
	char *ret = ft_substr(str, 99, size);
	printf("returned:%s", ret);
	return(0);
}
