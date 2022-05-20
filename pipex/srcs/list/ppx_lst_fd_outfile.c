/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_lst_fd_outfile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:27:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 09:12:10 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_lst_fd_outfile(int argc, char **argv, t_list *obj)
{
	t_cmd	*cmd;

	if (!obj)
		return (ft_error("lst_fd_outfile", "obj", 0, ERR_NOOBJ));
	cmd = (t_cmd *)obj->content;
	cmd->fd_w = open(argv[argc - 1], O_WRONLY | O_TRUNC
			| O_CREAT, 0644);
	if (cmd->fd_w < 0)
	{
		if (access(argv[argc - 1], F_OK) != 0)
		{
			cmd->fd_w = open(argv[argc - 1], O_WRONLY | O_TRUNC
					| O_CREAT, 0644);
			if (cmd->fd_w < 0)
				return (ft_shell_msg(errno, argv[argc - 1]));
		}
		else
			return (ppx_file_access(argv[argc - 1], 2));
	}
	return (0);
}
