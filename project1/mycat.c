//Created by Joshua Kasirye
//OS project 1
//57442019

#include <stdio.h> //std C library
#include <stdlib.h> // to enable exit()
int i; //for loop variable

int main(int argc, char *argv[])
{
    FILE *datafile;  // file varible name
    char content;   //variable name for characters being read in a line

    for(i=1;i<argc;i++){
        datafile = fopen(argv[i], "r");  //opening the file
        if (datafile == NULL){
            printf("mycat: cannot open file\n"); //if the file in datafile can't be opened
            exit(0);
            }
        content = fgetc(datafile); // getting characters from opened file
        if (datafile != NULL){
            while (content != EOF){ // loop to print every character in file to the end
                printf ("%c", content);
                content = fgetc(datafile);
                }
            }
        fclose(datafile); //closing the file
        printf("\n");
        }
    return 0;
}



