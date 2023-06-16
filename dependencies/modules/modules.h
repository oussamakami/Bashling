/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modules.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:49:02 by okamili           #+#    #+#             */
/*   Updated: 2023/06/16 15:19:40 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULES_H
# define MODULES_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct env_vars
{
	char			*name;
	char			*value;
	int				hide;
	struct env_vars	*next;
}	t_env;

/**
 * @brief A global variable that stores the reference to
 * the linked list encompassing all environment variables.
 */
extern t_env	*g_env;
/**
 * @brief Modify the size of a previously allocated memory.
 * 
 * @param ptr Pointer to the memory block that you wish to resize.
 * @param size The new memory size.
 * @return void* Pointer to a newly allocated memory block with the updated size.
 */
void	*ft_realloc(void *ptr, size_t size);
/**
 * @brief Retrieve the value of an environment variable by its name.
 * 
 * @param var_name The identifier/name of the environment variable.
 * @return char* The corresponding value of that environment variable.
 */
char	*fetch(char *var_name);
char	*get_work_dir(void);
char	*get_host_name(void);
char	*extract_branch(char *buff);
char	*prompt_msg(void);
char	*prompt(void);
char	*replace_word(char *str, char *w0, char *w1, int usefree);
char	*replace_all_words(char *str, char *w0, char *w1, int usefree);
t_env	*add_env(t_env *head, char *name, char *value);
t_env	*last_env(t_env *head);
t_env	*find_env(t_env *head, char *name);
void	destory_all_env(t_env *head);
void	free2d(void **ptr);
void	env_init(int argc, char **argv, char **env);
char	**export_env(void);

#endif