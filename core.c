#include "core.h"


int	args_count(char *cmd)
{
	int	count;
	int	dquotes;
	int	squotes;

	count = 0;
	dquotes = 0;
	squotes = 0;
	while (cmd[0])
	{
		if(ft_strchr("><", cmd[0]) && (!(dquotes & 1) && !(squotes & 1)))
		{
			while (ft_strchr("><", cmd[0]))
				cmd++;
			count--;
		}
		if (!ft_strchr("\t |;", cmd[0]) && (!(dquotes & 1) && !(squotes & 1)))
		{
			count++;
			while(!ft_strchr("\t ><", cmd[0]) || ((dquotes & 1) || (squotes & 1)))
			{
				dquotes += (!(squotes & 1) && cmd[0] == '"');
				squotes += (!(dquotes & 1) && cmd[0] == '\'');
				cmd++;
			}
		}
		else
			cmd++;
	}
	return count;
}


int main() {
	t_cmd *cmds;
    char* input;
	int i = 0;
    while (1) {
        input = readline("user@hostname:directory$ ");
		add_history(input);
		cmds = input_split(input);
		while (cmds)
		{
			printf("%d= %s (length: %d)\n", ++i, cmds->cmd, args_count(cmds->cmd));
			cmds = remove_cmd_from_tree(cmds, cmds);
		}
		i = 0;
		free(input);
    }
    return 0;
}