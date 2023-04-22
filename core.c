#include "core.h"

int main() {
    char* input;
    while (1) {
        input = readline("minishell$ ");
        free(input);
    }
    return 0;
}