/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_lst_fd_pfd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:26:59 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/23 17:35:27 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ppx_lst_fd_pfd(t_list *obj, t_cmd *cmd1, t_cmd *cmd2, int npipe)
{
	int		pfd[2];
	int		i;

	i = 0;
	while (obj && i < npipe)
	{
		cmd1 = (t_cmd *)obj->content;
		cmd2 = (t_cmd *)obj->next->content;
		if (pipe(pfd) < 0)
		{
			ft_shell_msg(errno, "pipe");
			cmd1->fd_w = -1;
			cmd2->fd_r = -1;
		}
		else
		{
			cmd1->fd_w = pfd[1];
			cmd2->fd_r = pfd[0];
		}
		obj = obj->next;
		i++;
	}
}
