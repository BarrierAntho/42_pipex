/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_lst_fd_in_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:27:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/19 19:23:33 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_lst_fd_in_out(int argc, char **argv, t_list *obj)
{
	t_cmd	*first;
	t_cmd	*last;
	t_list	*test;

	first = (t_cmd *)obj;
	last = (t_cmd *)ft_lst_last(obj);
	ppx_cmd_show(last);
	first->access = ppx_file_access(argv[1], 4);
	first->fd_r = open(argv[1], O_RDONLY);
	if (access(argv[argc - 1], F_OK) != 0)
	{
		last->fd_w = open(argv[argc - 1], O_WRONLY | O_TRUNC
				| O_CREAT, 0644);
		if (last->fd_w < 0)
		{
			ft_shell_msg(errno, argv[argc - 1]);
			return (1);
		}
		last->access = 16;
	}
	else if (ppx_file_access(argv[argc - 1], 2))
		last->access = 2;
	return (0);
}
