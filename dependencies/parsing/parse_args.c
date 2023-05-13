# include "parsing.h"

int next_arg(char *cmd)
{
	int index;
	int	dquotes;
	int	squotes;

	index = 0;
	dquotes = 0;
	squotes = 0;
	while(cmd[index] && (!ft_strchr("\t |;", cmd[index]) || (dquotes & 1) || (squotes & 1)))
	{
		dquotes += (!(squotes & 1) && cmd[index] == '"');
		squotes += (!(dquotes & 1) && cmd[index] == '\'');
		index++;
	}
	while (cmd[index] && (ft_strchr("\t |;", cmd[index])))
		index++;
	return index;
}

int args_count(char *cmd)
{
	int count;

	count = 0;
	while (cmd[0])
	{
		if (!ft_strchr("\t |;", cmd[0]))
		{
			count++;
			cmd += next_arg(cmd);
		}
	}
	return count;
}







// int	args_count(char *cmd)
// {
// 	int	count;
// 	int	dquotes;
// 	int	squotes;

// 	count = 0;
// 	while (cmd[0])
// 	{
// 		if(ft_strchr("><", cmd[0]) && (!(dquotes & 1) && !(squotes & 1)))
// 		{
// 			while (ft_strchr("><", cmd[0]))
// 				cmd++;
// 			count--;
// 		}
// 		if (!ft_strchr("\t |;", cmd[0]) && (!(dquotes & 1) && !(squotes & 1)))
// 		{
// 			count++;
// 			while(!ft_strchr("\t ><", cmd[0]) || ((dquotes & 1) || (squotes & 1)))
// 			{
// 				dquotes += (!(squotes & 1) && cmd[0] == '"');
// 				squotes += (!(dquotes & 1) && cmd[0] == '\'');
// 				cmd++;
// 			}
// 		}
// 		else
// 			cmd++;
// 	}
// 	return count;
// }