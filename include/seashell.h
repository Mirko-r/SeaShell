/*
Seashell :A fast and simple UNIX shell in C

seashell.h : here there are all the includes and defines

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
#include <pthread.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include<readline/history.h>
#include <readline/readline.h>
#include <stdbool.h>
#include "../include/command.h"
#include "../include/input.h"
#include "../include/errors.h"
#include "../include/benchmark.h"
#include "../include/history.h"

#define ITERATIONS 10000000 //benchmark
#define VERSION "0.0.5-alpha"

#define GREEN "\x1b[92m"
#define DEF "\x1B[0m"
#define BLUE "\x1b[94m"
#define CYAN "\x1b[96m"
#define RESET_COLOR "\e[m"