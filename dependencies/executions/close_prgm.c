/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_prgm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 00:26:37 by okamili           #+#    #+#             */
/*   Updated: 2023/05/30 01:59:00 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executions.h"

static long long	parse_int(char *str, int *err)
{
	int			sign;
	long long	result;
	long long	prev_result;

	sign = 1;
	result = 0;
	while ((str[0] >= '\t' && str[0] <= '\r') || str[0] == ' ')
		str++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str++;
	}
	while (str && !*err && str[0] >= '0' && str[0] <= '9')
	{
		prev_result = result;
		result = (result * 10) + (str[0] - '0');
		if (prev_result > result)
			*err = 1;
		str++;
	}
	return (result * sign);
}

static int	extract_err_code(char *code)
{
	int			err;
	long long	i;
	size_t		result;

	if (!code)
		return (-1);
	i = -1;
	result = 0;
	if (code[0] == '-' || code[0] == '+')
		i++;
	while (code[++i])
		if (code[i] < '0' || code[i] > '9')
			return (2);
	err = 0;
	i = parse_int(code, &err);
	if (err)
		return (2);
	else
		result = i;
	result %= 256;
	return (result);
}

void	close_prgm(t_cmd *cmd)
{
	int	errnm;

	rl_clear_history();
	destory_all_env(g_env);
	if (!cmd)
		exit(0);
	errnm = extract_err_code(cmd->args[1]);
	if (errnm < 0)
		errnm = cmd->prev_error;
	free_cmd_tree(cmd);
	printf("exit\n");
	exit(errnm);
}
