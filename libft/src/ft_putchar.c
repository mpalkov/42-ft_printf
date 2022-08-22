/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:03:15 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/22 16:36:45 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/libft.h"

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, sizeof(char)) != sizeof(char))
		return (-1);
	return (sizeof(char));
}
