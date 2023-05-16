#ifndef BUILTINS_H
# define BUILTINS_H


# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
#include <string.h>


typedef struct s_env {
    char *var;
    struct s_env *next;
} t_env;

t_env   *new_env_node(char *var);
t_env   *init_env_list(char **environ);
void    print_env_list(t_env *env_list);
int	ft_ispace(char ch, char c);
int	count_words(char *str, char c);
char	*malloc_word(char *str, char c);
char	**ft_split(char const *s, char c);
void sort_env_list(t_env *env_list);
t_env *search_env_list(t_env *env_list, char *var_name);
void export_env_var(t_env *env_list, char *var);
void export(t_env *env_list, char **vars);
void export_var(t_env **env_list, t_env **exp_list, char *var);

t_env *sorted_env_list(t_env *env_list);
void set_env_var(t_env **env_list, char *var);
int             if_value(char *str);
 void           add_to_export_list(t_env **export_list, char *var);
 void           process_command(t_env **env_list, t_env **export_list, char *line);
 t_env          *copy_env_list(t_env *source_list);
 t_env          *get_last_node(t_env *list);
 int	        ft_strchr(char *s, int c);
 void           unset_var(t_env **env_list, char *var);



#endif