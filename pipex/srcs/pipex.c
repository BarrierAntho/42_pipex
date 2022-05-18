/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/18 11:57:54 by abarrier         ###   ########.fr       */
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
int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	t_list	**list;
		(void)envp;

	if (argc != 5)
		return (ft_error("main", "argc", 0, ERR_ARG));
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY | O_RDWR | O_TRUNC
			| O_CREAT, 0644);
	list = ppx_list_init(argc, argv, envp);
	if (!list)
	{
		close(infile);
		close(outfile);
		return (ft_error("main", "list", 0, ERR_MALLOC));
	}
//	t_list *obj = *list;
//	t_cmd *cmd = (t_cmd *)obj->content;
//	ppx_cmd_show(cmd);
//	execve(cmd->fullcmd[0], cmd->fullcmd, NULL);
	close(infile);
	close(outfile);
	ft_lst_show(list, &ppx_cmd_show);
	ft_lst_free(list, &ppx_cmd_free);
	return (0);
}
