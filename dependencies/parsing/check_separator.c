#include "parsing.h"

static void	print_error(char *s)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("'\n", 2);
}

static char	*get_separator(char *str)
{
	int		index;
	int		dquotes;
	int		squotes;
	char	*result;

	index = 0;
	dquotes = 0;
	squotes = 0;
	result = ft_calloc(2, 1);
	while (str[0])
	{
		if (ft_strchr(";|", str[0]) && (!(dquotes & 1) && !(squotes & 1)))
		{
			result[index++] = str[0];
			result = ft_realloc(result, ft_strlen(result) + 2);
		}
		dquotes += (str[0] == '"');
		squotes += (str[0] == '\'');
		str++;
	}
	return (result);
}

int	check_separator(t_cmd *cmd)
{
	char	*temp;

	while (cmd)
	{
		temp = get_separator(cmd->whole_cmd);
		if (ft_strlen(temp) == ft_strlen(cmd->whole_cmd))
		{
			print_error(temp);
			free(temp);
			return (1);
		}
		free(temp);
		cmd = cmd->next;
	}
	return (0);
}
