/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:07:42 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/30 10:03:15 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*ppx_cmd_init(char *arg, char **envp)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
	{
		ft_error("cmd_init", "cmd", 0, ERR_MALLOC);
		return (NULL);
	}
	cmd->arg = NULL;
	cmd->fullcmd = NULL;
	cmd->fullpath = NULL;
	cmd->fd_r = -1;
	cmd->fd_w = -1;
	cmd->access = -1;
	if (ppx_cmd_init_prop(cmd, arg, envp))
	{
		free(cmd);
		cmd = NULL;
	}
	return (cmd);
}
