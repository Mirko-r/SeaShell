/*
Seashell :A fast and simple UNIX shell in C

errors.c : file for errors processing

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "../include/seashell.h"

void fork_err(){
    perror(CYAN "+--- Error in fork");
    exit(1);
}

void execvp_err(char **command){
    perror(command[0]);
    exit(1);
}

void cd_err(char **command){
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

void unexisting_dir(){
    perror(CYAN "+--- Directory does not exist");
    return;
}