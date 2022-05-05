/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/05 11:53:33 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t pid;
	int	i;

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
	int	pfd[2];
	pipe(pfd);
	ft_dprintf(1, "pfd[0] = %d\npfd[1] = %d\n", pfd[0], pfd[1]);

	pid = fork();
	if (pid == 0)
	{
		wait(NULL);
		ft_dprintf(1, "This is parent\n");
	}
	else
	{
		ft_dprintf(1, "This is child\n");
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
