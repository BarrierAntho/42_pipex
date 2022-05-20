/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_lst_fd_infile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:27:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 09:10:17 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_lst_fd_infile(char **argv, t_list *obj)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)obj->content;
	cmd->fd_r = open(argv[1], O_RDONLY);
	if (cmd->fd_r < 0)
		return (ppx_file_access(argv[1], 4));
	else
		return (0);
}
