/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:01:37 by okamili           #+#    #+#             */
/*   Updated: 2022/10/07 00:06:03 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//copies dst to the src
//example dst = "hello" src = "test"
//result will be dst = "testo";

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_holder;
	unsigned char	*dst_holder;
	size_t			counter;

	src_holder = (unsigned char *) src;
	dst_holder = (unsigned char *) dst;
	if (!src_holder && !dst_holder)
		return (NULL);
	counter = 0;
	while (counter < n)
	{
		*(unsigned char *)(dst + counter) = src_holder[counter];
		counter++;
	}
	return (dst_holder);
}
