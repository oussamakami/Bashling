/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:47:23 by okamili           #+#    #+#             */
/*   Updated: 2023/06/16 15:59:57 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"
#include "../../core.h"

static void	execute_process(t_cmd *cmd, int pfd[2], int red[2], int newpfd[2])
{
	char	**env;

	handle_fds(pfd, red, newpfd);
	cmd->error = handle_redir(cmd);
	if (cmd->error)
		exit(cmd->error);
	if (is_builtin(cmd->exec))
		run_builtins(cmd);
	else if (cmd->exec)
	{
		env = export_env();
		execve(cmd->exec, cmd->args, env);
		free2d((void **)env);
	}
}

void	execute_cmd(t_cmd *cmd, int pfd[2], int red[2], int newpfd[2])
{
	pid_t		pid;

	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		perror("fork: ");
	cmd->process_id = pid;
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (!cmd->error)
			execute_process(cmd, pfd, red, newpfd);
		exit(cmd->error);
	}
}

void	run_commands(t_cmd *cmd)
{
	int	status;
	int	hold_std[2];

	if (is_builtin(cmd->exec) && !cmd->error)
	{
		hold_std[0] = dup(0);
		hold_std[1] = dup(1);
		cmd->error = handle_redir(cmd);
		run_builtins(cmd);
		dup2(hold_std[0], 0);
		dup2(hold_std[1], 1);
	}
	else
		execute_cmd(cmd, NULL, (int [2]){0, 0}, NULL);
	wait(&status);
	if (!cmd->error && !is_builtin(cmd->exec))
	{
		cmd->error = WEXITSTATUS(status);
		if (WTERMSIG(status) == SIGINT)
			cmd->error = 130;
	}
	signal(SIGINT, sig_handler);
}
