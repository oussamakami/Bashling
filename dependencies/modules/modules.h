/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modules.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:49:02 by okamili           #+#    #+#             */
/*   Updated: 2023/05/15 12:10:27 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULES_H
# define MODULES_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

void	*ft_realloc(void *ptr, size_t size);
char	*get_work_dir(void);
char	*get_host_name(void);
char	*prompt(void);
void	free2d(void **ptr);
char	*replace_word(char *str, char *w0, char *w1, int usefree);
char	*replace_all_words(char *str, char *w0, char *w1, int usefree);

#endif