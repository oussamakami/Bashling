/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:32:37 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/01 17:32:38 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*p;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	p = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}
/* 
int main ()
{
	char	str1[];
	char	str2[];

  str1[] = "Geeks";
  str2[] = "Quiz";
  puts("str1 before memcpy ");
  puts(str1);
  memcpy (str1, str2, sizeof(str2));
  puts("\nstr1 after memcpy ");
  puts(str1);
  return (0);
}
 */
