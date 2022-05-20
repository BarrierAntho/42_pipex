/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_show.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:10:12 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 15:49:37 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ppx_cmd_show(void *content)
{
	t_cmd	*cmd;
	int		i;

	if (!content)
		return ;
	cmd = (t_cmd *)content;
	i = 0;
	if (cmd->arg)
		ft_dprintf(1, "arg: %s\n", cmd->arg);
	if (cmd->fullcmd)
	{
		while (cmd->fullcmd[i])
		{
			ft_dprintf(1, "fullcmd[%d]: %s\n", i, cmd->fullcmd[i]);
			i++;
		}
	}
	else
		ft_dprintf(1, "fullcmd: NULL\n");
	if (cmd->fullpath)
		ft_dprintf(1, "fullpath: %s\n", cmd->fullpath);
	else
		ft_dprintf(1, "fullpath: NULL\n");
	ft_dprintf(1, "pfd[0]: %d\tpfd[1]: %d\n", cmd->fd_r, cmd->fd_w);
	ft_dprintf(1, "%s\n", SEP_P);
}
