/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:08:04 by mpalkov           #+#    #+#             */
/*   Updated: 2022/06/17 17:37:39 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main()
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
//	char * empty = (char*)"";
	char *ft_str = 0;
	char *str = 0;

	if (ft_strnstr(haystack, needle, 0) == strnstr(haystack, needle, 0))
		printf("(haystack, needle, 0) - ok\n");
	else
		printf("(haystack, needle, 0) - KO\n");
	
	if (ft_strnstr(haystack, "a", -1) == strnstr(haystack, "a", -1))
	{
		printf("(haystack, needle, -1) - ok\n");
		printf("output ft_: %s\noutput str: %s\n", ft_str, str);
	}
	else
	{
		printf("(haystack, needle, -1) - KO\n");
		ft_str = ft_strnstr(haystack, needle, -1);
		str = strnstr(haystack, needle, -1);
		printf("output ft_: %s\noutput str: %s\n", ft_str, str);
	}	
	write(1, "\n", 1);
	return (0);
}
