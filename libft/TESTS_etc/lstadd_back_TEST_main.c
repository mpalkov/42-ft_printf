/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back_TEST_main.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:30:25 by mpalkov           #+#    #+#             */
/*   Updated: 2022/07/26 18:08:13 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    struct s_list   *mylist;

    mylist = (t_list *)malloc(sizeof(*mylist));
    if (!mylist)
        return (0);
    mylist->content = content;
    mylist->next = NULL;
    return (mylist);
}

int main(void)
{
    t_list  *a = ft_lstnew(strdup("AAAAA"));
    t_list  *b = ft_lstnew(strdup("BBBBB"));
    t_list  *c = ft_lstnew(strdup("OK"));

    a->next = b;
    b->next = 0;
    ft_lstadd_back(&a, c);
    if (b->next == c && !strcmp(b->next->content, "OK"))
      printf("OK ");
    else
       printf("2item list FAILED ");
    free(b);
    b = 0;
    a->next = 0;
    ft_lstadd_back(&a, c);
    if (a->next == c && !strcmp(a->next->content, "OK"))
      printf("OK ");
    else
       printf("1 item list FAILED ");
    free(a);
    a = 0;
    ft_lstadd_back(&a, c);
    if (a->next == 0 && !strcmp(a->content, "OK"))
      printf("OK ");
    else
       printf("NULL item list FAILED ");
    return (0);
}
