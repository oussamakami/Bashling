#include "executions.h"

static void execute_cmd(t_cmd *cmd, int pipefd[2], int red_input, int red_output)
{
	pid_t pid;
	
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
				dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[0]);
			close(pipefd[1]);
		}
		if (!cmd->error)
		execve(cmd->exec, cmd->args, NULL);
		exit(1);
	}
}

void run_cmd(t_cmd *cmd)
{
	execute_cmd(cmd, NULL, 0, 0);
	wait(NULL);
}


t_cmd *run_pipe_commands(t_cmd *cmds)
{
	int pipefd[2];
    // t_cmd *current = cmds;

    // while (current)
	// {
	// 	pipe(pipefd);
    //     execute_cmd(current, pipefd, current != cmds, current->sep[0] == '|');
    //     close(pipefd[1]);
	// 	if (current != cmds)
	// 		close(pipefd[0]);
	// 	if (current->sep[0] != '|')
	// 		break;
    //     current = current->next;
    // }

	pipe(pipefd);
	execute_cmd(cmds, pipefd, 0, 1);
	execute_cmd(cmds->next, pipefd, 1, 0);
    close(pipefd[0]);
	close(pipefd[1]);
    while(wait(NULL) > 0){};
	return cmds;
}























// t_cmd *run_cmds_pipe(t_cmd *cmd) {
//     int pipefd[2];
//     int input_fd = 0;

//     while (cmd)
// 	{
//         if (cmd->sep && cmd->sep[0] == '|')
// 		{
// 			pipe(pipefd);
//             int saved_stdout = dup(STDOUT_FILENO);
//             dup2(pipefd[1], STDOUT_FILENO);
//             run_cmd(cmd);
//             dup2(saved_stdout, STDOUT_FILENO);
//             close(saved_stdout);
//             int saved_stdin = dup(STDIN_FILENO);
//             close(pipefd[1]);
// 			dup2(pipefd[0], STDIN_FILENO);
//             if (cmd->next != NULL) {
// 				cmd = remove_cmd_from_tree(cmd, cmd);
//                 run_cmd(cmd);
//             }
//             dup2(saved_stdin, STDIN_FILENO);
//             close(saved_stdin);
// 			close(pipefd[0]);
//         } else {
//             run_cmd(cmd);
// 			break;
//         }
//     }
// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	return (remove_cmd_from_tree(cmd, cmd));
// }



















// t_cmd *run_cmds_pipe(t_cmd *cmd)
// {
// 	int	oldpipefd[2];
// 	int	currpipefd[2];
// 	pid_t pid;

// 	oldpipefd[0] = -1;
// 	int i = 5;
// 	while (cmd && --i)
// 	{
// 		pipe(currpipefd);
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			if (oldpipefd[0] != -1)
// 			{
// 				dup2(oldpipefd[0], STDIN_FILENO);
// 				close(oldpipefd[0]);
// 			}
// 			if (cmd->sep[0] == '|')
// 			{
// 				dup2(currpipefd[1], STDOUT_FILENO);
// 				close(currpipefd[1]);
// 			}
// 			close(currpipefd[0]);
// 			execve(cmd->exec, cmd->args, NULL);
// 			exit(1);
// 		}
// 		else
// 		{
// 			close(oldpipefd[0]);
// 			close(oldpipefd[1]);
// 			oldpipefd[0] = currpipefd[0];
// 			oldpipefd[1] = currpipefd[1];
// 		}
// 		wait(NULL);
// 		cmd = remove_cmd_from_tree(cmd, cmd);
// 	}
// 	return (cmd);
// }


// t_cmd *run_cmds_pipe(t_cmd *cmd)
// {
// 	int pipefd[2];
//     pid_t pid1, pid2;

//     // if (pipe(pipefd) == -1) {
//     //     perror("pipe");
//     //     exit(1);
//     // }
//     pid1 = fork();
//     if (pid1 == -1) {
//         perror("fork");
//         exit(1);
//     } else if (pid1 == 0) {
//         close(pipefd[0]);
//         dup2(pipefd[1], STDOUT_FILENO);
// 		run_cmd(cmd);
// 		exit(1);
//     }
// 	cmd = remove_cmd_from_tree(cmd, cmd);
//     pid2 = fork();
//     if (pid2 == -1) {
//         perror("fork");
//         exit(1);
//     } else if (pid2 == 0) {
//         close(pipefd[1]);
//         dup2(pipefd[0], STDIN_FILENO);
// 		run_cmd(cmd);
// 		exit(1);
//     }

//     // Close both ends of the pipe in the parent process
//     close(pipefd[0]);
//     close(pipefd[1]);

//     // Wait for both child processes to finish
//     wait(NULL);
//     wait(NULL);
// 	return (remove_cmd_from_tree(cmd, cmd));
// }