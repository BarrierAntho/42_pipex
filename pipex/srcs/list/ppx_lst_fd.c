/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_lst_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:22:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/19 19:15:30 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_lst_fd(int argc, char **argv, t_list **list)
{
	t_list	*obj;
	int		npipe;

	obj = *list;
	npipe = argc - NOT_COMMAND;
	if (ppx_lst_fd_in_out(argc, argv, obj) != 0)
		return (1);
	return (0);
}
