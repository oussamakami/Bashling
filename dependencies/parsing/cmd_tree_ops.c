# include "../../core.h"

t_cmd *allocate_cmd_node(char *whole_command)
{
	t_cmd *result;

	result = malloc(sizeof(t_cmd));
	result->whole_cmd = whole_command;
	result->cmd = NULL;
	result->options = NULL;
	result->args = NULL;
	result->redirection_file = NULL;
	result->redirection_symbols = NULL;
	result->usepipe = 0;
	result->parsing_error = NULL;
	result->next = NULL;
	return (result);
}

t_cmd *append_cmd_to_tree(t_cmd *head, t_cmd *new_command)
{
	t_cmd *temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_command;
	return (head);
}

t_cmd *remove_cmd_from_tree(t_cmd *head, t_cmd *todelete)
{
	t_cmd *result;
	if (todelete == head)
	{
		result = todelete->next;
		erase_cmd_node(todelete);
		return (result);
	}
	result = head;
	while (head && head->next != todelete)
		head = head->next;
	if (head)
		head->next = todelete->next;
	erase_cmd_node(todelete);
	return (result);
}

void	erase_cmd_node(t_cmd *cmd_pointer)
{
	if (cmd_pointer)
	{
		free(cmd_pointer->whole_cmd);
		free(cmd_pointer->cmd);
		free(cmd_pointer->options);
		free(cmd_pointer->args);
		free(cmd_pointer->redirection_file);
		free(cmd_pointer->redirection_symbols);
		free(cmd_pointer->parsing_error);
		free(cmd_pointer);
	}
}

void free_cmd_tree(t_cmd *head)
{
	while (head)
		head = remove_cmd_from_tree(head, head);
}