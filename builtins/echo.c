#include "builtins.h"



void echo(int argc, char **argv) {
  int i = 1;
    int print_newline = 1;

    while(i < argc) {
        if(argv[i][0] == '-' && argv[i][1] == 'n') {
            print_newline = 0;
            i++;
            while(i < argc && argv[i][0] == '-' && strstr(argv[i], "n")) {
                i++;
            }
        }
        argv[i] = remove_quotes(argv[i]);
        printf("%s", argv[i]);
        if(i < argc - 1) {
            printf(" ");
        }

        i++;
    }

    if(print_newline) {
        printf("\n");
    }
}
