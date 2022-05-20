/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:32:35 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 16:01:48 by abarrier         ###   ########.fr       */
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
# define ENV_PATH_NAME "PATH="
# define DIR_SEP "/"
# define ARG_SEP ' '

typedef struct s_cmd
{
	char	*arg;
	char	**fullcmd;
	char	*fullpath;
	int		fd_r;
	int		fd_w;
}		t_cmd;

/***LIST**/
int		ppx_lst_fd(int argc, char **argv, t_list **list);
int		ppx_lst_fd_infile(char **argv, t_list *obj);
int		ppx_lst_fd_outfile(int argc, char **argv, t_list *obj);
void	ppx_lst_fd_pfd(t_list *obj, t_cmd *cmd1, t_cmd *cmd2, int npipe);
int		ppx_lst_set(int argc, char **argv, char **envp, t_list **list);

/***COMMAND***/
void	ppx_cmd_close_fd(void *content);
void	ppx_cmd_free(void *content);
char	*ppx_cmd_getvalidpath(char *cmd, char **envp);
t_cmd	*ppx_cmd_init(char *arg, char **envp);
int		ppx_cmd_init_prop(t_cmd *cmd, char *arg, char **envp);
int		ppx_cmd_init_prop_null(t_cmd *cmd);
char	*ppx_cmd_loop_envline(char *cmd, char **envline);
char	*ppx_cmd_loop_envp(char *cmd, char **envp);
char	*ppx_cmd_loop_envp_str(char *cmd, char **envp, char *s);
char	*ppx_cmd_setpath(char *cmd, char *env);
void	ppx_cmd_show(void *content);

/***PIPEX***/
int		ppx_file_access(char *file, int mode);
void	ppx_pipex_cmd(t_list **list, t_list *obj);
void	ppx_pipex_run(int argc, t_list **list);
void	ppx_pipex_wait(int npipe);

#endif
