/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamili <okamili@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:48:10 by okamili           #+#    #+#             */
/*   Updated: 2023/05/28 03:47:02 by okamili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTIONS_H
# define EXECUTIONS_H

# include <sys/wait.h>
# include "../libft/libft.h"
# include "../modules/modules.h"
# include "../parsing/parsing.h"

void	pwd(void);
void	cd(t_cmd *cmd);
void	echo(t_cmd *cmd);
void	run_builtins(t_cmd *cmd);
void	run_commands(t_cmd *cmd);
t_cmd	*run_pipe_commands(t_cmd *cmds, int *err);
#endif