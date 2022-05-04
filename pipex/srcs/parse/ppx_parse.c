/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:47:35 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/03 16:08:02 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ppx_parse(int argc, char **argv)
{
	int	err;

	(void)argc;
	(void)argv;

	// TODO:
	// for 2nd and last arguments (files)
	// 	check access
	// for 3rd to last last argument (commands)
	// 	split char
	// 	check access
	
	int ret = access("/../", F_OK);
	ft_dprintf(1, "ret = %d\n", ret);
	
	err = 0;
	return (err);
}
