#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int i;
    char des_name[20] = "testname";
    char *ret_name;
    for(i = 0;i < 10;i++) {
        ret_name = tmpnam(des_name);
        if(ret_name != NULL)
            printf("%s\n",ret_name);
        else
            printf("creat err!\n");
    }
    return 0;
}
