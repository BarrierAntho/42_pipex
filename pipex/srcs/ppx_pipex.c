/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:39:44 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/06 09:46:42 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// INT IN CASE OF EXECVE ERROR
int	ppx_pipex(int argc, char *argv, int *pfd, int *npipe)
{
	pid_t	pid;
	int	pfd2[2];

	if (*npipe > 0)
	{
		*npipe--;
		pipe(pfd2);
		fork();
	}
	if (pid == 0)
	{
		ppx_pipex(argc, argv, pfd2, &npipe);
	}
	else
	{
	}

	return (errno);
}
