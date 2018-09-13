#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void my_write(FILE *fp, char *str)
{
    fprintf(fp, "%s", str);
}

int main(void)
{
    char *str = "test text\n";
    FILE *fp;

    fp = fopen("test.txt", "r+");
    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return 1;
    }
    my_write(fp, str);

    fclose(fp);

    return 0;
}
