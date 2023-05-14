/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:39:18 by yait-oul          #+#    #+#             */
/*   Updated: 2023/03/17 03:06:06 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && haystack[i + j] && i + j < len && haystack[i
					+ j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
// char	*ft_strnstr(const char *big, const char *little, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = (char *)big;
// 	j = 0;
// 	i = 0;
// 	if (!big && len == 0)
// 		return (NULL);
// 	if (little[0] == '\0' || len == 0)
// 		return ((char *)big);
// 	while (str[i] != '\0' && i < len)
// 	{
// 		j = 0;
// 		while (str[i + j] == little[j] && (i + j) < len && str[i + j]
// 			&& little[j])
// 		{
// 			if (little[j + 1] == '\0')
// 				return ((char *)(str + i));
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

/* int main(void) 
{
  char haystack[] = "This is the way.";
  char needle[] = "the";

  char *the = ft_strnstr(haystack, needle, 15);
  printf("the: %s\n" , the);
  char *fail = ft_strnstr(haystack, now,3);
  if (fail == NULL) printf("failed to find string!\n");
*/
