/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_variables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:42:17 by okamili           #+#    #+#             */
/*   Updated: 2023/05/27 23:13:13 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	next_variable(char *str, int index)
{
	int	i;
	int	dquotes;
	int	squotes;

	i = -1;
	dquotes = 0;
	squotes = 0;
	while (++i < index && str[i])
	{
		dquotes += (!(squotes & 1) && str[i] == '"');
		squotes += (!(dquotes & 1) && str[i] == '\'');
	}
	while ((str[i] && (str[i] != '$' || (squotes & 1)))
		|| (str[i] == '$' && !(squotes & 1)
			&& ft_strchr("\t ><;\"|'$", str[i + 1])))
	{
		dquotes += (!(squotes & 1) && str[i] == '"');
		squotes += (!(dquotes & 1) && str[i] == '\'');
		i++;
	}
	if (str[i] == '$')
		return (i);
	return (-1);
}

static char	*get_variable_name(char *str, int index)
{
	int	i;

	i = index + 1;
	while (str[i] && !ft_strchr("\t ><;\"|'$", str[i]))
		i++;
	return (ft_substr(str, index, i - index));
}

char	*replace_variables(char *str, int err)
{
	int		var_index;
	char	*var_name;
	char	*temp;
	char	*result;

	result = ft_strdup(str);
	var_index = next_variable(result, 0);
	while (var_index != -1)
	{
		var_name = get_variable_name(result, var_index);
		temp = replace_all_words(var_name, "$", NULL, 0);
		if (ft_strncmp("$?", var_name, 3))
			result = replace_word(result, var_name, fetch(temp), 1);
		else
		{
			free(temp);
			temp = ft_itoa(err);
			result = replace_word(result, var_name, temp, 1);
		}
		free(temp);
		free(var_name);
		var_index = next_variable(result, 0);
	}
	return (result);
}
