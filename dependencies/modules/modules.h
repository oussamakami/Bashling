/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modules.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:49:02 by okamili           #+#    #+#             */
/*   Updated: 2023/05/31 04:47:09 by okamili          ###   ########.fr       */
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

extern t_env	*g_env;
void	*ft_realloc(void *ptr, size_t size);
char	*get_work_dir(void);
char	*get_host_name(void);
char	*prompt(void);
char	*prompt_msg(void);
void	free2d(void **ptr);
char	*replace_word(char *str, char *w0, char *w1, int usefree);
char	*replace_all_words(char *str, char *w0, char *w1, int usefree);
t_env	*last_env(t_env *head);
t_env	*find_env(t_env *head, char *name);
t_env	*add_env(t_env *head, char *name, char *value);
void	destory_all_env(t_env *head);
char	*fetch(char *var_name);
void	env_init(int argc, char **argv, char **env);

#endif