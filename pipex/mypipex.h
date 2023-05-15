/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mypipex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 05:15:41 by yait-oul          #+#    #+#             */
/*   Updated: 2023/05/14 19:35:53 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYPIPEX_H
# define MYPIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# define MAX_PATHS 1000
# define EXIT_FAILURE 1

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	pid_t	child1;
	pid_t	child2;
	int		end_pipe[2];
	int		file1;
	int		file2;
	char	*paths;

	char	*comd;
	char	**envp;
	char	**mypaths;
	char	**mycmdargs;
}			t_bipex;

void		if_empty(char *f1);
int			search_for_word(char *input, char *word);
int			check_for_errors_files(char *file);
void		if_awk(t_bipex pipex, char **argv);
void		send_to_pipex(t_bipex pipex, char **argv);
int			code_exit(t_bipex pipex, char **envp, char **argv);
char		*envp_path(char **envp);
int			check_args(int argc, char *argv[]);
char		*get_string_inside_single_quote(char *input);
int			message(char *str);
char		**freeing(char **arr, char *s);
int			is_separator(char c, char *charset);
int			is_word(char c, char cbefore, char *charset);
int			get_words_count(char *str, char *charset);
int			*get_words_size(char *str, char *charset);
void		childs_check(int num);
char		**ft_split2(char *str, char *charset);
char		**ft_split(char const *s, char c);

char		*retrieve_p(char *argv, char **cenvp);
char		*ft_join(const char *str1, const char *str2);
char		*get_string_inside_single_quote(char *input);
char		**create_2d_array(int rows, int cols);
char		**cmd_args(char *argv);
char		**copy_envp(char **envp);
void		message_erreur(char *msg);
void		scriptchecking(char *argv);
char		*pathcmmd(char **paths, char *cmd, int *err);
char		*pathcmmd2(char **paths, char *cmd, int *err);
void		freeing_childs(t_bipex *pipex);
void		is_script(char *str);

void		freeing_par(t_bipex *pipex);
char		*retrieve_path(char *argv, char **cenvp);
char		**copy_envp(char **envp);
void		close_p(t_bipex *pipex);
int			child_one(t_bipex pipex, char **argv);
int			child_two(t_bipex pipex, char **argv);
int 		pipexx(int ac, char **argv, char **envp, t_bipex *pipex);
int 		pipexx_without_red(int ac, char **argv, char **envp, t_bipex *pipex);

#endif
