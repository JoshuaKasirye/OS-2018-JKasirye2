#include <stdio.h> //std library
#include <stdlib.h> // For exit()
#include <string.h> // string lib

int main(char *argc, char *argv[])
{
    FILE *datafile;
    char buffer;

    datafile = fopen(argv[1], "r");

    if (datafile == NULL)
    {
        printf("my-grep: cannot open file or \n");
        exit(1);
    }

    if (datafile != NULL )
    {
        if (argv[0] == " ")
        {
            while (buffer != EOF){ //if it's empty string, cat[1]
                printf ("%c", buffer);
                buffer = fgetc(datafile);
                }
        }
        else {   //if argv[0]it's not empty string
            while (buffer != EOF){
                    if (strstr(buffer, argv[0]))
                    printf ("%c", buffer);
                    buffer = fgetc(datafile);
                    }
            }
    fclose(datafile);
    return 0;
    }
}

