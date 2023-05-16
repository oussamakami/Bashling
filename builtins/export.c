#include "builtins.h"


t_env *sorted_env_list(t_env *env_list) {
    t_env *result = NULL;
    t_env *tmp;
    t_env *next;
    t_env *prev;

    while (env_list) {
        tmp = env_list;
        env_list = env_list->next;

        if (!result || strcmp(tmp->var, result->var) < 0) {
            tmp->next = result;
            result = tmp;
        } else {
            next = result;
            while (next) {
                prev = next;
                next = next->next;
                if (!next || strcmp(tmp->var, next->var) < 0) {
                    prev->next = tmp;
                    tmp->next = next;
                    break;
                }
            }
        }
    }

    return result;
}


void export_var(t_env **env_list, t_env **exp_list, char *var) {
    
    // If no variable is provided, print all variables in sorted order
    
    if (!var) {
        t_env *sorted_list = sorted_env_list(*exp_list);
        t_env *tmp = sorted_list;
        while (tmp) {

            char **env_parts = ft_split(tmp->var, '=');
            if (env_parts[1]) {
                printf("$ declare -x %s=\"%s\"\n", env_parts[0], env_parts[1]);
            } else {
                printf("$ declare -x %s\n", env_parts[0]);
            }
            for (int i = 0; env_parts[i]; i++) {
                free(env_parts[i]);
            }
            free(env_parts);
            tmp = tmp->next;
        }
        return;
    }
    
    t_env *tmp = *env_list;
    t_env *temporaire = *exp_list;
    t_env *prec = NULL;
    t_env *prev = NULL;

    // Split the variable into name and value
    char **parts = ft_split(var, '=');
    if (!parts || !parts[0]) {
        // Invalid input, handle error
        printf("Invalid input\n");
        return;
    }

    char *name = parts[0];
    char *value = parts[1] ? parts[1] : "";

    // If the variable doesn't have a value, return
    // if (!value || strcmp(value, "") == 0) {
    //     for (int i = 0; parts[i]; i++) {
    //         free(parts[i]);
    //     }
    //     free(parts);
    //     return;
    // }

    // Search for the variable in the list
    while (tmp) {
       
        char **env_parts = ft_split(tmp->var, '=');
        if (!strcmp(env_parts[0], name)) {
            // Variable found, update value
            free(tmp->var);
            tmp->var = strdup(var);
            // Remember to free the split parts
            for (int i = 0; env_parts[i]; i++) {
                free(env_parts[i]);
            }
            free(env_parts);
            // Also free the split parts of input var
            for (int i = 0; parts[i]; i++) {
                free(parts[i]);
            }
            *exp_list = *env_list;
            free(parts);
            
            return;
        }
        for (int i = 0; env_parts[i]; i++) {
            free(env_parts[i]);
        }
        free(env_parts);
        prev = tmp;
        tmp = tmp->next;
    }
    //    t_env *temporaire = copy_env_list(*env_list);
    temporaire = get_last_node(*exp_list);
    
    // Variable not found, add to the end of the list
    if (prev) {
        temporaire->next = new_env_node(var);
        if(ft_strchr(var, '=') == 0 )
            prev->next = new_env_node(var);
    } else {
        // If list was empty
        (*exp_list) = new_env_node(var);
        if(ft_strchr(var, '=') == 0 )
            *env_list = new_env_node(var);
        
    }

    // Free the split parts of input var
    for (int i = 0; parts[i]; i++) {
        free(parts[i]);
    }
    free(parts);

 }
