#include <stdio.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{
//printf("joshua\n");
FILE *datafile;
datafile =fopen("/tmp/test.py","r");
printf(datafile);
fclose(datafile);
}
