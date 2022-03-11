#ifndef __ERRORS_H
#define __ERRORS_H

void fork_err();
void execvp_err(char **command);
void malloc_err();
void cd_err(char **command);
void ls_err();

#endif