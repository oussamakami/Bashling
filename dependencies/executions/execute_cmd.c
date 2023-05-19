/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:47:23 by okamili           #+#    #+#             */
/*   Updated: 2023/05/19 12:59:06 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"

static void	execute_cmd(t_cmd *cmd, int pipefd[2], int red_input, int red_output, int newpipefd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free_cmd_tree(cmd);
		exit(1);
	}
	else if (pid == 0)
	{
		if (pipefd && !cmd->error)
		{
			if (red_input)
				dup2(pipefd[0], STDIN_FILENO);
			if (red_output)
			{
				if (newpipefd)
				{
					dup2(newpipefd[1], STDOUT_FILENO);
					close(newpipefd[1]);
				}else
				
					dup2(pipefd[1], STDOUT_FILENO);
				
			}
			close(pipefd[0]);
			close(pipefd[1]);
		}
		if (!cmd->error)
			execve(cmd->exec, cmd->args, NULL);
		exit(1);
	}
}

void	run_cmd(t_cmd *cmd)
{
	execute_cmd(cmd, NULL, 0, 0, NULL);
	wait(NULL);
}

t_cmd *run_pipe_commands(t_cmd *cmds) {
    int i = 0;
    int pipefd[2], old_pipefd[2] = {-1, -1};

	while (cmds)
	{
		pipe(pipefd);
		if (i == 0)
		{
			execute_cmd(cmds, pipefd, 0 , 1, NULL);
			close (pipefd[1]);
		}
		else if (!cmds->sep || cmds->sep[0] != '|')
		{
			execute_cmd(cmds, old_pipefd, 1 , 0, NULL);
			close(old_pipefd[0]);
			break;
		}
		else
		{
			execute_cmd(cmds, old_pipefd, 1 , 1, pipefd);
			close(old_pipefd[0]);
			close(pipefd[1]);
		}
		old_pipefd[0] = pipefd[0];
		old_pipefd[1] = pipefd[1];
		cmds = get_next_cmd(cmds);
		i++;
	}
	close(pipefd[0]);
	close(pipefd[1]);
	while(wait(NULL) > 0){};
	return cmds;
}
