/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:39:36 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/01 17:39:42 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*ptr;

	if (!s1)
		return (0);
	while (ft_strchr(set, *(char *)s1) && *s1)
		s1++;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len - 1]) && len > 0)
		len--;
	ptr = ft_substr(s1, 0, len);
	return (ptr);
}
// int main()
// {
//     char const *s1 = "              ";
// 	printf("%s \n", ft_strtrim(s1," "));
//     return(0);
// }
