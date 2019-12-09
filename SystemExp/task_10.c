#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    //printf("euid:%d;uid:%d\n",geteuid(), getuid());    
    //setuid(getuid());
    //printf("euid:%d;uid:%d\n",geteuid(), getuid());
    system("/bin/ls -l");
}
