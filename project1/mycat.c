#include <stdio.h> //std library
#include <stdlib.h> // For exit()
int i;

int main(int argc, char *argv[])
{
    FILE *datafile;
    char buffer;

    for(i=1;i<argc;i++){
        datafile = fopen(argv[i], "r");
        if (datafile == NULL){
            printf("mycat: cannot open file\n");
            exit(0);
            }
        buffer = fgetc(datafile);
        if (datafile != NULL){
            while (buffer != EOF){
                printf ("%c", buffer);
                buffer = fgetc(datafile);
                }
            }
        fclose(datafile);
        printf("\n");
        }
    return 0;
}



