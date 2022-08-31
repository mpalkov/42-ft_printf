/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:34:53 by mpalkov           #+#    #+#             */
/*   Updated: 2022/06/20 14:27:22 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int main(int argc, char *argv[])
{
    int c = 999;
//    if (argc == 1)
//        return (0);
	c = ft_atoi("    5");
    printf("argc = %d\narg1 = %s\nft_a = %d\n", argc, argv[1], c);
	return (0);
}
