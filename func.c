#include "lmvs.h"

int interative(){
    char **args = malloc(40);
    for(int i = 0; i < 40; i++ ){
        args[i] = malloc(MAX_LINE*sizeof(char));
    }
    char *command = malloc(100*sizeof(char));
    int should_run = 1;	
	int style = 0;
    int count; 
    

    while (should_run){
        
        
		if (style == 0){ 
			createSequential();
            scanf("%[^\n]%*c", command);
            style = verifyInput(&should_run, command, style);
            if(strcmp(command,"style sequential") && (strcmp(command,"exit")) && (strcmp(command,"style parallel"))){
                count = countCommand(command);
                args = splitInput(command, args);
                getSplited(args,count);
            }
            else if(!strcmp(command,"exit")){
                exit(0);
            }
		}
        else if (style == 1){
			createParallel();
            scanf("%[^\n]%*c", command);
            style = verifyInput(&should_run, command, style);
            if(strcmp(command,"style sequential") && (strcmp(command,"exit")) && (strcmp(command,"style parallel"))){
                count = countCommand(command);
                args = splitInput(command, args);
                getSplitedForParallel(args, count);
            }
            else if(!strcmp(command,"exit")){
                exit(0);
            }
		}
    }
	return 0;
}

int createSequential(){
    printf("lmvs seq> ");
    fflush(stdout);
}

int createParallel(){
    printf("lmvs par> ");
	fflush(stdout);
}

int verifyInput(int *exit, char *args, int style){
    if(!strcmp(args,"style sequential")){
        return 0;
    }else if(!strcmp(args,"style parallel")){
        return 1; 
    }else if(!strcmp(args,"exit")){
        //*exit = 0;
        kill(0, 9);
    }else{
        return style;
    }
}

char **splitInput(char *command, char **args){

    char *token = strtok(command, ";");
    int i = 0;

    while(token != NULL ){
        args[i] = token;    
        token = strtok(NULL, ";");
        i++;
    }
    return args;
}

void executeSequential(char **argsSplited){
    pid_t pid;
    pid = fork();

    if(pid > 0){
        wait(NULL);
    }
    else if (pid == 0){
        execvp(argsSplited[0], argsSplited);
    }
    else{
        fprintf(stderr, "Fork Failed!");
    }
}

void executeParallel(char **argsSplited, int count){

    for(int i = 0; i < count; i++){

        pid_t pid;
        pid = fork();

        if (pid == 0){
            execvp(argsSplited[i], argsSplited);
            exit(0);
        }
    }
    for(int i = 0; i < count; i++){
        wait(NULL);
    }
}

char **splitExecvp(char *command, char **argsSplited){
    
    char *token = strtok(command, " ");
    int i = 0;

    while(token != NULL){
        argsSplited[i] = token;
        token = strtok(NULL, " ");
        i++; 
    }
    argsSplited[i] = NULL;
    return argsSplited;
}

int getSplited(char **args, int count){
    int i = 0;

    for (i = 0; i < count ; i++ ){
        char **argsSplited = malloc(80);
        for(int i = 0; i < 40; i++ ){
            argsSplited[i] = malloc(MAX_LINE*sizeof(char));
        }
        char *argument = args[i];
        argsSplited = splitExecvp(argument, argsSplited);
        executeSequential(argsSplited);
    }
    return 0;
}

int getSplitedForParallel(char **args, int count){
    int i = 0;

    for (i = 0; i < count ; i++ ){
        char **argsSplited = malloc(80);
        for(int i = 0; i < 40; i++ ){
            argsSplited[i] = malloc(MAX_LINE*sizeof(char));
        }
        char *argument = args[i];
        argsSplited = splitExecvp(argument, argsSplited);
        executeParallel(argsSplited, count);

    }
    return 0;
}

int countCommand(char *command ){ 
    int count = 0;
    int commandLength = strlen(command);
    int i = 0;

    while(i <= commandLength){
        if(command[i] == ';'){
            count++;
        }
        i++;
    }
    count = count + 1;
    return count;
}

void batch(char **argv){
    FILE *file;
    file = fopen(argv[1], "a+");

    if((file=fopen(argv[1], "a+")) == NULL){ 
        fprintf(stderr,"file failed\n");
        exit(1);
    } 
    fclose(file);

    char *line = malloc(MAX_LINE*sizeof(char));
    int i;
    size_t len = 0;
    char **args = malloc(40);
    for(int i = 0; i < 40; i++ ){
        args[i] = malloc(MAX_LINE*sizeof(char));
    }
    int count = 0;
    
    file = fopen(argv[1], "a+");

    while(getline(&line, &len, file) != -1){
	    line[strlen(line)-1]='\0';
        count = countCommand(line);
        args = splitInput(line, args);
        getSplited(args,count);
        
    }
    fclose(file);
}
