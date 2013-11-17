#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_IN "file_in"
#define FILE_OUT "file_out_by_char"
int main(int argc,char *argv[])
{
    char buf;
    int fd_in;
    int fd_out;
    /*
    if(argc != 2) {
        printf("Usage:./copy_by_char file_in file_out");
        exit(1);
    }
    */
   fd_in = open(FILE_IN,O_RDONLY); 
   if(fd_in < 0) {
       perror("Open failed!(in)");
       exit(1);
   }
   fd_out = open(FILE_OUT,O_WRONLY|O_CREAT,0644); 
   if(fd_out < 0) {
       perror("Open failed!(out)");
       exit(1);
   }
   while(0 != read(fd_in,&buf,1)){
       write(fd_out,&buf,1);
   }
   printf("copy finished\n");
   return 0;
}
