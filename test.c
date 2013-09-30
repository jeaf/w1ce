#include "w1ce.h"

#include <stdio.h>

int main()
{
    printf("Should be true : %d\n", w1_isfile("w1ce.h"));
    printf("Should be false: %d\n", w1_isfile("skjdfnskdw1ce.h"));
    printf("Should be false: %d\n", w1_isfile("."));
    printf("Should be true : %d\n", w1_isdir("."));
    char abspath[4096];
    w1_abspath(".", abspath, 4096);
    printf("Abs path       : %s\n", abspath);
    printf("Press key...\n");
    int c = w1_getch();
    printf("Key pressed is: %d\n", c);
    return 0;
}

