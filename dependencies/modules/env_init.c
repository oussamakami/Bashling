/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:19:06 by okamili           #+#    #+#             */
/*   Updated: 2023/05/31 00:51:15 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

static char	*env_name(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == '=')
			break ;
	if (str)
		return (ft_substr(str, 0, i));
	return (NULL);
}

static char	*env_val(char *str)
{
	int	i;
	int	start;
	int	len;

	i = -1;
	len = 0;
	while (str && str[++i])
		if (str[i] == '=')
			break ;
	start = i + 1;
	while (str && str[++i])
		len++;
	if (str)
		return (ft_substr(str, start, len));
	return (NULL);
}

void	env_init(int argc, char **argv, char **env)
{
	int			i;
	char		*name;
	char		*val;

	(void)argc;
	(void)argv;
	i = -1;
	while (env && env[++i])
	{
		name = env_name(env[i]);
		val = env_val(env[i]);
		g_env = add_env(g_env, name, val);
		free(name);
		free(val);
	}
}
