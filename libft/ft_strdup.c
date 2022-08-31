/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:14:58 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/06 11:01:10 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*newstr;
	size_t	i;

	len = 0;
	newstr = 0;
	i = 0;
	while (str[i])
		len = ++i;
	newstr = malloc(len + 1);
	if (newstr == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}

/* MAN STRDUP
 * The strdup() function allocates sufficient memory for a copy of the string s1,
 * does the copy, and returns a pointer to it.  The pointer may subsequently
 * be used as an argument to the function free(3).

 * If insufficient memory is available, NULL is returned.

 * The strndup() function copies at most n characters from the string s1
 * always NUL terminating the copied string. */

/* First length of original string is determined, then memory
 * is allocated by malloc with size + 1 because string count starts at 0,
 * but malloc starts counting at 1. */
