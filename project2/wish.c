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

//Main functions for the wish.c
int main(int argc, char *argv[]){
    if (argc == 1){
        wish_loop();
    }
    else if (argc == 2){
        //wish_bash();
        printf("USe the Bash niggar");
    }
    else if(argc > 2 ){
        printf("Please The maximum arguments are two");
        exit(1);
    }

    return 1;
    }


//wish loop
int wish_loop(){
    char **task;
    while(1){
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
    //scanf("%[^\n]s",name);
    token = strtok(name," ");

    int i = 0;
    while (token != NULL){
	//token[strcspn(token,"\n")];
        array[i] = token;
       	token = strtok (NULL," ");
        i = i + 1;
        }
    array[i] = NULL;
    return array;
}


//Execution command
int exec_cmd(char **array){
   // printf("%s",array[0]);
    if (array[0] == "exit"){
        wish_exit();
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
    printf("%s", path1);
    printf("%s", path2);

   // printf("%s",array[0]);

    if (access(path1, F_OK)==0){
        pid_t pid = fork();
        if (pid == 0){
            array[0] = path1;
            execv(array[0],array);
            printf("The exec didn't work ");
            }
        else{
            printf("no child ");
            }
     }
     else if (access(path2, F_OK)==0){
        pid_t pid = fork();
        if (pid == 0){
            array[0] = path2;
            execv(array[0],array);
            printf("The exec didn't work ");
            }
        else{
            printf("no child ");
            }
     }

     else {
        printf("This has no path\n");
     }

    return 1;
}


int wish_exit(){
    exit(0);
}






