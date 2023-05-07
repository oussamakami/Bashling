/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:40:21 by okamili           #+#    #+#             */
/*   Updated: 2023/05/08 00:50:36 by okamili          ###   ########.fr       */
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
			ft_putstr_fd("minishell: Syntax error: Missing closing quote.\n", 2);
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

t_cmd	*input_split(char *input)
{
	t_cmd	*result;
	char	*temp;

	result = NULL;
	while (input[0])
	{
		temp = ft_substr(input, 0, command_length(input));
		result = append_cmd_to_tree(result,
				allocate_cmd_node(ft_strtrim(temp, "\t ")));
		input += ft_strlen(temp);
		free(temp);
	}
	if (check_separator(result) || check_quotes(result))
	{
		free_cmd_tree(result);
		return (NULL);
	}
	return (result);
}
