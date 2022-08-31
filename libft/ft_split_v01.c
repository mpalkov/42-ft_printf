/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:50:46 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/19 15:45:19 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static char	**ft_malloc1(char const *s, char c)
{
	size_t	i;
	size_t	nbytes;
	size_t	count;
	char	**split;

	i = 0;
	count = 0;
	nbytes = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			count++;
		if (s[i] != c)
			nbytes++;
		i++;
	}
	split = (char **)malloc(nbytes + count + 1);
	if (!split)
		return (0);
	return (split);
}

static void	ft_fillsplit(char const *s, char c, char **split)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	x = 0;
	y = 0;
	while (s[i])
	{
//		ir rellenando cada palabra del 2D array, terminar cada string con su \0
//			y terminar el 2D array con 0 byte.
		if (s[i] != c && s[i + 1] != c)
		{
			split[x][y] = s[i];
			y++;
		}
		if (s[i] != c && s[i + 1] == c)
		{
			split[x][y] = s[i];
			split[x][y + 1] = 0;
			x++;
			y = 0;
		}
		if (s[i] == c && s[i + 1] == c)
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
	split = ft_malloc1(s, c);
	if (!split)
		return (0);
	ft_fillsplit(s, c, split);
	return (split);
}
