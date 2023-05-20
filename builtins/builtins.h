#ifndef BUILTINS_H
# define BUILTINS_H


# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>


typedef struct s_env {
    char *var;
    struct s_env *next;
} t_env;

t_env   *new_env_node(char *var);
t_env   *init_env_list(char **environ);
void    print_env_list(t_env *env_list);
char	**ft_split2(char const *s, char c);
int	ft_ispace(char ch, char c);
int	count_words(char *str, char c);
char	*malloc_word(char *str, char c);
char    **ft_split(char *str, char sep);
void sort_env_list(t_env *env_list);
t_env *search_env_list(t_env *env_list, char *var_name);
void export_env_var(t_env *env_list, char *var);
void export(t_env *env_list, char **vars);
void export_var(t_env **env_list, t_env **exp_list, char **parties);

t_env        *sorted_env_list(t_env *env_list);
void         set_env_var(t_env **env_list, char *var);
int          if_value(char *str);
 void        add_to_export_list(t_env **export_list, char *var);
 void        process_command(t_env **env_list, t_env **export_list, char *line);
 t_env      *copy_env_list(t_env *source_list);
 t_env      *get_last_node(t_env *list);
 int	    ft_strchr(char *s, int c);
 void       unset_var(t_env **env_list, char *var);
 void       pwd();
 void       echo(int argc, char **argv);
 void       print_export_list(t_env *export_list);
 void       update_variable(t_env *env_list, char *var_name, char *new_var);
int         var_exists(t_env *env_list, char *var_name);
char        *remove_quotes(char *str);
void        concatenate_variable(t_env *env_list, char *var_name, char *new_var);
void        remove_char(char *str, char c);
int         is_valid_identifier(char *str);
void        set_env_var2(const char* var_name, const char* new_value);
int         cd_command(char* path);
void        cd(t_env **env_list, char *path);
void        parse_input(char* input, char** argv, int* argc);
void        afficher_export_list(t_env *exp_list);
int         export_modif(char *var,  char **parts, t_env **exp_list, int k);
int         search_variable(t_env *tmp, char *var, char **parts, int k);
void        variable_not_found(t_env **env_list, t_env *prev, char *var, t_env **exp_list );
int         loop_export(t_env **env_list, t_env **exp_list, char **parties, int k);
void        freeing_double_char(char **env_parts, char **parts);
int        set_env_var_help(char *name, char *var, char **parts, t_env *tmp);
void       sorting(t_env *copy, t_env *tmp, t_env *next, t_env *prev);
void       cd_utils(char *old_dir, char *new_dir, size_t size, t_env **env_list);
int         unset_var_utils(char *var, t_env *tmp, t_env *prev , t_env **env_list);
int       freeing(char **env_parts);



#endif