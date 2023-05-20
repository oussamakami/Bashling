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
    t_env *new_list;
    t_env *tmp ;

    if (source_list == NULL) 
        return NULL;
    new_list = NULL;
    tmp = NULL;
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

int freeing(char **env_parts)
{
    int i;

    i = 0;
      while (env_parts[i] != '\0') {
                free(env_parts[i]);
                i++;
            }
        free(env_parts);
        return 0;
}

void update_variable(t_env *env_list, char *var_name, char *new_var) {
    t_env *tmp;
    char **env_parts ;
    int i;

    i = -1;
    tmp = env_list;
    while (tmp != NULL) {
        env_parts = ft_split(tmp->var, '=');
        if (strcmp(env_parts[0], var_name) == 0) {
            free(tmp->var);
            tmp->var = malloc(strlen(var_name) + strlen(new_var) + 2); // +2 for the '=' and '\0'
            strcpy(tmp->var, var_name);
            strcat(tmp->var, "=");
            strcat(tmp->var, new_var);
            if (freeing(env_parts) == 0)
                return;
        }
        while(env_parts[i] != '\0')
            free(env_parts[i]);
        free(env_parts);
        tmp = tmp->next;
    }
}
void concatenate_variable(t_env *env_list, char *var_name, char *new_var) {
    t_env *tmp = env_list;

    while (tmp != NULL) {
        char **env_parts = ft_split(tmp->var, '=');
        if (strcmp(env_parts[0], var_name) == 0) {
            strcat(tmp->var, new_var);
            for (int i = 0; env_parts[i]; i++) {
                free(env_parts[i]);
            }
            free(env_parts);
            return;
        }
        for (int i = 0; env_parts[i]; i++) {
            free(env_parts[i]);
        }
        free(env_parts);
        tmp = tmp->next;
    }
}

int var_exists(t_env *env_list, char *var_name) {
    t_env *tmp = env_list;

    while (tmp) {
        if (!strcmp(tmp->var, var_name)) {
              return 0;
            }
        tmp = tmp->next;
    }
    // Variable not found
    return 1;
}

char *remove_quotes(char *str) {
    char *copy = strdup(str);
    if (!copy) {
        return NULL; // Handle allocation failure
    }

    int i, j = 0;
    for (i = 0; copy[i] != '\0'; i++) {
        if (copy[i] != '\"' && copy[i] != '\'') {
            copy[j++] = copy[i];
        }
    }
    copy[j] = '\0';
    return copy;
}

void remove_char(char *str, char c) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
        pw += (*pw != c);
    }
    *pw = '\0';
}




int is_valid_identifier(char *str)
{
    // First character should be alphabet or underscore
    if (!isalpha(str[0]) && str[0] != '_')
    {
        printf("Error: Identifier must start with an alphabet or underscore.\n");
        return (0);
    }
    // The rest can be alphanumeric or underscore
    for (int i = 1; str[i]; i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            printf("Error: Identifier can only contain alphabets, numbers, or underscores.\n");
            return (0);
        }
    }
    return (1);
}
