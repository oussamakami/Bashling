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
			printf("\targuments:\n");
			while (cmds->args[++i])
				printf("\t\t%d: \"%s\"\n", i, cmds->args[i]);
			printf("\t\t%d: \"%s\"\n", i, cmds->args[i]);
			i = -1;
			printf("\tredirection:\n");
			while (cmds->redir_sym[++i])
				printf("\t\t%d: \"%s\"\n", i, cmds->redir_sym[i]);
			printf("\tseparator: \"%s\"\n", cmds->sep);
			printf("======================================\n");
			cmds = remove_cmd_from_tree(cmds, cmds);
		}
    }
    return 0;
}