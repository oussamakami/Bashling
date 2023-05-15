/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:33:02 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/01 17:38:58 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(char const *s1, char const *s2)
{
	int	i;
	int	j;
	int	total;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	total = i + j;
	return (total);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_size(s1, s2);
	size++;
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s1, size);
	ft_strlcat(ptr, (char *)s2, size);
	return (ptr);
}
