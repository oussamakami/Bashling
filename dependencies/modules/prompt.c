#include "modules.h"
#include <fcntl.h>

char	*get_work_dir(void)
{
	char	*home_dir;
	char	*work_dir;
	size_t	work_len;
	size_t	home_len;

	home_dir = getenv("HOME");
	work_dir = getcwd(NULL, 0);
	home_len = ft_strlen(home_dir) - 1;
	work_len = ft_strlen(work_dir);
	if (!work_dir)
		return (NULL);
	if (home_dir && !ft_strncmp(work_dir, home_dir, home_len))
	{
		home_dir = ft_substr(work_dir, home_len, (work_len - home_len));
		home_dir[0] = '~';
		free(work_dir);
		return (home_dir);
	}
	return (work_dir);
}

char	*get_host_name(void)
{
	int		fd;
	char	*buff;

	fd = open("/etc/hostname", O_RDONLY);
	buff = ft_calloc(1024, 1);
	read(fd, buff, 1024);
	close(fd);
	if (buff && buff[ft_strlen(buff)-1] == '\n')
		buff[ft_strlen(buff) - 1] = '\0';
	return (buff);
}

char	*prompt(void)
{
	char	*user;
	char	*host;
	char	*dir;

	user = getenv("USER");
	host = get_host_name();
	dir = get_work_dir();
	if (!user)
		user = "User";
	if (!host)
		host = ft_strdup("Minishell");
	printf("\033[1;32m%s@%s\033[1;0m:\033[1;34m%s\033[1;0m$", user, host, dir);
	free(host);
	free(dir);
	rl_on_new_line();
	return (readline(" "));
}
