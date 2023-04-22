#ifndef CORE_H
# define CORE_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include <readline/readline.h>
# include <readline/history.h>
# include "dependencies/libft/libft.h"

typedef struct cmd_data
{
	char		*whole_cmd;
	char			*cmd;
	char			*options;
	char			*args;
	char			*redirection_file;
	char			*redirection_symbols;
	int				usepipe;
	char			*parsing_error;
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
 * @brief Add a node to the final element of the t_cmd tree.
 * 
 * @param head Reference to the beginning of the t_cmd tree.
 * @param new_command Reference to the node you intend to add.
 * @return t_cmd* The reference to the root node of the tree.
 */
t_cmd	*append_cmd_to_tree(t_cmd *head, t_cmd *new_command);
/**
 * @brief Delete and destroy a node from the t_cmd tree, regardless of whether or not it exists in the tree.
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

#endif