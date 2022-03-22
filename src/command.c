/*
Seashell :A fast and simple UNIX shell in C

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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "../include/command.h"
#include "../include/input.h"
#include "../include/errors.h"
#include "../include/benchmark.h"

#define VERSION "0.0.5-alpha"

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
    printf("%s\n",cwd);
}

void bench(char *numofthreads){
    int thread = 0;
    if(numofthreads == NULL){
        flops(1);
    }else{
        thread = *numofthreads - '0';
        flops(thread);
    }
}

void mc(char *path){ //mkdir and cd
    mkdir(path, 0700);
    cd(path);
}

void cp(char* file1, char* file2){
    FILE *f1,*f2;
    struct stat t1,t2;
    f1 = fopen(file1,"r");
    if(f1 == NULL){
        perror("+--- Error in cp file1 ");
        return;
    }
    f2 = fopen(file2,"r");// if file exists
    if(f2){
        // file2 exists
        // file1 must be more recently updated
        stat(file1, &t1);
        stat(file2, &t2);
        if(difftime(t1.st_mtime,t2.st_mtime) < 0){
            printf("+--- Error in cp : %s is more recently updated than %s\n",file2,file1);
            fclose(f1);
            fclose(f2);
            return;
        }
    }
    f2 = fopen(file2,"ab+"); // create the file if it doesn't exist
    fclose(f2);

    f2 = fopen(file2,"w+");
    if(f2 == NULL){
        perror("Error in cp file2 ");
        fclose(f1);
        return;
    }
    //if(access(file2,W_OK)!=0 || access(file1,R_OK)!=0 || access(file2,F_OK)!=0)
    if(open(file2,O_WRONLY)<0 || open(file1,O_RDONLY)<0){
        perror("Error in cp access ");
        return;
    }
    char cp;
    while((cp=getc(f1))!=EOF){
        putc(cp,f2);
    }

    fclose(f1);
    fclose(f2);
}


void about(){
    // Source - http://ascii.co.uk/art/seashell
    char* descr = BLUE"           _.-''|''-._\n        .-'     |     `-.\n      .'\\       |       /`.\n    .'   \\      |      /   `.        "RESET_COLOR "Seashell v "VERSION BLUE"\n    \\     \\     |     /     /        "RESET_COLOR "Made by @Mirko-r\n"BLUE"     `\\    \\    |    /    /'\n       `\\   \\   |   /   /'\n         `\\  \\  |  /  /'\n        _.-`\\ \\ | / /'-._ \n       {_____`\\\\|//'_____}\n               `-'\n\n";

    printf("%s",descr);
}
