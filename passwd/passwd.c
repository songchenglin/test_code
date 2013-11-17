#include <termios.h>
#include <stdio.h>
#include <stdlib.h>

#define PASSWORD_LEN     (6)

int main(void)
{
    struct termios raw_setting,new_setting;
    char password[PASSWORD_LEN+1];
    tcgetattr(fileno(stdin),&raw_setting);
    new_setting = raw_setting;
    new_setting.c_lflag &= ~ECHO;
    printf("Enter password:\n");
    if(tcsetattr(fileno(stdin),TCSAFLUSH,&new_setting) != 0) {
        fprintf(stderr,"Couldn't set attributes\n");
    } else {
        fgets(password,PASSWORD_LEN,stdin);
        tcsetattr(fileno(stdin),TCSANOW,&raw_setting);
        fprintf(stdout,"\nYou entered:%s\n",password);
    }
    return 0;
}
