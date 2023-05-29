/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:48:06 by okamili           #+#    #+#             */
/*   Updated: 2023/05/29 03:05:11 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"

void	pwd(void)
{
	char	*holder;

	holder = getcwd(NULL, 0);
	if (holder)
		printf("%s\n", holder);
	else
		perror("Minishell: pwd");
	free(holder);
}

void	cd(t_cmd *cmd)
{
	char	*temp;
	char	*path;

	path = cmd->args[1];
	if (path && cmd->args[2])
	{
		ft_putstr_fd("Minishell: cd: too many arguments\n", 2);
		cmd->error = 1;
		return ;
	}
	if (!path)
		path = get_relative_path("~");
	if (ft_strlen(path) == 1 && path[0] == '-')
		path = fetch("OLDPWD");
	temp = getcwd(NULL, 0);
	if (chdir(path))
	{
		perror("Minishell: cd");
		cmd->error = 1;
	}
	g_env = add_env(g_env, "OLDPWD", temp);
	free(temp);
}

void	echo(t_cmd *cmd)
{
	int		i;
	int		new_line;
	char	*tmp;

	i = 1;
	while (cmd->args[i] && !ft_strncmp("-n", cmd->args[i], 2))
		i++;
	new_line = (i == 1);
	while (cmd->args[i])
	{
		tmp = clean_quotes(cmd->args[i++]);
		printf("%s", tmp);
		free(tmp);
		if (cmd->args[i])
			printf(" ");
	}
	if (new_line)
		printf("\n");
}

void	close_prgm(t_cmd *cmd)
{
	int	temp;

	temp = -1;
	destory_all_env(g_env);
	if (!cmd)
		exit(0);
	while (cmd->args[1] && cmd->args[1][++temp])
	{
		if (cmd->args[1][temp] < '0' || cmd->args[1][temp] > '9')
		{
			temp = 0;
			break ;
		}
	}
	if (cmd->args[1] && temp)
		temp = ft_atoi(cmd->args[1]);
	free_cmd_tree(cmd);
	if (temp > 255)
		temp = 255;
	else if (temp < 0)
		temp = 0;
	printf("exit\n");
	exit(temp);
}

void	run_builtins(t_cmd *cmd)
{
	int	len;

	len = ft_strlen(cmd->exec);
	if (len == 2 && !ft_strncmp("cd", cmd->exec, 2))
		cd(cmd);
	if (len == 3 && !ft_strncmp("pwd", cmd->exec, 3))
		pwd();
	if (len == 4 && !ft_strncmp("echo", cmd->exec, 4))
		echo(cmd);
	if (len == 4 && !ft_strncmp("exit", cmd->exec, 4))
		close_prgm(cmd);
}
