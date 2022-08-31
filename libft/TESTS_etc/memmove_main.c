/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:07:01 by mpalkov           #+#    #+#             */
/*   Updated: 2022/05/19 12:14:46 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	source[] = "0123456789";
	char	destin[] = "----------";
	char	source2[] = "0123456789";
	char	destin2[] = "----------";
//	char	*ptr;	

//	ptr = &source;
	printf("src: %s\n", source);
	printf("dst: %s\n", destin);
	printf("(void *)destin = %p\n", (void *)destin);
	printf("&source = %p\n", &source);
	printf("source = %p\n", source);
	printf("&destin > &source: %d\n", (&destin > &source));
	printf("*destin > *source: %d\n", (*destin > *source));
//	printf("source > destin: %d\n", (source > destin));
//	printf("ptr *source = %p\n", ptr);
	memmove(destin, source, 3);
	printf("memmove: %s\n", destin);
	ft_memmove(destin2, source2, 3);
	printf("ft_memmove: %s\n", destin2); 
	return (0);
}
