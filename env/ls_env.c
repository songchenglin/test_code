#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    extern char **environ;
    char **env = environ;
    while(*env != NULL) {
        printf("%s\n",*env);
        env++;
    }
    return 0;
}
