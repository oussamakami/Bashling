/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:42:05 by okamili           #+#    #+#             */
/*   Updated: 2023/05/30 05:12:04 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_redi_arg(t_cmd *cmd, int size)
{
		cmd->redir_files = ft_calloc(size + 1, sizeof(char *));
		cmd->redir_sym = ft_calloc(size + 1, sizeof(char *));
}

void	parse_redir(t_cmd *cmd)
{
	int		index0;
	int		index1;
	int		length;
	char	**redi_extracted;

	if (cmd)
	{
		index0 = 0;
		index1 = 0;
		redi_extracted = extract_redir(cmd->cmd);
		length = ft_atoi(redi_extracted[0]);
		free(redi_extracted[0]);
		init_redi_arg(cmd, length / 2);
		while (++index0 <= length)
		{
			if (index0 % 2)
				cmd->redir_sym[index1] = redi_extracted[index0];
			else
				cmd->redir_files[index1++] = redi_extracted[index0];
		}
		free(redi_extracted);
	}
}
