#include "core.h"

int main() {
	t_cmd *cmds;
    char* input;
	char **temp;
	int i = 0;
    while (1) {
        input = readline("user@hostname:directory$ ");
		add_history(input);
		cmds = input_split(input);
		while (cmds)
		{
			printf("%s\n", cmds->cmd);
			temp = parse_args(cmds->cmd);
			while (temp[i])
			{
				printf("arg%d: %s\n", i, temp[i]);
				i++;
			}
			i = 0;
			cmds = remove_cmd_from_tree(cmds, cmds);
		}
		i = 0;
		free(input);
    }
    return 0;
}