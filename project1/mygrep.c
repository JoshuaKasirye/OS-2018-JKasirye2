
#include <stdio.h> //std library
#include <stdlib.h> // For exit()
#include <string.h> // string lib
#define  MAXStr_LEN  100 // Maximum

int main(char *argc, char *argv[])
{
    FILE *datafile;
    char line[MAXStr_LEN];
    char *dataline; //all characters per line

    datafile = fopen(argv[2], "r");
    if (datafile == NULL)
    {
        printf("my-grep: cannot open file %s \n",argv[2]);
        exit(1);}

    dataline = fgets(line,MAXStr_LEN,datafile);
    if (datafile != NULL )
    {
        if (argv[1] == " "){
            exit(0);}
        else{  //if argv[0]it's not empty string
            while( dataline!= NULL){
                if(strstr(dataline,argv[1])!=0){
                    printf("%s",dataline);}
                dataline = fgets(line,MAXStr_LEN,datafile);}
        }
    }
    fclose(datafile);
    return 0;
}


