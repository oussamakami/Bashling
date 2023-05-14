# include "parsing.h"

t_cmd *parsing(char *input)
{
	t_cmd	*result;
	t_cmd	*holder;

	result = input_split(input);
	holder = result;
	while (holder)
	{
		holder->args = parse_args(holder->cmd);
		holder->exec = holder->args[0];
		if (ft_strchr(";|", holder->cmd[ft_strlen(holder->cmd) - 1]))
			holder->sep = holder->cmd + (ft_strlen(holder->cmd) - 1);
		holder = holder->next;
	}
	parse_redir(result);
	return (result);
}