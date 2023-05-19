#ifndef EXECUTIONS_H
# define EXECUTIONS_H

# include <sys/wait.h>
# include "../libft/libft.h"
# include "../parsing/parsing.h"

void run_cmd(t_cmd *cmd);
t_cmd *run_pipe_commands(t_cmd *cmds);
// t_cmd	*run_cmds_pipe(t_cmd *cmd);
#endif