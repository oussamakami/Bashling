/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:47:23 by okamili           #+#    #+#             */
/*   Updated: 2023/06/06 06:10:47 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"

static void	execute_process(t_cmd *cmd, int pfd[2], int red[2], int newpfd[2])
{
	char	**env;

	handle_fds(pfd, red, newpfd);
	handle_redir(cmd);
	if (is_builtin(cmd->exec))
		run_builtins(cmd);
	else if (cmd->exec)
	{
		env = export_env();
		execve(cmd->exec, cmd->args, env);
		free2d((void **)env);
	}
}

static void	execute_cmd(t_cmd *cmd, int pfd[2], int red[2], int newpfd[2])
{
	pid_t		pid;

	pid = fork();
	if (pid == -1)
		perror("fork: ");
	if (pid == 0)
	{
		if (!cmd->error)
			execute_process(cmd, pfd, red, newpfd);
		exit(cmd->error);
	}
}

void	run_commands(t_cmd *cmd)
{
	int	status;

	// handle_redir(cmd);
	if (is_builtin(cmd->exec) && !cmd->error)
		run_builtins(cmd);
	else
		execute_cmd(cmd, NULL, (int [2]){0, 0}, NULL);
	wait(&status);
	if (!cmd->error && !is_builtin(cmd->exec))
		cmd->error = WEXITSTATUS(status);
}

static int	exec_pipes(t_cmd *cmds, int pfd[2], int oldpfd[2], int count)
{
	if (!count)
	{
		execute_cmd(cmds, pfd, (int [2]){0, 1}, NULL);
		close(pfd[1]);
	}
	else if (!cmds->sep || cmds->sep[0] != '|')
	{
		execute_cmd(cmds, oldpfd, (int [2]){1, 0}, NULL);
		close(oldpfd[0]);
		return (1);
	}
	else
	{
		execute_cmd(cmds, oldpfd, (int [2]){1, 1}, pfd);
		close(oldpfd[0]);
		close(pfd[1]);
	}
	oldpfd[0] = pfd[0];
	oldpfd[1] = pfd[1];
	return (0);
}

t_cmd	*run_pipe_commands(t_cmd *cmds, int *err)
{
	int	count;
	int	pfd[2];
	int	oldpfd[2];
	int	status;

	count = 0;
	while (cmds)
	{
		pipe(pfd);
		if (exec_pipes(cmds, pfd, oldpfd, count++))
			break ;
		cmds = get_next_cmd(cmds, err);
	}
	close(pfd[0]);
	close(pfd[1]);
	while (wait(&status) > 0)
		continue ;
	cmds->error = WEXITSTATUS(status);
	return (cmds);
}
