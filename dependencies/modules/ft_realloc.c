# include "modules.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*result;

	result = ft_calloc(1, size);
	ft_memcpy(result, ptr, size);
	free(ptr);
	return (result);
}