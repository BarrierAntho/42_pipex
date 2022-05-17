/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_show.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:10:12 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/17 16:39:25 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ppx_cmd_show(void *cmd)
{
	t_cmd	*obj;
	int		i;

	if (!cmd)
		return ;
	obj = (t_cmd *)cmd;
	i = 0;
	if (obj->arg)
		ft_dprintf(1, "arg: %s\n", obj->arg);
	if (obj->fullcmd)
	{
		ft_dprintf(1, "fullcmd:\n");
		while (obj->fullcmd[i])
		{
			ft_dprintf(1, "fullcmd[%d]: %s\n", i, obj->fullcmd[i]);
			i++;
		}
	}
	if (obj->fullpath)
		ft_dprintf(1, "fullpath: %s\n", obj->fullpath);
}
