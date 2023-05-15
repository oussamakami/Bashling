/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 04:59:59 by yait-oul          #+#    #+#             */
/*   Updated: 2023/03/17 02:04:54 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mypipex.h"

int	ft_ispace(char ch, char c)
{
	return (ch == c);
}

int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_ispace(*str, c))
			str++;
		if (*str && !ft_ispace(*str, c))
		{
			count++;
			while (*str && !ft_ispace(*str, c))
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !ft_ispace(str[i], c))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_ispace(str[i], c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	char	*str;

	str = (char *)s;
	arr = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && ft_ispace(*str, c))
			str++;
		if (*str && !ft_ispace(*str, c))
		{
			arr[i] = malloc_word(str, c);
			i++;
			while (*str && !ft_ispace(*str, c))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
