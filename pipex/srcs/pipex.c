/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/23 18:30:57 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	**list;
	int		npipe;
	int		res;

	if (argc != 5)
		return (ft_error("main", "argc", 0, ERR_ARG));
	list = ft_lst_init();
	res = 0;
	if (!list)
		return (1);
	if (ppx_lst_set(argc, argv, envp, list))
	{
		ft_lst_free(list, &ppx_cmd_free);
		return (2);
	}
	ppx_lst_fd(argc, argv, list);
	npipe = argc - NOT_COMMAND;
	res = ppx_pipex_run(npipe, list);
	ft_lst_func_lst(list, &ppx_cmd_close_fd);
	ft_lst_free(list, &ppx_cmd_free);
	if (res > 0)
		exit(EXIT_FAILURE);
	return (res);
}
