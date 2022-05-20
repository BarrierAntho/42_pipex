/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_lst_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:44:11 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 16:04:10 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_lst_set(int argc, char **argv, char **envp, t_list **list)
{
	t_cmd	*cmd;
	int		i;

	i = 2;
	while (i < (argc - 1))
	{
		cmd = ppx_cmd_init(argv[i], envp);
		if (!cmd)
			return (ft_error("lst_set", "cmd", 0, ERR_NOOBJ));
		if (!ft_lst_append(list, (void *)cmd))
		{
			ppx_cmd_free(cmd);
			return (ft_error("lst_set", "list/cmd",
					0, ERR_LST_APPEND));
		}
		i++;
	}
	return (0);
}
