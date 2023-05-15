/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removingquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 05:45:45 by yait-oul          #+#    #+#             */
/*   Updated: 2023/03/17 03:08:59 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mypipex.h"

char	*get_string_inside_single_quote(char *input)
{
	char	*output;
	char	*start;
	char	*end;
	size_t	length;

	output = NULL;
	start = ft_strchr(input, '\'');
	end = ft_strrchr(input, '\'');
	if (start && end && start != end)
	{
		length = end - start - 1;
		output = (char *)malloc((length + 1) * sizeof(char));
		ft_strncpy(output, start + 1, length);
		output[length] = '\0';
	}
	else
		return (input);
	return (output);
}
