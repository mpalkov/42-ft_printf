/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_Pointers_TEST_main.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:37:03 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/30 14:32:23 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	void	*ptr;

//	int		size = sizeof(void *);

	int		i = 42;
	size_t	s_42 = 42;
	size_t	s_maxint = 2147483647;
	size_t	s_maxull = 1844674407370955191;
	ptr = (void *)s_maxull;

	printf("size of void* = %lu\n", sizeof(ptr));
	printf("size of void* = %lu\n", sizeof(void*));

	printf("size int  = %lu\n", sizeof(i));
	printf("size of s_42 = %lu\n", sizeof(s_42));
	printf("size of s_maxint = %lu\n", sizeof(s_maxint));
	printf("size of s_maxull = %zu\n", sizeof(ssize_t));
	
	printf("\n ------sys Printf-----\n\n\n%%p of int 42 = %p\n", &i);
	printf("%%p of void* = %p\n", &ptr);
	printf("%%p of 42 = %p\n"
			"%%p of max_int = %p\n"
			"%%p of max_uns_long_long = %p\n", &s_42, &s_maxint, &s_maxull);
	printf("%%p of NULL = %p\n", NULL);


	printf("\n\n\n------HEX-----\n\n%%x int 42 = %x\n", i);
	printf("%%zx s_42 = %zx\n %%zX s_maxint = %zX\n%%zX s_maxull = %zX\n", s_42, s_maxint, s_maxull);


	return (i);
}
