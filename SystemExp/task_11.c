#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char **environ;

int main()
{
    char *argv[3];
    argv[0]="/bin/ls";
    argv[1]="-l";
    argv[2]=NULL;

    setuid(getuid());
    execve(argv[0], argv, environ);
    return 0;
}
