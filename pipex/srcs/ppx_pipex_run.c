/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:27:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/23 18:18:26 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_pipex_run(int ncmd, t_list **list)
{
	t_list	*obj;
	pid_t	pid;
	int		i;
	int		res;

	obj = *list;
	i = 0;
	res = 0;
	while (obj && i < ncmd)
	{
		pid = fork();
		if (pid < 0)
		{
			res += ft_error("pipex_run", "fork", 0, ERR_PIPE);
			break ;
		}
		if (pid == 0)
			ppx_pipex_cmd(list, obj);
		obj = obj->next;
		i++;
	}
	ft_lst_func_lst(list, &ppx_cmd_close_fd);
	res += ppx_pipex_wait(i, pid);
	return (res);
}
