/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:15:59 by antho             #+#    #+#             */
/*   Updated: 2022/05/14 15:03:31 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ppx_check_path(char *path, char *cmd)
{
	char	*fullpath;

	fullpath = (char *)malloc(sizeof(char * (ft_strlen(path)
					+ ft_strlen(DIR_SEP) + ft_strlen(cmd) + 1)));
	if (!fullpath)
	{
		ft_error("check_path", "fullpath", 0, ERR_MALLOC);
		return (NULL);
	}

	return (fullpath);
}
