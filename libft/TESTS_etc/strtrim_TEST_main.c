/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim_TEST_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:56:53 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/14 15:48:15 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	main()
{
	char	*newstr = 0;
	char	*newstr2 = 0;
	char	*newstr3 = 0;

	/* TEST 1 */
	newstr = ft_strtrim( "lorem \t  ipsum \n dolor sit amet", "et");
	if (!strcmp(newstr, "lorem \t  ipsum \n dolor sit am"))
		printf("lorem \t  ipsum \n dolor sit amet\nOK\n\n");
	else
		printf("KO\ns1: lorem \t  ipsum \n dolor sit amet\nexpected: lorem \t  ipsum \n dolor sit am\nResult: %s\n\n", newstr);

	/* TEST 2 */
	newstr2 = ft_strtrim("", "");
	if (!strcmp(newstr2, ""))
		printf("empty str\nOK\n\n");
	else
		printf("KO\ns1:\"\"\nexpected:\"\"\nResult: %s\n\n", newstr2);

	/* TEST 3 */
    newstr3 = ft_strtrim("Hola 42", "xde");
    if (!strcmp(newstr3, "Hola 42"))
        printf("Hola 42\nOK\n\n");
    else
        printf("KO\ns1:Hola 42\nexpected:Hola 42\nResult: %s\n", newstr3);

	/* TEST 4 */
	newstr2 = ft_strtrim("\t\t\t", "\t");
	if (!strcmp(newstr2, ""))
		printf("\"			\"\nOK\n\n");
	else
		printf("KO\ns1:\"\t\t\t\"\nexpected:\"\"\nResult: %s\n\n", newstr2);


	return (0);
}
