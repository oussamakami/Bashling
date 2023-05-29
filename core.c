/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 03:06:38 by okamili           #+#    #+#             */
/*   Updated: 2023/05/29 03:09:04 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	sig_handler(int sign)
{
	char	*msg;

	if (sign == SIGINT)
	{
		msg = prompt_msg();
		printf("\n%s", msg);
		free(msg);
	}
}

int	main(void)
{
	int		err;
	char	*input;
	t_cmd	*cmds;

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
