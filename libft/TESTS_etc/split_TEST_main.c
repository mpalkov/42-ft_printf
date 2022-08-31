/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_TEST_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:53:49 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/20 15:44:04 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_splittest(char const *s, char c)
{
	char	**mysplit;
	size_t	i;	
	
	i = 0;
	printf("---TEST---\n\ns = \"%s\"\nchar = \"%c\"\nResultado:\n", s, c);
	mysplit = ft_split(s, c);
	while (mysplit[i])
	{
		printf("string %zu = \"%s\"\n", i, mysplit[i]);
		i++;
	}
	printf("\n");
	return ;
}

int	main (void)
{
	ft_splittest("aaacocoalocoaaa123a", 'a');
	ft_splittest("", ' ');
	ft_splittest("42", 'a');
	ft_splittest("aaa42", 'a');
	ft_splittest("\0aa\0bbb", '\0');
	return (0);
}
