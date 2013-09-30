#include "w1ce.h"

#include <stdio.h>

int main()
{
    printf("Should be true : %d\n", w1_isfile("w1ce.h"));
    printf("Should be false: %d\n", w1_isfile("skjdfnskdw1ce.h"));
    return 0;
}

