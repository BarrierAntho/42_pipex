/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_close_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:39:37 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 12:40:50 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ppx_cmd_close_fd(void *obj)
{
	t_cmd	*cmd;

	if (!obj)
		return ;
	cmd = (t_cmd *)obj;
	if (!cmd)
		return ;
	if (cmd->fd_r > 2)
		close(cmd->fd_r);
	if (cmd->fd_w > 2)
		close(cmd->fd_w);
}
