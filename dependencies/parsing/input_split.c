/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:40:21 by okamili           #+#    #+#             */
/*   Updated: 2023/06/09 12:34:02 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_quotes_loop(char *str)
{
	int	dquotes;
	int	squotes;

	dquotes = 0;
	squotes = 0;
	while (str[0])
	{
		dquotes += (!(squotes & 1) && str[0] == '"');
		squotes += (!(dquotes & 1) && str[0] == '\'');
		str++;
	}
	return ((squotes & 1) || (dquotes & 1));
}

static int	check_quotes(t_cmd *cmds)
{
	while (cmds)
	{
		if (check_quotes_loop(cmds->cmd))
		{
			ft_putstr_fd("Minishell: syntax error: Missing closing quote.\n", 2);
			return (1);
		}
		cmds = cmds->next;
	}
	return (0);
}

static int	command_length(char *str)
{
	int	length;
	int	dquotes;
	int	squotes;

	length = 0;
	dquotes = 0;
	squotes = 0;
	while (str[0])
	{
		length++;
		if (ft_strchr(";|", str[0]) && (!(dquotes & 1) && !(squotes & 1)))
			return (length);
		dquotes += (!(squotes & 1) && str[0] == '"');
		squotes += (!(dquotes & 1) && str[0] == '\'');
		str++;
	}
	return (length);
}

static char	*read_heredoc(char *str)
{
	char	*buffer;
	char	*result;
	char	*tmp;

	result = ft_strdup("");
	while (1)
	{
		buffer = readline(">");
		if (!buffer)
		{
			free(result);
			return (NULL);
		}
		if (ft_strlen(buffer) == ft_strlen(str)
			&& !ft_strncmp(str, buffer, ft_strlen(str)))
		{
			free(buffer);
			return (result);
		}
		tmp = ft_strjoin(result, buffer);
		free(result);
		result = ft_strjoin(tmp, "\n");
		free(tmp);
		free(buffer);
	}
}

static void	manage_heredoc(t_cmd *cmds)
{
	int		i;
	t_cmd	*tmp;

	tmp = cmds;
	while (tmp)
	{
		i = -1;
		while (tmp->redir_sym && tmp->redir_sym[++i])
		{
			if (ft_strlen(tmp->redir_sym[i]) == 2
				&& !ft_strncmp("<<", tmp->redir_sym[i], 2))
			{
				free(tmp->heredoc_data);
				tmp->heredoc_data = read_heredoc(tmp->redir_files[i]);
			}
		}
		tmp = tmp->next;
	}
}

t_cmd	*input_split(char *input, int *err)
{
	t_cmd	*result;
	char	*temp;

	result = NULL;
	while (input[0])
	{
		temp = ft_substr(input, 0, command_length(input));
		result = append_cmd_to_tree(result,
				allocate_cmd_node(ft_strtrim(temp, "\t ")));
		if (!ft_strlen(last_cmd_node(result)->cmd))
			result = remove_cmd_from_tree(result, last_cmd_node(result));
		input += ft_strlen(temp);
		free(temp);
	}
	if (check_separator(result) || check_quotes(result) || parse_redir(result))
	{
		free_cmd_tree(result);
		*err = 2;
		return (NULL);
	}
	manage_heredoc(result);
	return (result);
}
