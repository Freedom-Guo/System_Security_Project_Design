#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
    printf("uid: %d\n", getuid());
    printf("euid: %d\n", geteuid());
    setuid(0);
    printf("uid after set: %d\n", getuid());
    printf("euid after set: %d\n", geteuid());
}
