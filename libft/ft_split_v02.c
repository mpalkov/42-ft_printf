/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:50:46 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/19 19:22:01 by mpalkov          ###   ########.fr       */
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

static void ft_sec_malloc(size_t i, size_t x, size_t y, char **split, char const *s)
{
	// + 2 porque la primera letra sera posicion 0, entonces hay que sumar 1
	// y luego otro 1 para el \0 terminal
	split[x] = (char *)malloc(y + 1);
	if (!split[x])
		ft_splitfree(x, split);
		//splitfree tendra que retornar 0;
	split[x][y] = 0;
	while (y > 0)
	{
		split[x][y - 1] = s[i];
		y--;
		i--;
	}
}

static void	ft_fillsplit(char const *s, char c, char **split)
{
	size_t	i;
	size_t	x;
	size_t	y;
//	size_t	len;

	i = 0;
	x = 0;
	y = 0;
//	len = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] != c && s [i + 1] != 0)
		{
			y++;
		}
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == 0))
		{
			y++;
			ft_sec_malloc(i, x, y, split, s);
			x++;
			y = 0;
		}
		i++;
	}
	split[x] = 0;
}


char	**ft_split(char const *s, char c)
{

	char	**split;
	size_t	i;

	i = 0;
	if (!s || !c)
		return (0);
	split = ft_pri_malloc(s, c);
	if (!split)
		return (0);
	ft_fillsplit(s, c, split);
	return (split);
}
