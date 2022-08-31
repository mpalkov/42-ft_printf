/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:38:13 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/20 16:01:21 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_calloc0strlen(char const *s, char *newstr)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	newstr = (char *)malloc(i + 2);
	if (!newstr)
		return (0);
	while (i > 0)
		newstr[i++] = 0;
	return (newstr);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*newstr;
	
	newstr = 0;
//	i = ft_strlen(s) + 1;
	i = 0;
	newstr = ft_calloc0strlen(s, newstr);
	if (!newstr)
		return (0);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}


// FT_STRMAPI Applies the function ’f’ to each character of the 
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.
