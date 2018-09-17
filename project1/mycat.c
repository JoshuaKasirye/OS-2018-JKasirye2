#include <stdio.h> //std library
#include <stdlib.h> // For exit()

int main(char *argc, char *argv[])  //argc, and argv[0/1..] for CMD
{
    FILE *datafile;
    char buffer;

    datafile = fopen(argv[1], "r");
    if (datafile == NULL)
    {
        printf("mycat: cannot open file\n");
        exit(0);
    }
    buffer = fgetc(datafile);
   if (datafile != NULL)
    {
        while (buffer != EOF)
        {
            printf ("%c", buffer);
            buffer = fgetc(datafile);
        }
    }
    fclose(datafile);
    return 0;
}


