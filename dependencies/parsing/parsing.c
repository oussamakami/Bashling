#include "parsing.h"

t_cmd	*parsing(char *input)
{
	t_cmd	*result;
	t_cmd	*holder;
	char	*temp;

	result = input_split(input);
	holder = result;
	while (holder)
	{
		temp = replace_variables(holder->cmd);
		holder->args = parse_args(temp);
		free(temp);
		holder->exec = holder->args[0];
		if (ft_strchr(";|", holder->cmd[ft_strlen(holder->cmd) - 1]))
			holder->sep = holder->cmd + (ft_strlen(holder->cmd) - 1);
		holder = holder->next;
	}
	parse_redir(result);
	return (result);
}
