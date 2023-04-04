#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


#define MAX_LINE 80

int interative();
int createSequential();
int createParallel();
int verifyInput(int *exit, char *args, int style);
char **splitInput(char *command, char **args);
char **splitExecvp(char *command, char **argsSplited);
int getSplited(char **args, int count);
void executeSequential(char **argsSplited);
int countCommand(char *command);
void batch(char **argv);
void executeParallel(char **argsSplited, int count);
int getSplitedForParallel(char **args, int count);
