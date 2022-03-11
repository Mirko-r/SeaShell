/*
Cshell :A fast and simple UNIX shell in C

main.c : main file

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
#include <readline/readline.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../include/input.h"
#include "../include/errors.h"
#include "../include/command.h"

#define RESET_COLOR "\e[m"

int main() {
    char **command;
    char *input;
    pid_t child_pid;
    int stat_loc;

    while (1) {
        printf(RESET_COLOR);
        input = readline("\nCsh> ");
	    if(input != NULL) { //check if EOF
		    command = get_input(input);
	    }else return 0; //^D to exit

        if (strcmp(command[0], "cd") == 0) {
            cd(command[1]); 
            continue;
        }

        if(strcmp(command[0], "pcd") == 0 || strcmp(command[0], "pwd") == 0){
            pcd();
            continue;
        }
        
        if (strcmp(command[0], "about") == 0){
            about();
            continue;
        }

        if (strcmp(command[0], "exit") == 0){
            return 0;
        }

        if(strcmp(command[0], "clear") == 0){
            function_clear();
            continue;
        }

        child_pid = fork();

        if (child_pid < 0) {
            fork_err();
        }

        if (child_pid == 0) {
            /* Never returns if the call is successful */
            if (execvp(command[0], command) < 0) {
                execvp_err(&command[0]);
            }
        } else {
            waitpid(child_pid, &stat_loc, WUNTRACED);
        }

        free(input);
        free(command);
    }

    return 0;
}
