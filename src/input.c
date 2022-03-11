#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "../include/input.h"
#include "../include/errors.h"

#define GREEN "\x1b[92m"
#define BLUE "\x1b[94m"
#define DEF "\x1B[0m"
#define CYAN "\x1b[96m"
#define VERSION "0.0.2-alpha"

char **get_input(char *input) {
    char **command = malloc(8 * sizeof(char *));
    if (command == NULL) {
        malloc_err();
    }
    char *separator = " ";
    char *parsed;
    int index = 0;

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}

int cd(char *path) {

    return chdir(path);
    
}

void function_clear(){
    const char* blank = "\e[1;1H\e[2J";
    write(STDOUT_FILENO,blank,12);
}

void about(){
    // Source - http://ascii.co.uk/art/seashell
    char* descr = "           _.-''|''-._\n        .-'     |     `-.\n      .'\\       |       /`.\n    .'   \\      |      /   `.        Cshell v " VERSION"\n    \\     \\     |     /     /        Made by @Mirko-r\n     `\\    \\    |    /    /'\n       `\\   \\   |   /   /'\n         `\\  \\  |  /  /'\n        _.-`\\ \\ | / /'-._ \n       {_____`\\\\|//'_____}\n               `-'\n\n";

    printf("%s",descr);
}
/* Just a fancy name printing function*/
void nameFile(struct dirent* name,char* followup){
    if(name->d_type == DT_REG)          // regular file
    {
        printf("%s%s%s",BLUE, name->d_name, followup);
    }
    else if(name->d_type == DT_DIR)    // a directory
    {
        printf("%s%s/%s",GREEN, name->d_name, followup);
    }
    else                              // unknown file types
    {
        printf("%s%s%s",CYAN, name->d_name, followup);
    }
}