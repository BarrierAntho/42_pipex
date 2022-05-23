/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:00:11 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/23 08:41:38 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_pipex_wait(int npipe)
{
	int	res;
	int	status;
	int	i;

	res = 0;
	i = 0;
	while (i < npipe)
	{
		waitpid(-1, &status, 0);
		if (status > 0)
			res++;
		i++;
	}
	return (res);
}
