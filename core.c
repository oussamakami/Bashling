#include "core.h"

int	main()
{
	t_cmd	*cmds;
    char	*input;
	int		i;

    while (1)
	{
        input = prompt();
		add_history(input);
		cmds = parsing(input);
		free(input);
		while (cmds)
		{
			i = -1;
			printf("command: \"%s\"\n", cmds->cmd);
			printf("\texecutable: \"%s\"\n", cmds->exec);
			while (cmds->args[++i])
				printf("\targ%d: %s\n", i, cmds->args[i]);
			printf("\targ%d: %s\n", i, cmds->args[i]);
			printf("\tsep: \"%s\"\n", cmds->sep);
			cmds = remove_cmd_from_tree(cmds, cmds);
		}
    }
    return 0;
}