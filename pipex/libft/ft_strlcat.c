/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:34:31 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/03 20:10:11 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len_src;
	unsigned int	len_dst;
	unsigned int	len;
	char			*ptr;

	ptr = dst;
	if (ptr == NULL && size == 0)
		return (0);
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	len = 0;
	i = 0;
	if (size == 0)
		return (len_src);
	if (size < len_dst)
		return (size + len_src);
	while (dst[len] != '\0')
		len++;
	while (src[i] != '\0' && len < size - 1)
	{
		dst[len++] = src[i++];
	}
	dst[len] = '\0';
	return (len_dst + len_src);
}
