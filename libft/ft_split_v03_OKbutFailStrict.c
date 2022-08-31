/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:50:46 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/28 16:03:43 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_pri_malloc(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**split;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == 0))
			count++;
		i++;
	}
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	return (split);
}

static int	ft_splitfree(size_t x, char **split)
{
	while (x >= 0)
	{
		free((void *)(split[x]));
		x--;
	}
	free((void **)split);
	return (0);
}

static char	*ft_sec_malloc(size_t i, size_t y, char const *s)
{
	char	*xptr;

	xptr = (char *)malloc(sizeof(char) * (y + 1));
	if (!xptr)
		return (NULL);
	xptr[y] = 0;
	while (y > 0)
	{
		xptr[y - 1] = s[i];
		y--;
		i--;
	}
	return (xptr);
}

static int	ft_fillsplit(char const *s, char c, char **split)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	x = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] != c && s [i + 1] != 0)
		{
			y++;
		}
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == 0))
		{
			y++;
			split[x] = ft_sec_malloc(i, y, s);
			if (split[x] == 0)
			{
				ft_splitfree(x, split);
				return (0);
			}
			x++;
			y = 0;
		}
		i++;
	}
	split[x] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	i = 0;
	split = ft_pri_malloc(s, c);
	if (!split || !s)
		return (0);
	if (!ft_fillsplit(s, c, split))
		return (0);
	return (split);
}
