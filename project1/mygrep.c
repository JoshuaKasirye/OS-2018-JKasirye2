//Created by Joshua Kasirye
//OS project 1
//57442019

#include <stdio.h> //std C library
#include <stdlib.h> // To enable use of exit()
#include <string.h> // string lib
#define  MAXStr_LEN  100 // Maximum str length
int i; //for loop varibale

int main(int argc, char *argv[])
{
    FILE *datafile;  //file varibale name
    char line[MAXStr_LEN];
    char *dataline; //all characters per line

    for(i=2;i<argc;i++){
        datafile = fopen(argv[i], "r"); //opening file for only reading
        if(datafile == NULL){
            printf("mygrep: cannot open file %s \n",argv[i]);
            exit(1);}
        dataline = fgets(line,MAXStr_LEN,datafile); //getting the string of characters in a line
        if (datafile != NULL ){
            if (argv[1] == " "){
                exit(0);}
            else{  //if argv[0]it's not empty string
                while( dataline!= NULL){
                    if(strstr(dataline,argv[1])!=0){
                        printf("%s",dataline);}
                    dataline = fgets(line,MAXStr_LEN,datafile);} //updating the dataline variable
                }
            }
        fclose(datafile); // closing every file after being read from
        printf(" ");
        }
    return 0;
}

