/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:32:35 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/06 09:52:16 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# include "ft_libft.h"
# include "ppx_message.h"

// CONST USED TO DERTERMINE N PIPE
// nPipe = nCmd - 1
// nPipe = (argc - argv[0] - argv[1] - argv[last]) - 1
// < file1 "cat" | "wc -c" > file2
// ./pipex file1 "cat" "wc -c" file2
# define NOT_COMMAND 3

#endif
