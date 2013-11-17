#include <syslog.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("abcdefg","r");
    if(!fp) {
        syslog(LOG_USER|LOG_ERR,"Scl test - %m\n");
    }
    return 0;
}
