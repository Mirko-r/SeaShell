#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "../include/command.h"

#define VERSION "0.0.2-alpha"
#define GREEN "\x1b[92m"
#define BLUE "\x1b[94m"
#define RESET_COLOR "\e[m"

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
    printf("\n%sCurrent Dir: %s%s\n",BLUE, GREEN, cwd);
}

void about(){
    // Source - http://ascii.co.uk/art/seashell
    char* descr = BLUE"           _.-''|''-._\n        .-'     |     `-.\n      .'\\       |       /`.\n    .'   \\      |      /   `.        "RESET_COLOR "Cshell v "VERSION BLUE"\n    \\     \\     |     /     /        "RESET_COLOR "Made by @Mirko-r\n"BLUE"     `\\    \\    |    /    /'\n       `\\   \\   |   /   /'\n         `\\  \\  |  /  /'\n        _.-`\\ \\ | / /'-._ \n       {_____`\\\\|//'_____}\n               `-'\n\n";

    printf("%s",descr);
}