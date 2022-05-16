/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:39:44 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/16 18:56:05 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// INT IN CASE OF EXECVE ERROR
int	ppx_pipex(char **envp, int *npipe)
{
	int	pfd[2];
	(void)npipe;

	pipe(pfd);

	int k = 0;
	char *test;
	while (envp[k])
	{
		if (k == 28)
		{
			ft_dprintf(1, "envp[%d] = %s\n", k, envp[k]);
			test = ppx_check_path(envp[k], "TEST");
			ft_dprintf(1, "test: %s\n", test);
			free(test);
		}
		k++;
	}
	return (errno);
}
