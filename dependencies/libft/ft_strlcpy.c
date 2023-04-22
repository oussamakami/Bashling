/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 02:03:11 by okamili           #+#    #+#             */
/*   Updated: 2022/10/15 07:38:24 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//same as memcpy but it stopes at the null terminator

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	count;

	src_length = ft_strlen(src);
	if (!dstsize)
		return (src_length);
	count = 0;
	while (count < (dstsize - 1) && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (src_length);
}
