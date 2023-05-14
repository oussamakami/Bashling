#include "parsing.h"


void	init_redi_arg(t_cmd *cmd, int size)
{
		cmd->redir_files = ft_calloc(size + 1, sizeof(char *));
		cmd->redir_sym = ft_calloc(size + 1, sizeof(char *));
}


void	parse_redir(t_cmd *head)
{
	int index0;
	int	index1;
	int length;
	char **redi_extracted;

	while (head)
	{
		index0 = 0;
		index1 = 0;
		redi_extracted = extract_redir(head->cmd);
		length = ft_atoi(redi_extracted[0]);
		init_redi_arg(head, length / 2);
		while (++index0 <= length)
		{
			if (index0%2)
				head->redir_sym[index1] = redi_extracted[index0];
			else
				head->redir_files[index1++] = redi_extracted[index0];
		}
		free(redi_extracted);
		head = head->next;
	}
}
