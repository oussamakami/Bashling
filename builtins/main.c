#include "builtins.h"


int main(int ac, char **av, char **environ) {
    // Initialize the environment list
    int k = 0;
  
    // The environment list
    t_env *env_list = NULL;
    t_env *export_list = NULL;
    env_list = init_env_list(environ);
    export_list = init_env_list(environ);
    char command[256];
    while (1) {
        printf("> ");
        fgets(command, 256, stdin);
         
        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        // Split the command and arguments
        char **parts = ft_split2(command, ' ');
        // count the arguments
        int count = 0;
        for(char **tmp = parts; *tmp; tmp++) {
            count++;
        }
        if (!parts || !parts[0]) {
            // Invalid input, handle error
            printf("Invalid input\n");
            continue;
        }

        if (!strcmp(parts[0], "exit")) {
            // Exit the shell
            break;
        } else if (!strcmp(parts[0], "env")) {
            // Print the environment variables
            print_env_list(env_list);
        } else if (!strcmp(parts[0], "export")) {
            // Add or update an environment variable
            // if (parts[1]) {
               
            export_var(&env_list, &export_list, parts);
            // } else {
            //     printf("Usage: export VAR=VALUE\n");
            // }
        }else if (!strcmp(parts[0], "unset"))
        {
            unset_var(&env_list, parts[1]);
            unset_var(&export_list, parts[1]);
        
        }else if (!strcmp(parts[0], "pwd"))
        {
            pwd();
        
        } else if (!strcmp(parts[0], "cd"))
        {
            cd(&env_list , parts[1]); 

        }else if (!strcmp(parts[0], "echo"))
        {
           echo(count, parts);    
        
        
        }else {
            printf("Unknown command: %s\n", parts[0]);
        }

        // Free the split parts of command
        for (int i = 0; parts[i]; i++) {
            free(parts[i]);
        }
        free(parts);
    }

    // Cleanup the environment list
    t_env *tmp;
    while (env_list) {
        tmp = env_list;
        env_list = env_list->next;
        free(tmp->var);
        free(tmp);
    }

    return 0;
}


