#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
char *fn = "/home/seed/SystemExp/ca_test_1_out.c";
char buf[60];
FILE* fp_out;
FILE* fp_in = fopen("/home/seed/SystemExp/ca_test_1_in.c", "r");
fread(buf, 1, sizeof(buf), fp_in);
fp_out = fopen(fn, "a+");
if(fp_out != NULL)
{
  fwrite("\n", sizeof(char), 1, fp_out);
  fwrite(buf , sizeof(char), strlen(buf), fp_out);
  fclose(fp_in);
  fclose(fp_out);
  printf("Write successful!\n");
}
else
{
  printf("No Permission!\n");
}
}
