/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:48:06 by okamili           #+#    #+#             */
/*   Updated: 2023/05/28 01:30:43 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"

void	pwd(void)
{
	char *holder;

	holder = getcwd(NULL, 0);
	if (holder)
        printf("p%s\n", holder);
	else
        perror("Minishell: pwd");
	free(holder);
}

void	cd(t_cmd *cmd)
{
	char *temp;
	char *path;

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
	env_data = add_env(env_data, "OLDPWD", temp);
	free(temp);
}