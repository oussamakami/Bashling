#include "parsing.h"

static char	*next_redi(char *cmd)
{
	int	dquotes;
	int	squotes;

	dquotes = 0;
	squotes = 0;
	while (!ft_strchr("><", cmd[0]) || ((dquotes & 1) || (squotes & 1)))
	{
		dquotes += (!(squotes & 1) && cmd[0] == '"');
		squotes += (!(dquotes & 1) && cmd[0] == '\'');
		cmd++;
	}
	return (cmd);
}

static int	skip_spaces(char *cmd)
{
	int	count;

	count = 0;
	while (cmd[count] && ft_strchr("\t ", cmd[count]))
		count++;
	return (count);
}

static char	*extract_redi(char *cmd)
{
	int	i;
	int	dquotes;
	int	squotes;

	i = 0;
	dquotes = 0;
	squotes = 0;
	if (ft_strchr("><", cmd[i]))
	{
		while (ft_strchr("><", cmd[i]))
			i++;
		return (ft_substr(cmd, 0, i));
	}
	while (!ft_strchr("\t ><;|", cmd[i]) || ((dquotes & 1) || (squotes & 1)))
	{
		dquotes += (!(squotes & 1) && cmd[i] == '"');
		squotes += (!(dquotes & 1) && cmd[i] == '\'');
		i++;
	}
	return (ft_substr(cmd, 0, i));
}

static int	redi_count(char *cmd)
{
	int	count;

	count = 0;
	cmd = next_redi(cmd);
	while (cmd[0])
	{
		count++;
		while (ft_strchr("><", cmd[0]))
			cmd++;
		cmd = next_redi(cmd);
	}
	return (count);
}

char	**parse_redi(char *cmd)
{
	int		index;
	int		count;
	char	**result;

	index = 0;
	count = redi_count(cmd) * 2;
	result = ft_calloc(count + 1, sizeof(char *));
	while (cmd && index < count)
	{
		cmd = next_redi(cmd);
		result[index] = extract_redi(cmd);
		cmd += ft_strlen(result[index++]);
		cmd += skip_spaces(cmd);
		result[index++] = extract_redi(cmd);
	}
	return (result);
}
