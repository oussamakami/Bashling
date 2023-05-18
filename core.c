#include "core.h"

void	sig_handler(int sign)
{
	char *msg;
	if (sign == SIGINT)
	{
		msg = prompt_msg();
		printf("\n%s", msg);
		free(msg);
	}
}


int	main()
{
	t_cmd	*cmds;
    char	*input;
	int		i;

	signal(SIGINT, sig_handler);
    while (1)
	{
        input = prompt();
		if (!input)
		{
			printf("\n");
			exit(0);
		}
		add_history(input);
		cmds = parsing(input);
		free(input);
		while (cmds)
		{
			i = -1;
			if (!cmds->error){
			printf("command: \"%s\"\n", cmds->cmd);
			printf("\texecutable: \"%s\" %d\n", cmds->exec, cmds->error);
			printf("\targuments:\n");
			while (cmds->args[++i])
				printf("\t\t%d: \"%s\"\n", i, cmds->args[i]);
			printf("\t\t%d: \"%s\"\n", i, cmds->args[i]);
			i = -1;
			printf("\tredirection:\n");
			while (cmds->redir_sym[++i])
				printf("\t\t%d: \"%s\", \"%s\"\n", i, cmds->redir_sym[i], cmds->redir_files[i]);
			printf("\tseparator: \"%s\"\n", cmds->sep);
			printf("======================================\n");
			}
			cmds = remove_cmd_from_tree(cmds, cmds);
		}
    }
    return 0;
}