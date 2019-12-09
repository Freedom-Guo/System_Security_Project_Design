#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <linux/capability.h>
#include <sys/capability.h>

int main(void) {

     if (open ("/etc/shadow", O_RDONLY) < 0)

                 printf("(1) Open failed\n");

     /* 问题1：上面的打开操作是否成功？为什么？*/

     if (cap_disable(CAP_DAC_READ_SEARCH) < 0) return -1;

     if (open ("/etc/shadow", O_RDONLY) < 0)

                 printf("(2) Open failed\n");

     /* 问题2：上面的打开操作是否成功？为什么？*/

     if (cap_enable(CAP_DAC_READ_SEARCH) < 0) return -1;

     if (open ("/etc/shadow", O_RDONLY) < 0)

                 printf("(3) Open failed\n");

     /* 问题3：上面的打开操作是否成功？为什么？*/
    
     if (cap_drop(CAP_DAC_READ_SEARCH) < 0) return -1;

     if (open ("/etc/shadow", O_RDONLY) < 0)

                 printf("(4) Open failed\n");

     /* 问题4：上面的打开操作是否成功？为什么？*/

     if (cap_enable(CAP_DAC_READ_SEARCH) == 0) return -1;

     if (open ("/etc/shadow", O_RDONLY) < 0)

                 printf("(5) Open failed\n");

     /* 问题5：上面的打开操作是否成功？为什么？*/
}

