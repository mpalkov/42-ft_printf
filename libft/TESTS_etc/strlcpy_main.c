/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:46:25 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/20 11:51:24 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "123457890";
	char	d[] = "abdefghijklmnop";
	int		srclen;
//	int		dstsize;

	printf("source: %s\n", s);
	printf("destin: %s\n", d);
	srclen = ft_strlcpy(d, s, 5);
	printf("-------\nsrclen is: %i\n", srclen);
	printf("source2: %s\n", s);
	printf("destin2: %s\n", d);
	return (0);
}


//strlcpy returns total size of source string
//(size of only content, without the terminating '\0');
