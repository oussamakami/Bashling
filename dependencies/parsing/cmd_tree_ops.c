/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:52:06 by okamili           #+#    #+#             */
/*   Updated: 2023/05/13 07:21:25 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd	*allocate_cmd_node(char *whole_command)
{
	t_cmd	*result;

	result = malloc(sizeof(t_cmd));
	result->cmd = whole_command;//
	result->exec = NULL;
	result->args = NULL;//
	result->redir_files = NULL;
	result->redir_sym = NULL;
	result->sep = NULL;//
	result->error = 0;
	result->next = NULL;
	return (result);
}

t_cmd	*last_cmd_node(t_cmd *head)
{
	if (head)
	{
		while (head->next)
			head = head->next;
	}
	return (head);
}

t_cmd	*previous_cmd_node(t_cmd *head, t_cmd *current_node)
{
	while (head && head->next != current_node)
		head = head->next;
	return (head);
}

t_cmd	*append_cmd_to_tree(t_cmd *head, t_cmd *new_command)
{
	if (head)
	{
		last_cmd_node(head)->next = new_command;
		return (head);
	}
	return (new_command);
}

t_cmd	*remove_cmd_from_tree(t_cmd *head, t_cmd *todelete)
{
	t_cmd	*temp;

	temp = previous_cmd_node(head, todelete);
	if (temp)
		temp->next = todelete->next;
	else
		head = todelete->next;
	erase_cmd_node(todelete);
	return (head);
}

void	erase_cmd_node(t_cmd *cmd_pointer)
{
	if (cmd_pointer)
	{
		free(cmd_pointer->cmd);
		free(cmd_pointer->exec);
		//args is a 2d array, still need its own func to free it
		free(cmd_pointer->args);
		free(cmd_pointer->redir_files);
		free(cmd_pointer->redir_sym);
		free(cmd_pointer);
	}
}

void	free_cmd_tree(t_cmd *head)
{
	while (head)
		head = remove_cmd_from_tree(head, head);
}
