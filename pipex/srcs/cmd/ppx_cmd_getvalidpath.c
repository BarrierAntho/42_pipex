/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_getvalidpath.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:01:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/17 19:08:08 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ppx_cmd_getvalidpath(char *cmd, char **envp)
{
	char	*path;
	char	**tmp;
	int		i;
	int		j;

	path = NULL;
	tmp = NULL;
	i = 0;
	j = 0;
	while (envp[i])
	{
		tmp = ft_split(ft_strchr(envp[i], ENV_SEP) + 1, ENV_FIELD_SEP);
		if (!tmp)
		{
			ft_error("cdm_getvalidpath", "tmp", 0, ERR_NOOBJ);
			break ;
		}
		j = 0;
		while (tmp[j])
		{
			path = ppx_cmd_setpath(cmd, tmp[j]);
			free(path);
			path = NULL;
			j++;
		}
		ft_free_ptrptr_str(tmp);
		tmp = NULL;
		i++;
	}
	return (path);
}
