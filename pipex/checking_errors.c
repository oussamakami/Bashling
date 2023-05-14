/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 05:00:15 by yait-oul          #+#    #+#             */
/*   Updated: 2023/03/17 04:24:52 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mypipex.h"

int	message(char *str)
{
	write(2, str, ft_strlen(str));
	return (127);
}

int	code_exit(t_bipex pipex, char **envp, char **argv)
{
	int	err;

	err = 0;
	pipex.paths = envp_path(envp);
	pipex.mypaths = ft_split(pipex.paths, ':');
	pipex.mycmdargs = ft_split(argv[3], ' ');
	pipex.comd = pathcmmd2(pipex.mypaths, pipex.mycmdargs[0], &err);
	freeing_par(&pipex);
	freeing_childs(&pipex);
	return (err);
}

void	message_erreur(char *msg)
{
	write(1, "bash: ", ft_strlen("bash: "));
	perror(msg);
	exit(1);
}

void	scriptchecking(char *argv)
{
	if (ft_strstr(argv, ".sh") && !(ft_strstr(argv, "./")))
	{
		ft_printf("bash: %s: command not found\n", argv);
		exit(127);
	}
	if ((argv[0] == '.' && argv[1] == '/') || ft_strstr(argv, "bash"))
	{
		if (!(access(argv, X_OK) == 0))
			message_erreur(argv);
	}
}

void	if_empty(char *f1)
{
	if (f1[0] == '\0')
	{
		write(2, "bash: : command not found\n",
			ft_strlen("bash: : command not found\n"));
	}
}
