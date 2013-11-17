#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char out_msg[] = "Here is a out msg!\n";
    char err_msg[] = "Here is a err msg!\n";
    char buf[256*4];
    int ret = 0;
    write(1,out_msg,sizeof(out_msg));
    write(2,err_msg,sizeof(err_msg));
    memset(buf,0,sizeof(buf));
    ret = read(0,buf,sizeof(buf));
    if(ret < 0) {
        write(2,"Read err\n",10);
    }
    write(1,buf,ret);
    exit(0);
}
