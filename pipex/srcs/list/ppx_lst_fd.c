/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_lst_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:22:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 12:08:51 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_lst_fd(int argc, char **argv, t_list **list)
{
	t_list	*obj;
	int		npipe;

	obj = *list;
	if (!obj)
		return (ft_error("lst_fd", "obj", 0, ERR_NOOBJ));
	npipe = argc - NOT_COMMAND - 1;
	ppx_lst_fd_infile(argv, obj);
	ppx_lst_fd_outfile(argc, argv, ft_lst_last(obj));
	ppx_lst_fd_pfd(obj, NULL, NULL, npipe);
	return (0);
}
