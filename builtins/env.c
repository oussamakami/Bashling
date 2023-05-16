#include "builtins.h"

t_env *new_env_node(char *var) {
    t_env *new_node = malloc(sizeof(t_env));
    if (!new_node) {
        return NULL;
    }
    new_node->var = strdup(var);
    new_node->next = NULL;
    return new_node;
}

t_env *init_env_list(char **environ) {
    t_env *env_list = NULL;
    t_env *tmp;

    int i = 0;
    while (environ[i]) {
        if (!env_list) {
            env_list = new_env_node(environ[i]);
            tmp = env_list;
        } else {
            tmp->next = new_env_node(environ[i]);
            tmp = tmp->next;
        }
        i++;
    }
    return env_list;
}

void print_env_list(t_env *env_list) {
    t_env *tmp = env_list;
    while (tmp) {
        printf("%s\n", tmp->var);
        tmp = tmp->next;
    }
}











