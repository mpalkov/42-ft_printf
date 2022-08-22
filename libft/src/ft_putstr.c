/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:33:57 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/22 16:38:09 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		if(write(fd, &str[i++], sizeof(char)) != sizeof(char))
			return (-1);
	return (i);
}
