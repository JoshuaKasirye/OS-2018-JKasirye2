#include <stdio.h> //std library
#include <stdlib.h> // For exit()
#include <string.h> // string lib
#define  MAXStr_LEN  100 // Maximum
int i;

int main(int argc, char *argv[])
{
    FILE *datafile;
    char line[MAXStr_LEN];
    char *dataline; //all characters per line

    for(i=2;i<argc;i++){
        datafile = fopen(argv[i], "r");
        if(datafile == NULL){
            printf("mygrep: cannot open file %s \n",argv[i]);
            exit(1);}
        dataline = fgets(line,MAXStr_LEN,datafile);
        if (datafile != NULL ){
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
        }
    return 0;
}

