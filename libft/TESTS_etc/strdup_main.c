/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:31:57 by mpalkov           #+#    #+#             */
/*   Updated: 2022/06/28 15:45:21 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main()
{
	char	*ptrnew;
	char	str[] = " \t  jdfnijj";

	ptrnew = ft_strdup(str);
	printf("newstring:%s", str);
	return (0);
}
