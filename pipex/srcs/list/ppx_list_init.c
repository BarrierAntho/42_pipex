/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_list_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:01:24 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/17 17:36:00 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	**ppx_list_init(int argc, char **argv, char **envp)
{
	t_list	**list;
	t_cmd	*cmd;
	int		i;

	list = (t_list **)malloc(sizeof(t_list *));
	if (!list)
	{
		ft_error("list_init", "list", 0, ERR_MALLOC);
		return (NULL);
	}
	*list = NULL;
	i = 2;
	while (i < (argc - 1))
	{
//							if (i == 3)
//								cmd = NULL;
//							else
		cmd = ppx_cmd_init(argv[i], envp);
		if (!cmd)
		{
//			ft_error("TEST", "TEST", 0, "ERROR");
			ft_lst_clear(list, &ppx_cmd_free);
			free(list);
			return (NULL);
		}
		if (!ft_lst_append(list, (void *)cmd))
		{
			ft_error("list_init", "list_append", 0, "ERROR");
			ppx_cmd_free(cmd);
			ft_lst_clear(list, &ppx_cmd_free);
			free(list);
			return (NULL);
		}
//							ppx_cmd_show(cmd);
		i++;
	}
	return (list);
}
