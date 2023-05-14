/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mypipex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 04:43:25 by yait-oul          #+#    #+#             */
/*   Updated: 2023/05/14 19:35:10 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mypipex.h"

int pipexx_without_red(int ac, char **argv, char **envp, t_bipex *pipex)
{
    int err = 0;
    int p[2];
    pid_t pid;
    int fd_in = 0;
    int i;

    pipex->envp = envp;
    pipex->paths = envp_path(envp);
    pipex->mypaths = ft_split(pipex->paths, ':');

    i = 0;
   while( ++i < ac ) {
        pipe(p);
        if ((pid = fork()) == -1) {
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            dup2(fd_in, 0);
            if (i != ac-1) {
                dup2(p[1], 1);
            }
            close(p[0]);
            pipex->mycmdargs = ft_split(argv[i], ' ');
            pipex->comd = pathcmmd(pipex->mypaths, pipex->mycmdargs[0], &err);
            execve(pipex->comd, pipex->mycmdargs, envp);
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
            close(p[1]);
            fd_in = p[0];
        }
    }
    if (fd_in > 0) {
        close(fd_in);
    }

    return (0);
}

int pipexx(int ac, char **argv, char **envp, t_bipex *pipex)
{
    int err = 0;
    int p[2];
    pid_t pid;
    int fd_in = 0;
    int i;

    pipex->envp = envp;
    pipex->paths = envp_path(envp);
    pipex->mypaths = ft_split(pipex->paths, ':');

    fd_in = open(argv[1], O_RDONLY);  // open the input file
    if(fd_in < 0) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }
    i = 1;
    while(++i < ac) {  // start from the second command argument
        pipe(p);
        if ((pid = fork()) == -1) {
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            dup2(fd_in, 0);  // replace the standard input with the input file or the previous command's output
            if(fd_in != 0) {
                close(fd_in);
            }
            if (i != ac-2) {
                dup2(p[1], 1);  // replace the standard output with the pipe's write end, unless it's the last command
            }
            else { // if it is the last command
                int fd_out = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
                if(fd_out < 0) {
                    perror("Failed to open file");
                    exit(EXIT_FAILURE);
                }
                dup2(fd_out, 1);
                close(fd_out);
            }
            close(p[0]);
            pipex->mycmdargs = ft_split(argv[i], ' ');
            pipex->comd = pathcmmd(pipex->mypaths, pipex->mycmdargs[0], &err);
            execve(pipex->comd, pipex->mycmdargs, envp);
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
            close(p[1]);
            fd_in = p[0];  // save the pipe's read end to use as the next command's input
        }
    }

    if (fd_in > 0 && fd_in != p[0]) {
        close(fd_in);
    }

    return (0);
}


