/*
Cshell :A fast and simple UNIX shell in C

input.h : input.c header file

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef __INPUT_H
#define __INPUT_H
#include <stdbool.h>

char **get_input(char *input);
void shellPrompt();
// Returns 1 (true) if the string includes the substring or else  returns 0 (false)
int strinclude(char *string, char *substring);
//chack if a directory exist
bool is_an_existing_dir(char *path);

#endif