/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_TEST_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:45:54 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/22 16:41:01 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/libft.h"
#include <stdio.h>

int	main(void)
{
	int	ret;

	ret = ft_putstr_fd("2", STDOUT_FILENO);
	printf("\n%i\n", ret);
	return (0);
}
