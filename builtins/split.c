#include "builtins.h"

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

char	**ft_split2(char const *s, char c)
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


char **ft_split(char *str, char sep) {
    char **result = malloc(sizeof(char *) * 3);
    if (!result) {
        printf("Memory allocation error\n");
        return NULL;
    }
	char *sep_position = strchr(str, sep);
    if (sep_position) {
        int index = sep_position - str;
        result[0] = malloc(index + 1);
        strncpy(result[0], str, index);
        result[0][index] = '\0';

        result[1] = strdup(sep_position + 1);
    } else {
        // If separator doesn't exist in the string
        result[0] = strdup(str);
        result[1] = NULL;
    }
	result[2] = NULL; // End of array
    return result;
}


// int main()
// {
// 	char *str = "variable===value";

// 	char **string = ft_split_first(str, '=');

// 	printf("%s\n", string[0]);
// 	printf("%s\n", string[1]);

// }