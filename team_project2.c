#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

unsigned long htoi(char s[]);
int main()
{
    char s[10];
    printf("0x");
    scanf("%s", s);
    printf("Hex: %s\n", s);
    printf("Dec: %ld\n", htoi(s));

    return 0;
}
unsigned long htoi(char s[])
{

    for (int i = 0; i < strlen(s); i++)
    {
        s[i] = toupper(s[i]);
        if (!(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'A' && s[i] <= 'F'))
        {
            printf("Invalid input\n");
            return 0;
        }
    }
    return strtol(s, NULL, 16);
}