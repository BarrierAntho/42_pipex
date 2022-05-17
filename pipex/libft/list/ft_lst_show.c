/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:16:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/17 16:35:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lst_show(t_list **list, void (*f)(void *))
{
	t_list	*obj;

	if (!list)
	{
		ft_error("lst_show", "list", 0, ERR_NOOBJ);
		return ;
	}
	obj = *list;
	while (obj)
	{
		if (f)
			(f)(obj->content);
		obj = obj->next;
	}
}
