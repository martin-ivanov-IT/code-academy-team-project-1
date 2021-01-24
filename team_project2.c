#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
    int number = 0;
    unsigned long sum = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        s[i] = toupper(s[i]);
        if (s[i] >= '0' && s[i] <= '9') number = s[i] - '0';

        else if (s[i] >= 'A' && s[i] <= 'F')number = s[i] - 'A' + 10;

        else
        {
            printf("Invalid input\n");
            break;
        }
        sum = sum * 16 + (number);
    }
    return sum;
}