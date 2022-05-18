/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_pipex_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:27:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/18 13:17:55 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ppx_pipex_run(int argc, char **argv, t_list **list)
{
	int		infile;
	int		outfile;

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY | O_RDWR | O_TRUNC
			| O_CREAT, 0644);
	if (infile > 0)
		close(infile);
	if (outfile > 0)
		close(outfile);
	(void)list;
}
