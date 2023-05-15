/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:16:30 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/01 16:16:31 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		*(unsigned char *)s = '\0';
		s++;
		n--;
	}
}

/*
int	main(void)
{
	char	str[50];

    str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore bzero(): %s\n", str);
  
    // Fill 8 characters starting from str[13] with '.'
    ft_bzero(str + 2, 8);
  
    printf("After bzero():  %s", str);
    return (0);
}
*/
