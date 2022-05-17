/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:35:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/17 16:17:40 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ppx_cmd_free(void *cmd)
{
	t_cmd	*obj;

	if (!cmd)
		return ;
	obj = (t_cmd *)cmd;
	if (obj->fullcmd)
	{
		ft_free_ptrptr_str(obj->fullcmd);
		obj->fullcmd = NULL;
	}
	if (obj->fullpath)
	{
		free(obj->fullpath);
		obj->fullpath = NULL;
	}
	free(obj);
	obj = NULL;
}
