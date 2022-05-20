/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:27:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 09:07:42 by abarrier         ###   ########.fr       */
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
	int		pfd[2];

	int	myerr = 0;
	myerr = ppx_file_access(argv[1], 4);

	if (pipe(pfd) != 0)
	{
		ft_lst_free(list, &ppx_cmd_free);
		exit(EXIT_FAILURE);
	}
	pid_t	pid = fork();
	if (pid == 0)
	{
		t_list *obj = *list;
		t_cmd *cmd = (t_cmd *)obj->content;
		//ppx_cmd_show(cmd);
		if (cmd->fd_r > 0)
		{
			close(pfd[0]);
			close(pfd[1]);
			return ;
		}
		infile = open(argv[1], O_RDONLY);
		dup2(infile, STDIN_FILENO);
		close(pfd[0]);
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[1]);
		close(infile);
		execve(cmd->fullcmd[0], cmd->fullcmd, NULL);
		ft_shell_msg(errno, cmd->fullcmd[0]);
	}
	else
	{
		t_list *obj2 = *list;
		obj2 = obj2->next;
		t_cmd *cmd2 = (t_cmd *)obj2->content;
		if (cmd2->fd_r > 0)
		{
			close(pfd[0]);
			close(pfd[1]);
			return ;
		}
		outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC
			| O_CREAT, 0644);
		//ppx_cmd_show(cmd2);
		//waitpid(-1, NULL, 0);
		dup2(pfd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(pfd[1]);
		close(pfd[0]);
		close(outfile);
		execve(cmd2->fullcmd[0], cmd2->fullcmd, NULL);
		ft_shell_msg(errno, cmd2->fullcmd[0]);
	}
/*
	if (infile > 0)
		close(infile);
	if (outfile > 0)
		close(outfile);
*/
}
