/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 15:57:46 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	**list;

//	if (argc != 5)
//		return (ft_error("main", "argc", 0, ERR_ARG));
	list = ft_lst_init();
	if (!list)
		return (1);
	if (ppx_lst_set(argc, argv, envp, list))
	{
		ft_lst_free(list, &ppx_cmd_free);
		return (2);
	}
	ppx_lst_fd(argc, argv, list);
	ppx_pipex_run(argc, list);
	ft_lst_func_lst(list, &ppx_cmd_close_fd);
	ft_lst_free(list, &ppx_cmd_free);
	return (0);
}
