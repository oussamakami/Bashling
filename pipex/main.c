#include "mypipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_bipex	pipex;
	pipex.pid1 = 0;
	
	//  pipexx(argc, argv, envp, &pipex);
	pipexx_without_red(argc, argv, envp, &pipex);

	return (0);
}
