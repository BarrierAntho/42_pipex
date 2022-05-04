/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/03 15:52:26 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = 1;
	(void)envp;

	if (argc != 5)
		return (ft_error("main", "argc", 0, ERR_ARG));
	else
	{
		while (i < argc)
		{
			ft_dprintf(1, "argv[] = %s\n", argv[i]);
			i++;
		}
	}
	ppx_parse(argc, argv);
	return (0);
}
