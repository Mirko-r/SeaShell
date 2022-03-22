/*
Seashell :A fast and simple UNIX shell in C

input.c : file for input processing

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
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/input.h"
#include "../include/errors.h"

#define GREEN "\x1b[92m"
#define BLUE "\x1b[94m"
#define DEF "\x1B[0m"
#define CYAN "\x1b[96m"
#define RESET_COLOR "\e[m"

struct stat st = {0};


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

/**
 *	Displays the prompt for the shell
 */
char execdir[1000];
char host[1000];
char user[1000];

const char *shellPrompt(){
	char home[1000];
    getcwd(home,1000);
    int flag=0;
    char changehome[1000]="~";
    char **prompt = malloc(sizeof(char)*4000);
    gethostname(host, sizeof(host));
    int i;

    // Checking for the directory to be printed
    // Changing home dir to ~
    if ( strlen(execdir) <= strlen(home) )
        for( i = 0 ; execdir[i]!='\0' ; i++ ){
            if( execdir[i] != home[i] ){
                flag=1;
                break;
            }
        }else
        flag=1;

    if( flag == 0 ){
        int j,k;
        for( j=i , k=1 ; home[j]!='\0' ; j++,k++ )
            changehome[k] = home[j];
        //prompt = BLUE,getenv("LOGNAME"),"@",host,": ",GREEN,changehome;
        sprintf(prompt, "\n%s%s@%s: %s%s>%s ",  BLUE,getenv("LOGNAME"),host,GREEN,changehome,RESET_COLOR);
    }else
     //prompt = BLUE,getenv("LOGNAME"),"@",host,": "GREEN,home;
     sprintf(prompt, "\n%s%s@%s: %s%s>%s ",  BLUE,getenv("LOGNAME"),host,GREEN,changehome,RESET_COLOR);

     return prompt;
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

int strinclude(char *string, char *substring){
    return strstr(string, substring) ? true : false;
}

bool is_an_existing_dir(char *path){
    if(stat(path, &st) == -1){
        return true;
    }else{
        return false;
    }
}
