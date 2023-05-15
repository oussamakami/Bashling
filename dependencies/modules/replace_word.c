#include "modules.h"

static int	new_str_size(char *str, char *w0, char *w1)
{
	size_t	w0_len;
	size_t	w1_len;
	size_t	str_len;
	size_t	match_count;

	w0_len = ft_strlen(w0);
	w1_len = ft_strlen(w1);
	str_len = ft_strlen(str);
	match_count = 0;
	while (str && w0 && str[0])
	{
		if (!ft_strncmp(str, w0, w0_len))
			match_count++;
		str++;
	}
	return (str_len + ((w1_len - w0_len) * match_count));
}

//need to handle if one or more of the arguments is null
char	*replace_word(char *str, char *w0, char *w1)
{
	char	*result;
	size_t	w0_len;
	size_t	w1_len;
	size_t	result_length;

	w0_len = ft_strlen(w0);
	w1_len = ft_strlen(w1);
	result_length = new_str_size(str, w0, w1);
	result = ft_calloc(result_length + 1, 1);
	while (str && str[0])
	{
		if (w0 && !ft_strncmp(str, w0, w0_len))
		{
			ft_strlcpy(result, w1, result_length);
			result += w1_len;
			str += w0_len;
		}
		else
			*result++ = *str++;
	}
	result -= result_length;
	return (result);
}
