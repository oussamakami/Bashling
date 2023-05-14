/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul < yait-oul@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 05:03:48 by yait-oul          #+#    #+#             */
/*   Updated: 2023/04/22 02:50:38 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mypipex.h"

void	childs_check(int num)
{
	perror("Fork");
	exit(num);
}



int	check_args(int argc, char *argv[])
{
	if (argc != 5)
	{
		ft_printf("Invalid number of arguments.\n");
		exit(1);
	}
	if (argv[1] == NULL)
	{
		ft_printf("bash: %s: No such file or directory\n", argv[1]);
		return (0);
	}
	return (0);
}

void	if_awk(t_bipex pipex, char **argv)
{
	int		err;
	char	**mycmdargs;

	err = 77;
	mycmdargs = NULL;
	if (ft_strstr(argv[2], "awk ") != NULL)
	{
		mycmdargs = create_2d_array(4, ft_strlen(argv[2]));
		mycmdargs[0] = "awk";
		mycmdargs[1] = get_string_inside_single_quote(argv[2]);
		mycmdargs[2] = NULL;
		pipex.mycmdargs = mycmdargs;
		pipex.comd = pathcmmd(pipex.mypaths, pipex.mycmdargs[0], &err);
		dup2(pipex.end_pipe[1], 1);
		close(pipex.end_pipe[0]);
		dup2(pipex.file1, 0);
		if (!pipex.comd)
		{
			freeing_childs(&pipex);
			exit(1);
		}
		execve(pipex.comd, pipex.mycmdargs, NULL);
		exit(err);
	}
}
