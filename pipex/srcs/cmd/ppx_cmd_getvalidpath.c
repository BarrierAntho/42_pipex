/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_getvalidpath.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:01:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/18 11:53:34 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ppx_cmd_getvalidpath(char *cmd, char **envp)
{
	char	*path;

	path = NULL;
	if (access(cmd, F_OK & X_OK) == 0)
		path = ft_strdup(cmd);
	else
	{
		path = ppx_cmd_loop_envp_str(cmd, envp, ENV_PATH_NAME);
		if (path)
			return (path);
		path = ppx_cmd_loop_envp(cmd, envp);
	}
	if (!path)
		path = ft_strdup(cmd);
	return (path);
}
