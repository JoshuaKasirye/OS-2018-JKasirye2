
#include <stdio.h> //std C library
#include <stdlib.h> // To enable use of exit()
#include <string.h> // string lib
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int wish_loop();
int wish_exit();
char **read_wish_stdin();
int exec_cmd();
int builtIn_cd();

//Main functions for the wish.c
int main(int argc, char *argv[]){
    if (argc == 1){
        wish_loop();
    }
    else if (argc == 2){
        printf("USing the bash \n");
    }
    else if(argc > 2 ){
        printf("Please The maximum arguments are two\n");
        exit(1);
    }

    return 1;
    }


//wish loop
int wish_loop(){
    char **task;
    while(1) {
        printf("wish> ");
        task = read_wish_stdin();
	exec_cmd(task);
	}
}


//Reading user input
char **read_wish_stdin(){
    char **array = malloc(64 *sizeof(char));
    char *token;
    char name[60];


    fgets(name, 100, stdin);
    token = strtok(name," \n");

    int i = 0;
    while (token != NULL){
        array[i] = token;
       	token = strtok (NULL," \n");
        i = i + 1;
        }
    array[i] = NULL;
    return array;
}


//Execution command
int exec_cmd(char **array){
    if (strcmp(array[0],"exit") == 0){
	printf("passed exit");
        wish_exit();
    }

 
    //Calling the cd builtIn first
   if (strcmp(array[0], "cd")==0){
	 builtIn_cd(array);
	 return 1;
   }
    
    char str1[10] = "/bin/";
    char str2[10] = "/usr/bin/";

    //concatenating the paths
    char *path1 = malloc(strlen(str1) + strlen(array[0]) + 1);
    strcat(path1,str1);
    strcat(path1,array[0]);
    char *path2 = malloc(strlen(str2) + strlen(array[0]) + 1);
    strcat(path2,str2);
    strcat(path2,array[0]);

    pid_t wait_pid;
    pid_t pid;
    int status;
    if (access(path1, F_OK)==0){
        pid = fork();
        if (pid == 0){
            array[0] = path1;
            execv(array[0],array);
            printf("The exec didn't work\n ");
            }
	pid = wait(NULL);	
     }
     else if (access(path2, F_OK)==0){
        pid = fork();
        if (pid == 0){
            array[0] = path2;
            execv(array[0],array);
            printf("The exec didn't work\n ");
            }
	pid = wait(NULL);
     }

     else {
         printf("Unknown Command ...\n");
	 pid = wait(NULL);
    	} 

    return 1;
}

//Wish Exit function
int wish_exit(){
    exit(0);
}


//BuiltIn cd command
int builtIn_cd(char **array){
    if ( array[1] != NULL){
        char *path = array[1];
        if (chdir(path) != 0){
            printf("The path does not exist ..\n");
        }
    }
    return 1;
}




