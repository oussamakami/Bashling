#include "builtins.h"

// Function to update environment variable
// void set_env_var2(const char* var_name, const char* new_value) {
//     setenv(var_name, new_value, 1);
// }

// Function to change directory and update environment variables

void cd_utils(char *old_dir, char *new_dir, size_t size, t_env **env_list)
{
    
    char var[PATH_MAX + 10];  // +10 for "OLDPWD=", "PWD=", and '\0'
    
    // Get the new current directory
    if (getcwd(new_dir, size) == NULL) {
        perror("getcwd() error");
        return;
    }

    // Update OLDPWD and PWD
    

    // Create and set OLDPWD
    strcpy(var, "OLDPWD=");
    strcat(var, old_dir);
    set_env_var(env_list, var);

    // Create and set PWD
    strcpy(var, "PWD=");
    strcat(var, new_dir);
    set_env_var(env_list, var);
}
void cd(t_env **env_list, char *path) {
    char old_dir[PATH_MAX];
    char new_dir[PATH_MAX];

    // Save the current directory
    if (getcwd(old_dir, sizeof(old_dir)) == NULL) {
        perror("getcwd() error");
        return;
    }

    // If no path is given, change to the HOME directory
    if (!path) {
        path = getenv("HOME");
        if (!path) {
            printf("cd: HOME not set\n");
            return;
        }
    }

    // Change directory
    if (chdir(path) != 0) {
        perror("cd");
        return;
    }
    cd_utils(old_dir, new_dir,sizeof(new_dir), env_list);
}
