#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main()
{
    setuid(0);
    char* fn="/etc/passwd";
    char buff[50];
    FILE *fp;
    scanf("%50s", buff);
    if((fp=fopen(fn, "a+"))!=NULL)
    {
        fwrite("\n", sizeof(char), 1, fp);
        fwrite(buff, sizeof(char), strlen(buff), fp);
        printf("Add User Successfully!\n");
        fclose(fp);
     }
     else printf("No Permission!\n");
}
