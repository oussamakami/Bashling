/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:49:27 by okamili           #+#    #+#             */
/*   Updated: 2023/05/08 00:49:57 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	print_error(char *s)
{
	ft_putstr_fd("minishell: Syntax error near unexpected token `", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("'\n", 2);
}

static char	*get_separator(char *str)
{
	int		index;
	int		dquotes;
	int		squotes;
	char	*result;

	index = 0;
	dquotes = 0;
	squotes = 0;
	result = ft_calloc(2, 1);
	while (str[0])
	{
		if (ft_strchr(";|", str[0]) && (!(dquotes & 1) && !(squotes & 1)))
		{
			result[index++] = str[0];
			result = ft_realloc(result, ft_strlen(result) + 2);
		}
		dquotes += (!(squotes & 1) && str[0] == '"');
		squotes += (!(dquotes & 1) && str[0] == '\'');
		str++;
	}
	return (result);
}

int	check_separator(t_cmd *cmds)
{
	char	*temp;

	while (cmds)
	{
		temp = get_separator(cmds->cmd);
		if (ft_strlen(temp) == ft_strlen(cmds->cmd)
			|| (temp[0] == '|' && !cmds->next))
		{
			print_error(temp);
			free(temp);
			return (1);
		}
		free(temp);
		cmds = cmds->next;
	}
	return (0);
}
