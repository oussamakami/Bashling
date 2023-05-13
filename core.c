#include "core.h"

int main() {
	t_cmd *cmds;
    char* input;
	int i = 0;
    while (1) {
        input = readline("user@hostname:directory$ ");
		add_history(input);
		cmds = parsing(input);
		while (cmds)
		{
			printf("command: \"%s\"\n", cmds->cmd);
			printf("\texecutable: \"%s\"\n", cmds->exec);
			while (cmds->args[i])
			{
				printf("\targ%d: %s\n", i, cmds->args[i]);
				i++;
			}
			printf("\targ%d: %s\n", i, cmds->args[i]);
			printf("\tsep: \"%s\"\n\n", cmds->sep);
			i = 0;
			cmds = remove_cmd_from_tree(cmds, cmds);
		}
		i = 0;
		free(input);
    }
    return 0;
}