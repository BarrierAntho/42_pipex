/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_file_permission.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:17:36 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/19 16:24:39 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_file_permission(char *file, int mode)
{
	if (mode == 16 && access(file, F_OK) != 0)
		return (16);
	else if (access(file, F_OK) != 0)
	{
		errno = ENOENT;
		ft_shell_msg("bash", file);
		return (8);
	}
	else if (mode == 4 && access(file, R_OK) != 0)
	{
		errno = EACCES;
		ft_shell_msg("bash", file);
		return (4);
	}
	else if (mode == 2 && access(file, W_OK) != 0)
	{
		errno = EACCES;
		ft_shell_msg("bash", file);
		return (2);
	}
	else if (mode == 1 && access(file, X_OK) != 0)
	{
		errno = EACCES;
		ft_shell_msg("bash", file);
		return (1);
	}
	return (0);
}
