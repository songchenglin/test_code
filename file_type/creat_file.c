#include <stdio.h>
#include <stdlib.h>

#define FILE_IN     "file_in"
#define FILE_DOS    "file_dos"
#define FILE_LINUX  "file_linux"
#define FILE_MAC    "file_mac"
#define BUF_SIZE    (1024*8)
int main(void)
{
    FILE *fin,*fdos,*flinux,*fmac;
    char buf[BUF_SIZE];
    int ret,i;
    if((fin    = fopen(FILE_IN,"r"))    == NULL
     ||(fdos   = fopen(FILE_DOS,"w"))   == NULL
     ||(flinux = fopen(FILE_LINUX,"w")) == NULL
     ||(fmac   = fopen(FILE_MAC,"w"))   == NULL) {
        perror("Open failed!");
        exit(1);
    }
    while((ret = fread(buf,sizeof(char),BUF_SIZE,fin)) > 0) {
        for(i = 0;i < ret;i++) {
            if(buf[i] == '\n') {
                fwrite("\r\n",sizeof(char),2,fdos);
                fwrite("\n",sizeof(char),1,flinux);
                fwrite("\r",sizeof(char),1,fmac);
            } else {
                fwrite(&buf[i],sizeof(char),1,fdos);
                fwrite(&buf[i],sizeof(char),1,flinux);
                fwrite(&buf[i],sizeof(char),1,fmac);
            }
        }
    }
    printf("Finish!\n");
    return 0;
}
