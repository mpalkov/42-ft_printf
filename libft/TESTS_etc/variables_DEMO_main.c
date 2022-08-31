/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_DEMO_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:48:20 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/29 17:00:08 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
int	i = 0;

while (i <= 9)
{
	int (new(char)i) = i;
	printf("(char)i = %c\nint i = %d\n\n", (new(char)i), i);
	i++;
}
}
