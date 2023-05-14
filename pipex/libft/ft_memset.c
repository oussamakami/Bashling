/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:32:42 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/01 17:32:43 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	t;
	char			*ptr;

	i = 0;
	ptr = (char *)s;
	t = (unsigned char)c;
	while (i < n)
	{
		ptr[i] = t;
		i++;
	}
	return (ptr);
}
