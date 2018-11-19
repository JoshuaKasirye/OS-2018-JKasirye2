/*
Operating Systems
Project 2
Creating a bash Shell
By: Joshua Kasirye
*/
//Including all necessary libraries
#include <stdio.h> //std C library
#include <stdlib.h> // To enable use of exit()
#include <string.h> // string lib
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

//Creating the pro-log
int wish_loop();
int wish_exit();
int read_wish_stdin();
int exec_cmd();
int builtIn_cd();
volatile int item = 0;
char *filename;
char **implement_path();

//Main functions for the wish.c
int main(int argc, char *argv[]){
    if (argc == 1){
        wish_loop();
    }
    else if (argc == 2){
        printf("Using the bash \n");
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
        read_wish_stdin();
        }
}


//Reading user input
int read_wish_stdin(){
    char *token1;
    char **token_array = malloc(64 *sizeof(char));
    char name[60];
    fgets(name, 100, stdin);
    token1 = strtok(name,"&\n");

    int count_val = 0;
    int i = 0;
    while (token1 != NULL){ //token for &
        token_array[i] = token1;
        count_val = count_val+1;
        i = i+1;
        token1 = strtok (NULL,"&\n");

    }
   for (int i = 0; i<count_val; i++){
        char **array = malloc(64 *sizeof(char));
        char *token ;
        token = strtok(token_array[i]," \n");
        int i = 0;
        volatile int index = 0;
        while (token != NULL){ //token for space
            if (strcmp(token,">") == 0){
                item = 1;
                index = i;
                array[i] = NULL;
                }
            else{
                array[i] = token;
            }
            token = strtok (NULL," \n");
            i = i + 1;
            }
        array[i] = NULL;
        if (item == 1 && array[index + 1] != NULL && array[index + 1] != " " ){
            filename = array[index+1];
        }
        exec_cmd(array);
   }

    return 1;
}



//Execution command
int exec_cmd(char **array){
    char **path_lst_new;
    if (strcmp(array[0],"exit") == 0){
        wish_exit();
    }
    //Calling the cd builtIn first
   if (strcmp(array[0], "cd")==0){
            builtIn_cd(array);
        }

   if (strcmp(array[0], "path")==0){
       path_lst_new = implement_path(array);
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

    if (access(path1, F_OK)==0){
        pid = fork();
        if (pid == 0){
            array[0] = path1;
            if (item == 1 && filename != NULL && filename != ""){
                FILE *out = fopen(filename,"w+"); //O_RDWR|O_CREAT,S_IRUSR |S_IWUSR);
                FILE *error = fopen(filename,"w+");
                dup2(fileno(out),fileno(stdout));
                dup2(fileno(error),fileno(stderr));
                fclose(out);
                execv(array[0],array);
                printf("The exec didn't work\n ");
            }
            else{
                execv(array[0],array);
                printf("The exec didn't work\n ");
            }

            }
	pid = wait(NULL);
     }
     else if (access(path2, F_OK)==0){
        pid = fork();
        if (pid == 0){
            array[0] = path2;
            if (item == 1 && filename != NULL && filename != ""){
                FILE *out = fopen(filename,"w+"); //O_RDWR|O_CREAT,S_IRUSR |S_IWUSR);
                dup2(fileno(out),fileno(stdout));
                dup2(fileno(out),fileno(stderr));
                fclose(out);
                execv(array[0],array);
                printf("The exec didn't work\n ");
            }
            else{
                execv(array[0],array);
                printf("The exec didn't work\n ");
            }

            }
	pid = wait(NULL);
     }

     else {
         printf("Unknown Command ...\n");
	 pid = wait(NULL);
    	}

    item = 0;
    filename = "";

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

//implementing path
int path_index = 0;
char **implement_path(char **array){
    //creating path list(array)
    char **Path_lst = malloc(64 *sizeof(char));
    char *str1 = "/bin";
    char *str2 = "/usr/bin";
    Path_lst[path_index]= str1;
    Path_lst[path_index+1] = str2;
    if (strcmp(array[1]," ") == 0){
        printf("No path provided... \n");
        free(Path_lst);
    }
    if(array[1] != NULL){ //updating list
        Path_lst[path_index+1] = array[1];
        printf("made the path list \n");
    }
    return Path_lst;
}


