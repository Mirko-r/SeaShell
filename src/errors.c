#include <stdlib.h>
#include <string.h>
#include "../include/errors.h"

#define CYAN "\x1b[96m"

void fork_err(){
    perror(CYAN "+--- Error in fork");
    exit(1);
}

void execvp_err(char **command){
    perror(command[0]);
    exit(1);
}

void cd_err(char *command){
    perror(command[1]);
}

void malloc_err(){
    perror(CYAN "+--- Error in malloc");
    exit(1);
}

void ls_err(){
    printf("\033[0;31mError: Invalid or Unaccessible Directory\033[0m\n");
    perror(CYAN "ls: ");
    return;
}