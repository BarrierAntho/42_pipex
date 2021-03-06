/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:09:43 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/30 10:20:16 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ppx_pipex_cmd(t_list **list, t_list *obj)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)obj->content;
	if (cmd->fd_r >= 0)
		dup2(cmd->fd_r, STDIN_FILENO);
	else
	{
		ft_lst_free(list, &ppx_cmd_free);
		exit(EXIT_FAILURE);
	}
	if (cmd->fd_w < 0)
	{
		ft_lst_free(list, &ppx_cmd_free);
		exit(EXIT_FAILURE);
	}
	dup2(cmd->fd_w, STDOUT_FILENO);
	ft_lst_func_lst(list, &ppx_cmd_close_fd);
	execve(cmd->fullcmd[0], cmd->fullcmd, NULL);
	if (cmd->access == -1)
		ft_dprintf(2, "Error: %s: %s\n", ERR_CMD_FOUND, cmd->fullcmd[0]);
	else
		ft_shell_msg(errno, cmd->fullcmd[0]);
	ft_lst_free(list, &ppx_cmd_free);
	exit(EXIT_FAILURE);
}
