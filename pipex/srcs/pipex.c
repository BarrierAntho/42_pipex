/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/06 12:21:18 by abarrier         ###   ########.fr       */
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
	dup2(ret, 0);
	execve(argv[2], &argv[2], NULL);

	npipe = argc - NOT_COMMAND - 1;

	if(pipe(pfd) == -1)
		return (ft_error("main", "pipe", 0, ERR_PIPE));
	ft_dprintf(1, "pfd[0] = %d\n", pfd[0]);
	ft_dprintf(1, "pfd[1] = %d\n", pfd[1]);

	char buf;
	while (read(pfd[1], &buf, 1) > 0)
		write(1, &buf, 1);
	ft_dprintf(1, "======================\n");
	pid = fork();
	if (pid == -1)
		return (ft_error("main", "fork", 0, ERR_FORK));
	if (pid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		execve(argv[2], &argv[2], NULL);
		close(pfd[0]);
		ft_dprintf(1, "END CHILD\n");
	}
	else
	{
		close(pfd[0]);
		int ret_dup2 = dup2(ret, pfd[1]);
		if (ret_dup2 == -1)
			return (ft_error("main", "dup2", 0, "ERROR"));
		close(pfd[1]);
		wait(NULL);
		ft_dprintf(1, "END PARENT\n");
	}
/*
	int	ret;
	ret = execve(argv[1], &argv[1], envp);
	ft_dprintf(1, "ret = %d\n", ret);

	if (ret != 0)
	{
		ft_shell_msg("pipex", argv[1]);
		return (1);
	}
*/
	return (0);
}
