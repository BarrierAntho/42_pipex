/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_file_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:17:36 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/19 19:02:34 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_file_access(char *file, int mode)
{
//	if (mode == 16 && access(file, F_OK) != 0)
//		return (16);
	if (access(file, F_OK) != 0)
	{
		ft_shell_msg(ENOENT, file);
		return (8);
	}
	else if (mode == 1 && access(file, X_OK) != 0)
	{
		ft_shell_msg(EACCES, file);
		return (1);
	}
	else if (mode == 2 && access(file, W_OK) != 0)
	{
		ft_shell_msg(EACCES, file);
		return (2);
	}
	else if (mode == 4 && access(file, R_OK) != 0)
	{
		ft_shell_msg(EACCES, file);
		return (4);
	}
	return (0);
}
