/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:50:54 by okamili           #+#    #+#             */
/*   Updated: 2023/05/14 03:51:06 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include "../modules/modules.h"

typedef struct cmd_data
{
	char			*cmd;
	char			*exec;
	char			**args;
	char			**redir_files;
	char			**redir_sym;
	char			*sep;
	int				error;
	struct cmd_data	*next;
}	t_cmd;

/**
 * @brief Generate a new node to store command information.
 * 
 * @param whole_command The command initially inputted by the user.
 * @return t_cmd* Reference to a node that holds that command information.
 */
t_cmd	*allocate_cmd_node(char *whole_command);
/**
 * @brief Locate the final node within the t_cmd tree.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 * @return t_cmd* Reference to the last node.
 */
t_cmd	*last_cmd_node(t_cmd *head);
/**
 * @brief Locate the node that is pointing to your current node.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 * @param current_node Reference to current node.
 * @return t_cmd* Reference to the located node.
 */
t_cmd	*previous_cmd_node(t_cmd *head, t_cmd *current_node);
/**
 * @brief Add a node to the final element of the t_cmd tree.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 * @param new_command Reference to the node you intend to add.
 * @return t_cmd* The reference to the root node of the tree.
 */
t_cmd	*append_cmd_to_tree(t_cmd *head, t_cmd *new_command);
/**
 * @brief Delete and destroy a node from the t_cmd tree,
 * regardless of whether or not it exists in the tree.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 * @param todelete eference to the node you intend to delete.
 * @return t_cmd* The reference to the root node of the tree.
 */
t_cmd	*remove_cmd_from_tree(t_cmd *head, t_cmd *todelete);
/**
 * @brief Destroy a t_cmd node.
 * 
 * @param cmd_pointer Reference to the node you intend to destroy.
 */
void	erase_cmd_node(t_cmd *cmd_pointer);
/**
 * @brief Remove all nodes within a t_cmd tree.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 */
void	free_cmd_tree(t_cmd *head);
t_cmd	*input_split(char *input);
int		check_separator(t_cmd *cmd);
char **parse_args(char *cmd);
t_cmd *parsing(char *input);

#endif