#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    decrypt(int nb)
{
    char    buff[17] = "Q}|u`sfg~sf{}|a3";
    int     i;

    i = 0;
    while (i < strlen(buff))
    {
        buff[i] ^= nb;
        i++;
    }
    if (strncmp(buff, "Congratulations!", 17) == 0)
        system("/bin/sh");
    else
        puts("\nInvalid Password");
    return ;
}

void    test(int password, int number)
{
    int     key;

    key = number - password;
    if ((key >= 1 && key <= 9) || (key >= 16 && key <= 21))
        decrypt(key);
    else
        decrypt(rand());
}

int     main()
{
    int     password;

    srand(time(0));
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &password);
    test(password, 322424845);
    return 0;
}
