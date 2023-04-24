/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:40:21 by okamili           #+#    #+#             */
/*   Updated: 2023/05/04 23:51:52 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
		if (ft_strchr(";|&", str[0]) && (!(dquotes & 1) && !(squotes & 1)))
		{
			if (ft_strchr(";|&", str[0]) && ft_strchr(";|&", str[1]))
			{
				if (ft_strchr(";|&", str[2]))
					return (length + 2);
				return (length + 1);
			}
			return (length);
		}
		dquotes += (str[0] == '"');
		squotes += (str[0] == '\'');
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
	return (result);
}
