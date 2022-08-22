/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_TEST_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:27:52 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/22 16:29:59 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/libft.h"
#include <stdio.h>

int main(void)
{
    int ret;

    ret = ft_putchar_fd('X', STDOUT_FILENO);
    printf("\n%i\n", ret);
    return (0);
}
