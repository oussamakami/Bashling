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

	buff = NULL;
	fd = open("/etc/hostname", O_RDONLY);
	if (fd > 0)
	{
		buff = ft_calloc(1024, 1);
		read(fd, buff, 1024);
	}
	close(fd);
	if (buff && buff[ft_strlen(buff)-1] == '\n')
		buff[ft_strlen(buff) - 1] = '\0';
	return (buff);
}

char	*extract_branch(char *buff)
{
	int		i;
	char	**temp;
	char	*branch;

	i = -1;
	temp = ft_split(buff, '/');
	free(buff);
	while (temp[++i])
		branch = temp[i];
	branch[ft_strlen(branch)-1] = '\0';
	branch = replace_all_words(" (b)", "b", branch, 0);
	free2d((void **)temp);
	return (branch);
}

char	*get_branch_name(void)
{
	int		fd;
	char	*buff;

	buff = NULL;
	fd = open(".git/HEAD", O_RDONLY);
	if (fd > 0)
	{
		buff = ft_calloc(1024, 1);
		read(fd, buff, 1024);
	}
	close(fd);
	if (buff)
		return (extract_branch(buff));
	return (NULL);
}

static char	*generate_prompt(void)
{
	char	*host;
	char	*dir;
	char	*branch;
	char	*prompt;

	host = get_host_name();
	dir = get_work_dir();
	branch = get_branch_name();
	prompt = ft_strdup(
			"\033[1;32mUSER@Minishell\033[1;0m:\033[1;34mD\033[1;35mB\033[1;0m$ ");
	if (getenv("USER"))
		prompt = replace_all_words(prompt, "USER", getenv("USER"), 1);
	if (host)
		prompt = replace_all_words(prompt, "Minishell", host, 1);
	free(host);
	prompt = replace_all_words(prompt, "D", dir, 1);
	free(dir);
	prompt = replace_all_words(prompt, "B", branch, 1);
	free(branch);
	return (prompt);
}

char	*prompt(void)
{
	char	*input;

	input = readline(generate_prompt());
	return (input);
}
