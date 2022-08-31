/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:46:25 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/20 18:02:12 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "1234567";
	char	d[] = "abc\0\0\0\0\0\0\0\0\0\0\0";
	size_t	srclen;
//	int		dstsize;

	printf("source: %s\n", s);
	printf("destin: %s\n", d);
	srclen = ft_strlcat(d, s, 4);
	printf("-------\nreturn is: %zu\n", srclen);
	printf("source2: %s\n", s);
	printf("destin2: %s\n", d);
	return (0);
}


//strlcpy returns total size of source string
//(size of only content, without the terminating '\0');
