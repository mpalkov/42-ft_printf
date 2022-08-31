/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:05:33 by mpalkov           #+#    #+#             */
/*   Updated: 2022/06/15 16:36:45 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char	s1[] = "saad0snn";
	const char	s2[] = "saaazx";
	const char *ptr_s1;
	const char *ptr_s2;
	ptr_s1 = &s1[0];
	ptr_s2 = &s2[0];

	printf("s1: %s\ns2: %s\nstrncmp: %d\n", s1, s2, strncmp(ptr_s1, ptr_s2, 8));
	printf("ft_st...: %d\n", ft_strncmp(ptr_s1, ptr_s2, 8));
	return (0);
}
