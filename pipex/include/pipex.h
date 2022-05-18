/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:32:35 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/18 08:33:53 by abarrier         ###   ########.fr       */
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
# define ENV_SEP '='
# define ENV_FIELD_SEP ':'
# define DIR_SEP "/"
# define ARG_SEP ' '

typedef struct s_cmd
{
	char			*arg;
	char			**fullcmd;
	char			*fullpath;
}			t_cmd;

/***LIST**/
t_list	**ppx_list_init(int argc, char **argv, char **envp);

/***COMMAND***/
void	ppx_cmd_free(void *cmd);
char	*ppx_cmd_getvalidpath(char *cmd, char **envp);
t_cmd	*ppx_cmd_init(char *arg, char **envp);
int		ppx_cmd_init_prop(t_cmd *cmd, char *arg, char **envp);
char	*ppx_cmd_loop_envp(char *cmd, char **envp);
char	*ppx_cmd_loop_envline(char *cmd, char **envline);
char	*ppx_cmd_setpath(char *cmd, char *env);
void	ppx_cmd_show(void *cmd);

#endif
