/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/18 13:07:30 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//dup2(infile, STDIN_FILENO);
//char	*test[] = {"/usr/bin/cat", NULL};
//pid_t	pid = fork();
//if (pid == 0)
//{
//	execve(*test, test, NULL);
//}
//	t_list *obj = *list;
//	t_cmd *cmd = (t_cmd *)obj->content;
//	ppx_cmd_show(cmd);
//	execve(cmd->fullcmd[0], cmd->fullcmd, NULL);
int	main(int argc, char **argv, char **envp)
{
	t_list	**list;

	if (argc != 5)
		return (ft_error("main", "argc", 0, ERR_ARG));
	list = ft_lst_init();
	if (!list)
		return (1);
	if (ppx_lst_set(argc, argv, envp, list))
	{
		ft_lst_free(list, &ppx_cmd_free);
		return (2);
	}
	ppx_pipex_run(argc, argv, list);
	ft_lst_show(list, &ppx_cmd_show);
	ft_lst_free(list, &ppx_cmd_free);
	return (0);
}
