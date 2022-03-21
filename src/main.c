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
#include "../include/history.h"
#include "../CLI-Autocomplete/include/autocomplete.h"

#define RESET_COLOR "\e[m"
#define GREEN "\x1b[92m"
#define BLUE "\x1b[94m"

int main() {
    char **command;
    char *input;
    pid_t child_pid;
    int stat_loc;
    
    initalize_history();
    Tree* rules = tree_create("../../../../example.config");

    while (1) {
        char* str = input(rules);
        printf("\n%s\n", str);

        // Stop listening if user need
        if (strcmp(str, "") == 0) {
            free(str);
            break;
        }

        // Free user input string
        free(str);
	


        printf(RESET_COLOR);
        input = readline("\nCsh> ");

	if(input != NULL) { //check if EOF
		command = get_input(input);
        add_to_history(input);
	}else return 0; //^D to exit

        //Which command?

        if (strcmp(command[0], "cd") == 0) {
            cd(command[1]); 
            continue;
        }

        if (strcmp(command[0], "mc") == 0) {
            mc(command[1]); 
            continue;
        }

        if(strcmp(command[0], "pcd") == 0 || strcmp(command[0], "pwd") == 0){
            printf("\n%sCurrent Dir: %s",BLUE, GREEN);
            pcd();
            continue;
        }

        if(strcmp(command[0], "bench") == 0){
            bench(command[1]);
            continue;
        }
        
        if (strcmp(command[0], "about") == 0){
            about();
            continue;
        }

        if(strcmp(command[0], "history") == 0){
            print_history();
            continue;
        }

        if (strcmp(command[0], "exit") == 0){
            return 0;
        }

        if(strcmp(command[0], "clear") == 0){
            function_clear();
            continue;
        }

        //Execute the command

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
    tree_free(rules);

    return 0;
}
