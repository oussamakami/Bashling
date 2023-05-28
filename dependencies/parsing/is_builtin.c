/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:43:26 by okamili           #+#    #+#             */
/*   Updated: 2023/05/28 01:11:28 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_builtin(char *cmd)
{
	int len;

	len = ft_strlen(cmd);
	if ((len == 3 && !ft_strncmp("pwd", cmd, 3))
		|| (len == 2 && !ft_strncmp("cd", cmd, 2)))
		return (1);
	return (0);
}