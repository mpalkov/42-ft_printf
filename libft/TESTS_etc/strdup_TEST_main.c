/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_TEST_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:54:27 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/06 10:39:20 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main()
{
	char	*ft_result1;
	char	*ft_result2;
	char	*ft_result3;
	char	*sysresult1;
	char	*sysresult2;
	char	*sysresult3;

	ft_result1 = ft_strdup("");
	ft_result2 = ft_strdup("sadfvbf");
	ft_result3 = ft_strdup("fdfjkdf\n353\t46");
	sysresult1 = strdup("");
	sysresult2 = strdup("sadfvbf");
	sysresult3 = strdup("fdfjkdf\n353\t46");
	printf("test1: \nsource:\"\"\nresult:%s\n\n", ft_result1); 
	printf("test2: \nsource:sadfvbf\nresult:%s\n\n", ft_result2);
	printf("test3: \nsource:fdfjkdf\n353\t46\nresult:%s\n\n", ft_result3);
	printf("STRCMP1:%d\n", strcmp(ft_result1, sysresult1));
	printf("STRCMP2:%d\n", strcmp(ft_result2, sysresult2));
	printf("STRCMP3:%d\n", strcmp(ft_result3, sysresult3));
	printf("0 == OK (no hay diferencia entre strings comparadas)\n");
	return (0);
}
