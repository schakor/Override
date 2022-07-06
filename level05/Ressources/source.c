#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void     main(void)
{
    char buff[100];
    int i;

    fgets(buff, 100, stdin);
    i = 0;
    while(i < strlen(buff))
    {
        if(buff[i] > 64 && buff[i] <= 90)
            buff[i] ^= 32;
        i++;
    }
    printf(buff);
    exit(0);
}
