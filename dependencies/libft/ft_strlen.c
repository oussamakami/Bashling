/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:36:33 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 08:27:40 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//return the length of the string

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	total;

	total = 0;
	while (s[total] != '\0')
	{
		total++;
	}
	return (total);
}
