#include "modules.h"

void	free2d(void **ptr)
{
	int	index;

	index = 0;
	while (ptr && ptr[index])
		free(ptr[index++]);
	free(ptr);
}
