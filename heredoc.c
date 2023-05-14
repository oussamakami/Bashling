#include "get_next_line.h"

#define MAX_LINE_LENGTH 1000

void	here_doc(char *argv)
{
	int		file;
	char	*buf;
    int infile;
	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0);
		if (!strncmp(argv, buf, strlen(argv) ))
			break ;
		// write(file, buf, strlen(buf));
		// write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(file);
	infile = open(".heredoc_tmp", O_RDONLY);
	if (infile < 0)
	{
		unlink(".heredoc_tmp");
		printf("Error heredoc\n");
	}
}

// int main(int ac , char **av)
// {
//     (void)ac;
//     here_doc(av[1]);
//     return 0;
// }
