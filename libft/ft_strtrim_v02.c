/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_v02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:17:19 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/12 14:41:39 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static	int	ft_charcmp(char a, char const *set, size_t setlen)
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

static	char *ft_calloc0(char *newstr, size_t size)
{
	size_t	i;
	
	i = 0;
	newstr = malloc(size + 1);
	if (!newstr)
		return (0);
	while (i <= size + 1)
		newstr[i++] = 0;
	return (newstr);
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
	if (!s1)
		return (0);
	while (s1[start] && start < len && ft_charcmp(s1[start], set, setlen))
	{
		if (!ft_charcmp(s1[start + 1], set, setlen))
			break;
		start++;
	}
	while (s1[end] && len > end && ft_charcmp(s1[end], set, setlen))
	{
		if (!ft_charcmp(s1[end - 1], set, setlen))
			break;
		end--;
	}
	newstr = ft_calloc0(newstr, end - start);
	if (!newstr)
		return (0);
	return (newstr);
}
