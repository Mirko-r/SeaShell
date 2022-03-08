#include <stdlib.h>
#include <string.h>
#include "../include/errors.h"

void fork_err(){
    perror("Fork failed");
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
    perror("malloc failed");
    exit(1);
}