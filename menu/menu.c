#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

char *menu[] = {
    "a - add new record",
    "d - delete record",
    "q - quit",
    NULL,
};
int getchoice(char *prompt,char *menu[],FILE *in,FILE *out);
int main(void)
{
    char choice = 0;
    FILE *tty_in;
    FILE *tty_out;
    struct termios raw_setting,new_setting;
    if(!isatty(fileno(stdout))) {
        fprintf(stderr,"Stdout is redirected!\n");
    }
    tty_in = fopen("/dev/tty","r");
    tty_out = fopen("/dev/tty","w");
    tcgetattr(fileno(tty_in),&raw_setting);
    new_setting = raw_setting;
    new_setting.c_lflag &= ~(ICANON|ECHO|ISIG);
    new_setting.c_cc[VMIN] = 1;
    new_setting.c_cc[VTIME] = 0;
    if(tcsetattr(fileno(tty_in),TCSANOW,&new_setting) != 0) {
        fprintf(stderr,"Couldn't set attributes\n");
    }
    do {
        choice = getchoice("Please make a choice:",menu,tty_in,tty_out);
        printf("You select %c\n",choice);
    } while(choice != 'q');
    tcsetattr(fileno(tty_in),TCSANOW,&raw_setting);
    return 0;
}

int getchoice(char *prompt,char *menu[],FILE *in,FILE *out)
{
    char **menu_p = menu;
    char selected = 0;
    int flag  = 0;
    fprintf(out,"%s\n",prompt);
    do {
        while(*menu_p != NULL) {
            fprintf(out,"%s\n",*menu_p);
            menu_p++;
        }
        menu_p = menu;
        //fflush(stdin);
        do {
            selected = getchar();
        } while(selected == '\n');
        while(*menu_p != NULL) {
            if(selected == *menu_p[0]) {
                flag = 1;
                break;
            }
            menu_p++;
        }
        if(flag == 0) {
            fprintf(stderr,"Error choice!\nSelect again:\n");
        }
    } while(flag == 0);
    return selected;
}
