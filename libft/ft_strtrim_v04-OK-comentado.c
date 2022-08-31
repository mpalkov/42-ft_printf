/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:23:12 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/14 13:59:15 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcmp(char a, char const *set )
{
	size_t	j;
	size_t	setlen;

	j = 0;
	setlen = ft_strlen(set);
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


char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*newstr;

	start = 0;
	end = ft_strlen(s1) - 1;
	newstr = 0;
	if (!s1 && !set)
		return (0);

	//estas 2 lineas se pueden evitar si se configura bien la busqueda de inicio y final
	//y el resultado sera que el Ft_substr empieza crear desde la posicion del \0
	//y de longitud 1, asi que retorna una string vacia.
	
	/* if (s1[0] == 0)
		return (newstr = ft_calloc0(newstr, 1)); */
	while (s1[start] && ft_charcmp(s1[start], set))
			start++;
	//if (start == ft_strlen(s1) - 1)
	//	return (newstr = ft_calloc0(newstr, 1));
	while (s1[0] && ft_charcmp(s1[end], set))
		end--;
	//estas 3 lineas se pueden ahorrar tambien configurando bien start y end que nos crea un
	
	/* newstr = ft_calloc0(newstr, end - start + 2);
		if (!newstr)
			return (0); */
	newstr = ft_substr(s1, start, end-start + 1);
	return (newstr);
}
// FT_STRTRIM
// Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
// specified in ’set’ removed from the beginning and the end of the string.
//
// The function first searches the s1 string, char by char,
// for coincidence with a char  included in set. If no more coincidence ocurrs,
// search for start ends. Like this, there is  no problem if a char from set
// is in a middle of the string.  Only consecutive  matches from start count.
//
// If all chars are included in the set, the first loop reaches end
// of the s1 string. Then the second loop searches matches starting at the end
// and reaches start of s1.  Subsequently the ft_substr creates only empty new
// string (end - start - 1) containinng only terminating \0 char.
