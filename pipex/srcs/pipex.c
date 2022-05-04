/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/04 13:07:53 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = 1;
	(void)envp;

	if (argc != 4)
		return (ft_error("main", "argc", 0, ERR_ARG));
	else
	{
		while (i < argc)
		{
			ft_dprintf(1, "argv[] = %s\n", argv[i]);
			i++;
		}
	}
	//ppx_parse(argc, argv);
	int	ret;
	ret = execve(argv[1], &argv[1], envp);
	ft_dprintf(1, "ret = %d\n", ret);

	ft_shell_msg("pipex", argv[1]);
	if (ret != 0)
		return (1);
	return (0);
}
