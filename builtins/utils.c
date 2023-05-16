#include "builtins.h"


int if_value(char *str)
{
    int i = 0;
  
    while(str[i] != '\0')
    {
        if (str[i] == '=')
            return 1;
        i++;
    }
    return 0;
}

t_env *copy_env_list(t_env *source_list) {
    if (source_list == NULL) {
        return NULL;
    }

    t_env *new_list = NULL;
    t_env *tmp = NULL;

    while (source_list) {
        t_env *new_node = new_env_node(source_list->var);
        if (!new_node) {
            // Handle allocation failure, e.g., by freeing already copied nodes
            return NULL;
        }

        if (new_list == NULL) {
            new_list = new_node;
            tmp = new_list;
        } else {
            tmp->next = new_node;
            tmp = tmp->next;
        }

        source_list = source_list->next;
    }

    return new_list;

}
int	ft_strchr( char *s, int c)
{
	char	*chr;

	chr = (char *)s;
	while (*chr != c)
	{
		if (!*chr)
			return (1);
		chr++;
	}
	return (0);
}

t_env *get_last_node(t_env *list) {
    if (list == NULL) {
        return NULL;
    }

    t_env *tmp = list;

    while (tmp->next) {
        tmp = tmp->next;
    }

    return tmp;
}

