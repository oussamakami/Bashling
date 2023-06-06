/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:48:10 by okamili           #+#    #+#             */
/*   Updated: 2023/06/06 05:52:01 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTIONS_H
# define EXECUTIONS_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../modules/modules.h"
# include "../parsing/parsing.h"

void	pwd(void);
void	cd(t_cmd *cmd);
void	echo(t_cmd *cmd);
void	close_prgm(t_cmd *cmd);
void	list_env(void);
void	unset_env(t_cmd *cmd);
void	run_export(t_cmd *cmd);
void	run_builtins(t_cmd *cmd);
void	run_commands(t_cmd *cmd);
t_cmd	*run_pipe_commands(t_cmd *cmds, int *err);
void	handle_redir(t_cmd *cmd);
void	handle_fds(int pfd[2], int red[2], int newpfd[2]);

#endif