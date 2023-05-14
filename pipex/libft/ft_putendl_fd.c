/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:32:47 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/03 19:11:52 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// int main(void)
// {
// 	int fd;
// 	fd = open("fichierr.txt",O_RDWR );
// 	char *s = "yessir\n";
// 	ft_putendl_fd(s, fd);
// 	close(fd);
// 	return (0);
// }