/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/14 14:19:49 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		i;
	int		k;
	int		npipe;
	int		pfd[2];

	i = 1;
	
	k = 0;
	while (envp[k])
	{
		ft_dprintf(1, "envp[%d] = %s\n", k, envp[k]);
		k++;
	}

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

	//npipe = argc - NOT_COMMAND - 1;
	npipe = 5;
	ft_dprintf(1, "npipe in main: %d\n", npipe);

	if(pipe(pfd) == -1)
		return (ft_error("main", "pipe", 0, ERR_PIPE));
	ft_dprintf(1, "pfd[0] = %d\n", pfd[0]);
	ft_dprintf(1, "pfd[1] = %d\n", pfd[1]);

	dup2(ret, 0);

	pid = fork();
	if (pid == -1)
		return (ft_error("main", "fork", 0, ERR_FORK));
	if (pid == 0)
	{
		ft_dprintf(1, "STARTCHILD\n");
		ppx_pipex(argc, argv, pfd, &npipe);
		ft_dprintf(1, "END CHILD\n");
	}
	else
	{
		wait(NULL);
		ft_dprintf(1, "END PARENT\n");
	}
	return (0);
}
