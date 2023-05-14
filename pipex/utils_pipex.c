/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:22:47 by yait-oul          #+#    #+#             */
/*   Updated: 2023/03/17 04:18:33 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mypipex.h"

char	*envp_path(char **envp)
{
	char	*path_from_envp;
	int		i;

	i = 0;
	path_from_envp = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_from_envp = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (path_from_envp == NULL)
	{
		ft_printf("Error: PATH variable not found in environment\n");
		exit(1);
	}
	return (path_from_envp);
}

char	*pathcmmd(char **paths, char *cmd, int *err)
{
	char	*momentane;
	char	*commmand;
	int		i;

	i = 0;
	if (access(cmd, 0) == 0)
		return (cmd);
	while (paths[i] != NULL)
	{
		momentane = ft_strjoin(paths[i], "/");
		commmand = ft_strjoin(momentane, cmd);
		free(momentane);
		if (access(commmand, 0) == 0)
			return (commmand);
		free(commmand);
		i++;
	}
	*err = 127;
	if (cmd == NULL)
	{
		ft_printf("bash: : command not found\n");
		return (NULL);
	}
	ft_printf("bash: %s: command not found\n", cmd);
	return (NULL);
}

char	*pathcmmd2(char **paths, char *cmd, int *err)
{
	char	*momentane;
	char	*commmand;
	int		i;

	i = 0;
	while (paths[i] != NULL)
	{
		momentane = ft_strjoin(paths[i], "/");
		commmand = ft_strjoin(momentane, cmd);
		free(momentane);
		if ((access(commmand, F_OK) == 0) && (access(commmand, X_OK) == 0))
			return (commmand);
		free(commmand);
		i++;
	}
	*err = 127;
	return (NULL);
}

char	**create_2d_array(int rows, int cols)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc(rows * sizeof(char *));
	while (i < rows)
	{
		arr[i] = (char *)malloc(cols * sizeof(char));
		i++;
	}
	return (arr);
}

void	is_script(char *str)
{
	char	*script_path;
	char	*args[3];

	script_path = str;
	args[0] = "sh";
	args[1] = script_path;
	args[2] = NULL;
	if (execve("/bin/sh", args, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
