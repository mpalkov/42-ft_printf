/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:23:12 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/12 13:53:01 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int ft_charcmp(char a, char const *set, size_t setlen)
{
	size_t j;

	j = 0;
	while (j < setlen)
	{
		if (a == set[j])
			return (1);
		j++;
	}
	return (0);
}

static	char *ft_calloc0(char *newstr, size_t size)
{
	size_t	i;
	i = 0;
	newstr = malloc (size + 1);
	if (!newstr)
		return (0);
	while (i <= size)
		newstr[i++] = 0;
	return (newstr); 
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	setlen;
	size_t	i;
//	size_t	j;
	size_t	len;
	size_t	trimstart;
	size_t	trimend;
	char	*newstr;

	setlen = ft_strlen(set);
	len = ft_strlen(s1);
	i = 0;
//	j = 0;
	trimstart = 0;
	trimend = len - 1;
	newstr = 0;
	if (!s1)
		return (0);
	while (s1[i] && i < len)
	{
		if ((ft_charcmp(s1[i], set, setlen)) && (i == 0 || i - 1 == trimstart))
		{
			trimstart = i;
		}
		i++;
	}
	i = 0;
	while (s1[len - i - 1] && i <= len - 1 && (trimend == len - 1 || trimend == len - i))
	{
		if (ft_charcmp(s1[len - i - 1], set, setlen) \
				&& (i == len - 1 || len - i == trimend))
				{
					trimend = len - i - 1;
				}
		i++;
	}
	newstr = ft_calloc0(newstr, trimend - trimstart);
	if (!newstr)
		return (0);
	i = 0;
	while (i < (trimend - trimstart))
	{
		newstr[i] = s1[trimstart + i];
		i++;
	}
	newstr[i] = 0;
	return (newstr);	
}
