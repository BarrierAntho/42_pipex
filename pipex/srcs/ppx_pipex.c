/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:39:44 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/14 12:11:25 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// INT IN CASE OF EXECVE ERROR
int	ppx_pipex(int argc, char **argv, int pfd[], int *npipe)
{
	pid_t	pid;
	char	**cmd1;
	char	**cmd2;
	(void)argc;
	(void)argv;
	(void)pfd;
	(void)npipe;

	pid = 0;
	cmd1 = NULL;
	cmd2 = NULL;
	ft_dprintf(1, "pfd[0] = %d\n", pfd[0]);
	ft_dprintf(1, "pfd[1] = %d\n", pfd[1]);

	int	i = 0;
	if (argv[2])
	{
			cmd1 = ft_split(argv[2], ' ');
			while (cmd1[i])
			{
				ft_dprintf(1, "cmd1: %s\n", cmd1[i]);
				i++;
			}
	}
	i = 0;
	if (argv[3])
	{
			cmd2 = ft_split(argv[3], ' ');
			while (cmd2[i])
			{
				ft_dprintf(1, "cmd2: %s\n", cmd2[i]);
				i++;
			}
	}
	
	if (execve(*cmd1, cmd1, NULL))
		ft_dprintf(1, "ERROR\n");
	return (errno);
}
