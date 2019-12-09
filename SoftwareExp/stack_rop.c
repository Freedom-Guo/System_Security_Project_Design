/* stack.c */

/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str, int count)
{
    char buffer[12];
    //memset();
//printf("%d\n", strlen(str));

    /* The following statement has a buffer overflow problem */ 
    memcpy(buffer, str, count);
    return 1;
}

int main(int argc, char **argv)
{
    char str[200];
    FILE *badfile;
    int count = 0;

    badfile = fopen("./badfile", "rb");
    count = fread(str, sizeof(char), 200, badfile);

    bof(str, count);

    printf("Returned Properly\n");
    return 1;
}

