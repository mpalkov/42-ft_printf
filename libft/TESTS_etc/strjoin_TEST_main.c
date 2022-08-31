/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_TEST_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:21:26 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/11 12:50:44 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main ()
{
	char	*s1 = "Hello! My name is";
	char	*s2 = "";
	char	*s3 = " 42.";
	char	*result = ft_strjoin(ft_strjoin(s1, s2), s3);

	if (!strcmp(result, "Hello! My name is 42."))
	{
		free(result);
		printf("OK\n");
		return (0);
	}
	printf("KO\nExpected: Hello! My name is 42.\nReturned: %s\n", result);
	free(result);
	return (0);
}




