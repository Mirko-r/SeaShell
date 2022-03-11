#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "../include/command.h"

#define VERSION "0.0.2-alpha"

int cd(char *path) {
    return chdir(path);
}

void function_clear(){
    const char* blank = "\e[1;1H\e[2J";
    write(STDOUT_FILENO,blank,12);
}

// Function to print Current Directory.
void pcd(){
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\nCurrent Dir: %s\n", cwd);
}

void about(){
    // Source - http://ascii.co.uk/art/seashell
    char* descr = "           _.-''|''-._\n        .-'     |     `-.\n      .'\\       |       /`.\n    .'   \\      |      /   `.        Cshell v " VERSION"\n    \\     \\     |     /     /        Made by @Mirko-r\n     `\\    \\    |    /    /'\n       `\\   \\   |   /   /'\n         `\\  \\  |  /  /'\n        _.-`\\ \\ | / /'-._ \n       {_____`\\\\|//'_____}\n               `-'\n\n";

    printf("%s",descr);
}