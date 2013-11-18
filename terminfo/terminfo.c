#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>

int main(void)
{
    setupterm(NULL,fileno(stdout),NULL);
    printf("Done\n");
    return 0;
}
