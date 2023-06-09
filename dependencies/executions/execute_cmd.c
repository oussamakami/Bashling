/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:47:23 by okamili           #+#    #+#             */
/*   Updated: 2023/06/09 08:48:35 by okamili          ###   ########.fr       */
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
		handle_redir(cmd);
		run_builtins(cmd);
		dup2(hold_std[0], 0);
		dup2(hold_std[1], 1);
	}
	else
		execute_cmd(cmd, NULL, (int [2]){0, 0}, NULL);
	wait(&status);
	if (WTERMSIG(status) == SIGINT)
		cmd->error = 130;
	else if (!cmd->error && !is_builtin(cmd->exec))
		cmd->error = WEXITSTATUS(status);
	signal(SIGINT, sig_handler);
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

static pid_t	*allocate_pids_block(t_cmd *cmds)
{
	int	count;

	count = 0;
	while (cmds && cmds->sep && cmds->sep[0] == '|')
	{
		count++;
		cmds = cmds->next;
	}
	return (ft_calloc(count + 2, sizeof(pid_t)));
}

static	void	extract_err_code(t_cmd *cmds, pid_t *pids)
{
	int	count;
	int	status;

	count = 0;
	while (pids[count])
	{
		waitpid(pids[count++], &status, 0);
		if (WTERMSIG(status) == SIGINT)
			cmds->error = 130;
		else
			cmds->error = WEXITSTATUS(status);
	}
	free(pids);
	signal(SIGINT, sig_handler);
}

t_cmd	*run_pipe_commands(t_cmd *cmds, int *err)
{
	int		count;
	int		pfd[2];
	int		oldpfd[2];
	pid_t	*pids;

	count = 0;
	pids = allocate_pids_block(cmds);
	while (cmds)
	{
		pipe(pfd);
		if (exec_pipes(cmds, pfd, oldpfd, count))
		{
			pids[count] = cmds->process_id;
			break ;
		}
		pids[count++] = cmds->process_id;
		cmds = get_next_cmd(cmds, err);
	}
	close(pfd[0]);
	close(pfd[1]);
	extract_err_code(cmds, pids);
	return (cmds);
}
