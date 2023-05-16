#include "builtins.h"

void unset_var(t_env **env_list, char *var) {
    if (!var) {
        // If no variable is provided, print error and return
        printf("unset: not enough arguments\n");
        return;
    }

    t_env *tmp = *env_list;
    t_env *prev = NULL;

    // Search for the variable in the list
    while (tmp) {
        char **env_parts = ft_split(tmp->var, '=');
        if (!strcmp(env_parts[0], var)) {
            // Variable found, remove it
            if (prev) {
                prev->next = tmp->next;
            } else {
                // If removing first element in the list
                *env_list = tmp->next;
            }
            
            // Remember to free the split parts
            for (int i = 0; env_parts[i]; i++) {
                free(env_parts[i]);
            }
            free(env_parts);
            free(tmp->var);
            free(tmp);
            return;
        }
        for (int i = 0; env_parts[i]; i++) {
            free(env_parts[i]);
        }
        free(env_parts);
        prev = tmp;
        tmp = tmp->next;
    }

    // Variable not found, print error and return
    printf("unset: %s: not found\n", var);
}
