/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:42:05 by okamili           #+#    #+#             */
/*   Updated: 2023/06/06 06:36:04 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_redi_arg(t_cmd *cmd, int size)
{
		cmd->redir_files = ft_calloc(size + 1, sizeof(char *));
		cmd->redir_sym = ft_calloc(size + 1, sizeof(char *));
}

static char	*extract_err_sym(char *sym)
{
	int	skip;

	if (!sym)
		return (NULL);
	skip = 1;
	if (sym[0] && sym[1] && sym[0] == sym[1])
		skip++;
	sym += skip;
	return (sym);
}

static int	check_redir(t_cmd *cmd)
{
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (cmd->redir_sym[++i] && !tmp)
	{
		len = ft_strlen(cmd->redir_sym[i]);
		if (len <= 2 && (!ft_strncmp("<<", cmd->redir_sym[i], len)
				|| !ft_strncmp(">>", cmd->redir_sym[i], len)))
		{
			if (!ft_strlen(cmd->redir_files[i]))
				tmp = "newline";
		}
		else
			tmp = extract_err_sym(cmd->redir_sym[i]);
	}
	if (!tmp)
		return (0);
	tmp = replace_word("Minishell: syntax error near "
			"unexpected token `X'\n", "X", tmp, 0);
	ft_putstr_fd(tmp, 2);
	free(tmp);
	return (1);
}

int	parse_redir(t_cmd *cmd)
{
	int		index0;
	int		index1;
	int		length;
	char	**redi_extracted;

	while (cmd)
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
				cmd->redir_sym[index1] = clean_quotes(redi_extracted[index0]);
			else
				cmd->redir_files[index1++] = clean_quotes(redi_extracted[index0]);
			free(redi_extracted[index0]);
		}
		free(redi_extracted);
		if (check_redir(cmd))
			return (1);
		cmd = cmd->next;
	}
	return (0);
}
