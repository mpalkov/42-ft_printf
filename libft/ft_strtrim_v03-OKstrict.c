/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:23:12 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/14 11:49:50 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcmp(char a, char const *set, size_t setlen)
{
	size_t	j;

	j = 0;
	while (j < setlen)
	{
		if (a == set[j])
			return (1);
		j++;
	}
	return (0);
}

static char	*ft_calloc0(char *newstr, size_t size)
{
	size_t	i;

	i = 0;
	newstr = malloc(size);
	if (!newstr)
		return (0);
	while (i < size)
		newstr[i++] = 0;
	return (newstr);
}

static char	*ft_fill(char const *s, char *new, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start <= end)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	setlen;
	size_t	len;
	char	*newstr;

	setlen = ft_strlen(set);
	len = ft_strlen(s1);
	start = 0;
	end = len - 1;
	newstr = 0;
	if (!s1 && !set)
		return (0);
	if (s1[0] == 0)
		return (newstr = ft_calloc0(newstr, 1));
	while (s1[start] && start < len - 1 && ft_charcmp(s1[start], set, setlen))
	{
		if (!ft_charcmp(s1[start + 1], set, setlen))
		{
			start++;
			break ;
		}
		start++;
	}
	if (start == len - 1)
		return (newstr = ft_calloc0(newstr, 1));
	while (s1[end] && len > end && ft_charcmp(s1[end], set, setlen))
	{
		if (!ft_charcmp(s1[end - 1], set, setlen))
		{
			end--;
			break ;
		}
		end--;
	}
	newstr = ft_calloc0(newstr, end - start + 2);
	if (!newstr)
		return (0);
	newstr = ft_fill(s1, newstr, start, end);
	return (newstr);
}
