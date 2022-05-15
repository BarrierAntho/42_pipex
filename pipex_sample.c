/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/08 12:37:26 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		i;
	int		npipe;
	int		pfd[2];

	i = 1;
	(void)envp;

	if (argc == 1)
		return (ft_error("main", "argc", 0, ERR_ARG));
	else
	{
		while (i < argc)
		{
			ft_dprintf(1, "argv[] = %s\n", argv[i]);
			i++;
		}
	}

	int ret = open(argv[1], O_RDONLY);
	if (ret == -1)
		return (ft_error("main", "open", 0, "ERROR"));
	else
		ft_dprintf(1, "ret = %d\n", ret);
	//dup2(ret, 0);
	//execve(argv[2], &argv[2], NULL);

	npipe = argc - NOT_COMMAND - 1;

	if(pipe(pfd) == -1)
		return (ft_error("main", "pipe", 0, ERR_PIPE));
	ft_dprintf(1, "pfd[0] = %d\n", pfd[0]);
	ft_dprintf(1, "pfd[1] = %d\n", pfd[1]);

	dup2(ret, pfd[1]);
	close(ret);
	
	pid = fork();
	if (pid == -1)
		return (ft_error("main", "fork", 0, ERR_FORK));
	if (pid != 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 0);
		close(pfd[1]);
		execve(argv[2], &argv[2], NULL);
		wait(NULL);
		ft_dprintf(1, "END PARENT\n");
	}
	else
	{
		close(pfd[1]);
		close(pfd[0]);
		ft_dprintf(1, "END CHILD\n");
	}
	return (0);
}
