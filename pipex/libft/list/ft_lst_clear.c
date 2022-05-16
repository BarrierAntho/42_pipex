/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:19:56 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/16 09:38:21 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lst_clear(t_list **lst)
{
	t_list	*obj;
	t_list	*del;

	if (!lst)
		return ;
	obj = *lst;
	del = NULL;
	while (obj)
	{
		del = obj;
		obj = obj->next;
		free(del);
		del = NULL;
	}
}
