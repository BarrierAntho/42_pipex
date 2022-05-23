/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:00:11 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/23 18:18:40 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_pipex_wait(int ncmd, int pid)
{
	int	status;
	int	i;

	status = 1;
	i = 0;
	waitpid(pid, &status, 0);
	while (i < ncmd)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
	return (status);
}
