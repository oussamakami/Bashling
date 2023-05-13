#include "parsing.h"

char	*next_arg(char *cmd)
{
	int	dquotes;
	int	squotes;

	dquotes = 0;
	squotes = 0;
	while (!ft_strchr("\t ><", cmd[0]) || ((dquotes & 1) || (squotes & 1)))
	{
		dquotes += (!(squotes & 1) && cmd[0] == '"');
		squotes += (!(dquotes & 1) && cmd[0] == '\'');
		cmd++;
	}
	return (cmd);
}

int	args_count(char *cmd)
{
	int	count;

	count = 0;
	while (cmd[0])
	{
		if (ft_strchr("><", cmd[0]))
		{
			while (ft_strchr("><", cmd[0]))
				cmd++;
			count--;
		}
		else if (!ft_strchr("\t |;", cmd[0]))
		{
			count++;
			cmd = next_arg(cmd);
		}
		else
			cmd++;
	}
	return (count);
}
