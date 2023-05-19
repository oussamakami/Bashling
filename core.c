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
		cmds = input_split(input);
		parsing(cmds);
		free(input);
		while (cmds)
		{
			if (cmds->sep && cmds->sep[0] == '|')
				cmds = run_pipe_commands(cmds);
			else
				run_cmd(cmds);
			cmds = get_next_cmd(cmds);
		}
    }
    return 0;
}