/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:42:09 by okamili           #+#    #+#             */
/*   Updated: 2023/05/19 19:15:23 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parsing(t_cmd *cmd)
{
	char	*temp;

	if (!cmd)
		return ;
	temp = replace_variables(cmd->cmd, cmd->prev_error);
	cmd->args = parse_args(temp);
	free(temp);
	cmd->exec = parse_exec(cmd->args[0], &cmd->error);
	if (ft_strchr(";|", cmd->cmd[ft_strlen(cmd->cmd) - 1]))
		cmd->sep = cmd->cmd + (ft_strlen(cmd->cmd) - 1);
	parse_redir(cmd);
}
