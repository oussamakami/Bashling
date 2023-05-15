/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:52:22 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/01 17:32:41 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	s = (char *)src;
	d = (char *)dest;
	i = -1;
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
		while (++i < n)
			d[i] = s[i];
	return (dest);
}
/* 
int	main(void)
{
	char	str1[];

	str1[] = "Geeks";
	char str2[] = "Quiz"; 
	puts("str1 before memmove ");
	puts(str1);
	ft_memmove(str1+2, str1, sizeof(str2));
	puts("\nstr1 after memmove ");
	puts(str1);
	return (0);
}
 */
