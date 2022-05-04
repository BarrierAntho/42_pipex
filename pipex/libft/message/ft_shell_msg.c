/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:05:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/04 12:21:34 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"
#include "ft_dprintf.h"

int	ft_shell_msg(char *type, char *data)
{
	int	res;
	char	*message;

	message = strerror(errno);
	res = ft_dprintf(2, "%s%s: %s: %s%s\n", RD, type, message, data, NC);
	if (res <= 0)
		res = 1;
	return (res);
}
