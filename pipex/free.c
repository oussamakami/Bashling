/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 04:43:44 by yait-oul          #+#    #+#             */
/*   Updated: 2023/03/17 03:12:16 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mypipex.h"

void	freeing_par(t_bipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->mypaths[i])
	{
		free(pipex->mypaths[i]);
		i++;
	}
	free(pipex->mypaths);
}

void	freeing_childs(t_bipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->mycmdargs[i])
	{
		free(pipex->mycmdargs[i]);
		i++;
	}
	free(pipex->mycmdargs);
	free(pipex->comd);
}
