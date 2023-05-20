#include "builtins.h"

void sorting(t_env *copy, t_env *tmp, t_env *next, t_env *prev)
{
    t_env *result ;
    
    result = NULL;
    while (copy) {
        tmp = copy;
        copy = copy->next;
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
}

t_env *sorted_env_list(t_env *env_list) {
    t_env *copy = NULL;
    t_env *cursor = env_list;
    
    // Create a copy of the original list
    while(cursor) {
        set_env_var(&copy, cursor->var);
        cursor = cursor->next;
    }

    t_env *result = NULL;
    t_env *tmp;
    t_env *next;
    t_env *prev;

    // Sort the copy
    sorting(copy, tmp, next, prev);

    return result;
}
void afficher_export_list(t_env *exp_list)
{
      t_env *sorted_list;
        t_env *tmp; 
        char **env_parts;
        sorted_list = sorted_env_list(exp_list);
        tmp = exp_list;
        while (tmp) {

            env_parts = ft_split(tmp->var, '=');
            if (env_parts[1] ) {
                printf("$ declare -x %s=\"%s\"\n", env_parts[0], env_parts[1]);
            } else {
                if (ft_strchr(tmp->var, '=') == 0) 
                    printf("$ declare -x %s=\"\"\n", env_parts[0]);
                else
                    printf("$ declare -x %s\n", env_parts[0]);
            }
           
            for (int i = 0; env_parts[i]; i++) {
                free(env_parts[i]);
            }
            free(env_parts);
            tmp = tmp->next;
        }
}
int export_modif(char *var,  char **parts, t_env **exp_list, int k)
{
    char *name ;
    char *value ;
    char **variable;
    char **parties;

    name = parts[0];
    value = parts[1] ? parts[1] : "";

    if(ft_strchr(var, '=')== 0 && ft_strchr(var, '+') == 0)
        {
            parties = ft_split2(var, '=');
            if (parties[1])
                concatenate_variable(*exp_list, name, value );
        if (parts[k + 1])
            return 2;    
        return 0;
        }
    variable = ft_split(var, '=');
    if (variable[1])
        update_variable(*exp_list, name, variable[1] );
    return 1;
    
}
void freeing_double_char(char **env_parts, char **parts)
{
     for (int i = 0; env_parts[i]; i++) {
                free(env_parts[i]);
            }
            free(env_parts);
            for (int i = 0; parts[i]; i++) {
                free(parts[i]);
            }
            free(parts);
}
int search_variable(t_env *tmp, char *var, char **parts, int k)
{
        char **env_parts;

        env_parts = ft_split(tmp->var, '=');
        if (!strcmp(env_parts[0], parts[0])) {
           if(ft_strchr(var, '=') == 0 )
            {
                var = remove_quotes(var);
                free(tmp->var);
                tmp->var = strdup(var);
            }
            freeing_double_char(env_parts, parts);
            if (parts[k + 1])
                return 2;
            return 0;
        }
        for (int i = 0; env_parts[i]; i++) {
            free(env_parts[i]);
        }
        free(env_parts);
        return 1;
}

void variable_not_found(t_env **env_list, t_env *prev, char *var, t_env **exp_list )
{
    t_env *temporaire; 
    temporaire = get_last_node(*exp_list);
    
    if (prev) {
       if (var_exists(*exp_list,var ) == 1)
        {
             var = remove_quotes(var);
            temporaire->next = new_env_node(var);
        }
            
        if(ft_strchr(var, '=') == 0 )
           prev->next = new_env_node(var);
    } else {
        var = remove_quotes(var);
        if (var_exists(*exp_list,var ) == 1)
            (*exp_list) = new_env_node(var);
        if(ft_strchr(var, '=') == 0 )
            *env_list = new_env_node(var);
    }
}
int loop_export(t_env **env_list, t_env **exp_list, char **parties, int k)
{
    t_env *tmp;
    char **parts ;
    t_env *prev ;

    tmp = *env_list;
    parts = ft_split(parties[k], '=');
    is_valid_identifier(parts[0]);
    if (export_modif(parties[k], parts, exp_list, k) == 0)
        return 0;
    while (tmp) {
        if (search_variable(tmp, parties[k],parts, k) == 0)
            return 0;
        prev = tmp;
        tmp = tmp->next;
    }
    variable_not_found(env_list, prev, parties[k],exp_list );
    for (int i = 0; parts[i]; i++) {
        free(parts[i]);
    }
    free(parts);
    return 1;
}
void export_var(t_env **env_list, t_env **exp_list, char **parties) {
    
    int k;
    t_env *tmp ;
    
     k = 0;
    if (!parties[1]) {
       
        afficher_export_list(*exp_list);
        return;
    }
    while (parties[++k] != '\0')
    {
        if (loop_export(env_list, exp_list, parties, k) == 0)
            return;
    }
}
int  set_env_var_help(char *name, char *var, char **parts, t_env *tmp)
{
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
            free(parts);
            return 0;
        }
        for (int i = 0; env_parts[i]; i++) {
            free(env_parts[i]);
        }
        free(env_parts);
        return 1;
}
void set_env_var(t_env **env_list, char *var) {
    t_env *tmp = *env_list;
    t_env *prev = NULL;

    char **parts = ft_split(var, '=');
    char *name = parts[0];
    char *value = parts[1] ? parts[1] : "";
    while (tmp) {
       
        if (set_env_var_help(name, var, parts, tmp) == 0)
            return ;
        prev = tmp;
        tmp = tmp->next;
    }
    if (prev) {
        prev->next = new_env_node(var);
    } else {
        *env_list = new_env_node(var);
    }
    for (int i = 0; parts[i]; i++) {
        free(parts[i]);
    }
    free(parts);
}
