/*
Cshell :A fast and simple UNIX shell in C

command.c : file for builtin commands

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "../include/command.h"

#define VERSION "0.0.3-alpha"

#define GREEN "\x1b[92m"
#define BLUE "\x1b[94m"
#define RESET_COLOR "\e[m"

void cd(char *path) {
    if (path == NULL){
        chdir (getenv ("HOME"));
    }else if(chdir(path) == -1){
            cd_err(path);     
    }
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
