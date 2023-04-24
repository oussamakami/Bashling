#include "core.h"

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
			printf("%d= %s\n", ++i, cmds->whole_cmd);
			cmds = remove_cmd_from_tree(cmds, cmds);
		}
		free(input);
    }
    return 0;
}