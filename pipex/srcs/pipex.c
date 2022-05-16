/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:31:40 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/16 18:57:08 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd;
	int		npipe;
	char	**cmd1;
	char	**cmd2;

	if (argc != 5)
		return (ft_error("main", "argc", 0, ERR_ARG));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("main", "open", 0, "ERROR"));
	npipe = argc - NOT_COMMAND - 1;
	dup2(fd, 0);
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	if (!cmd1 || !cmd2)
		return (ft_error("main", "cmd1/cmd2", 0, "ERROR"));
	ppx_pipex(envp, &npipe);
	ft_free_ptrptr_str(cmd1);
	ft_free_ptrptr_str(cmd2);
	return (0);
}
