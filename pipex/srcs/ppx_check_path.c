/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:15:59 by antho             #+#    #+#             */
/*   Updated: 2022/05/16 14:29:53 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ppx_check_path(char *path, char *cmd)
{
	char	*tmp;
	char	*fullpath;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
	{
		ft_error("check_path", "tmp", 0, ERR_MALLOC);
		return (NULL);
	}
	fullpath = ft_strjoin(tmp, cmd);
	if (!fullpath)
	{
		ft_error("check_path", "fullpath", 0, ERR_MALLOC);
		return (NULL);
	}
	free(tmp);
	tmp = NULL;
	return (fullpath);
}
