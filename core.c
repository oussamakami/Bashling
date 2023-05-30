/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 03:06:38 by okamili           #+#    #+#             */
/*   Updated: 2023/05/31 00:44:24 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	sig_handler(int sign)
{
	if (sign == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay(); 
	}
}

int	main(int argc, char **argv, char **env)
{
	int		err;
	char	*input;
	t_cmd	*cmds;

	env_init(argc, argv, env);
	signal(SIGINT, sig_handler);
	err = 0;
	while (1)
	{
		input = prompt();
		if (!input)
		{
			printf("\nexit\n");
			close_prgm(NULL);
		}
		add_history(input);
		cmds = input_split(input, &err);
		if (cmds)
			cmds->prev_error = err;
		parsing(cmds);
		free(input);
		while (cmds)
		{
			if (cmds->sep && cmds->sep[0] == '|')
				cmds = run_pipe_commands(cmds, &err);
			else
				run_commands(cmds);
			cmds = get_next_cmd(cmds, &err);
		}
	}
	return (0);
}
