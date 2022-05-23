/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_init_prop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:08:21 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/23 08:14:08 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_cmd_init_prop(t_cmd *cmd, char *arg, char **envp)
{
	if (!cmd)
		return (ft_error("cmd_init_prop", "cmd", 0, ERR_MALLOC));
	cmd->arg = arg;
	if (*arg == '\0')
	{
		if (ppx_cmd_init_prop_null(cmd))
			return (ft_error("cmd_init_prop", "arg null",
					0, ERR_MALLOC));
		return (0);
	}
	cmd->fullcmd = ft_split(arg, ARG_SEP);
	if (!cmd->fullcmd)
		return (ft_error("cmd_init_prop", "fullcmd", 0, ERR_MALLOC));
	cmd->fullpath = ppx_cmd_getvalidpath(cmd, envp);
	if (cmd->fullcmd[0] != cmd->fullpath)
	{
		free(cmd->fullcmd[0]);
		cmd->fullcmd[0] = NULL;
		cmd->fullcmd[0] = ft_strdup(cmd->fullpath);
		if (!cmd->fullcmd[0])
			return (ft_error("cmd_init_prop", "fullcmd[0]",
					0, ERR_MALLOC));
	}
	return (0);
}
