/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:27:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/23 08:37:12 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_pipex_run(int argc, t_list **list)
{
	t_list	*obj;
	pid_t	pid;
	int		npipe;
	int		i;
	int		res;

	obj = *list;
	npipe = argc - NOT_COMMAND - 1;
	i = 0;
	res = 0;
	while (i < npipe && obj)
	{
		pid = fork();
		if (pid < 0)
		{
			ft_error("pipex_run", "fork", 0, ERR_PIPE);
			break ;
		}
		if (pid == 0)
			ppx_pipex_cmd(list, obj);
		obj = obj->next;
	}
	ft_lst_func_lst(list, &ppx_cmd_close_fd);
	res = ppx_pipex_wait(npipe);
	return (res);
}
