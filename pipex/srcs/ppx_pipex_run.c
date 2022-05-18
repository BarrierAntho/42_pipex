/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:27:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/18 22:18:43 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	dup2(infile, STDIN_FILENO);
	pid_t	pid = fork();
	if (pid == 0)
	{
		t_list *obj = *list;
		t_cmd *cmd = (t_cmd *)obj->content;
		//ppx_cmd_show(cmd);
		execve(cmd->fullcmd[0], cmd->fullcmd, NULL);
	}
	else
		waitpid(-1, &resultat, 0);
*/
void	ppx_pipex_run(int argc, char **argv, t_list **list)
{
	int		infile;
	int		outfile;
	int		resultat;
	int		pfd[2];

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY | O_RDWR | O_TRUNC
			| O_CREAT, 0644);

	dup2(infile, STDIN_FILENO);
	if (pipe(pfd) != 0)
	{
		ft_lst_free(list, &ppx_cmd_free);
		exit(EXIT_FAILURE);
	}
	pid_t	pid = fork();
	if (pid == 0)
	{
		ft_dprintf(1, "CHILD\n");
		t_list *obj = *list;
		t_cmd *cmd = (t_cmd *)obj->content;
		//ppx_cmd_show(cmd);
		close(pfd[0]);
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[1]);
		execve(cmd->fullcmd[0], cmd->fullcmd, NULL);
		ft_shell_msg("TEST", cmd->fullcmd[0]);
	}
	else
	{
		ft_dprintf(1, "PARENT\n");
		t_list *obj2 = *list;
		obj2 = obj2->next;
		t_cmd *cmd2 = (t_cmd *)obj2->content;
		//ppx_cmd_show(cmd2);
		close(pfd[1]);
		dup2(pfd[0], STDIN_FILENO);
		close(pfd[0]);
		waitpid(-1, &resultat, 0);
		execve(cmd2->fullcmd[0], cmd2->fullcmd, NULL);
		ft_shell_msg("TEST", cmd2->fullcmd[0]);
	}

	if (infile > 0)
		close(infile);
	if (outfile > 0)
		close(outfile);
	(void)list;
}
