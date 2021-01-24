#include <stdio.h>
unsigned long htoi (char s[]);
int main (){
    char s[10];
    printf ("0x");
    scanf("%s", s);
    unsigned long rez=htoi(s);
    printf ("Hex: %s\n",s);
    printf ("Dec: %ld\n",rez);
    return 0;
}
unsigned long htoi (char s[]){
    int i=0;
    int br=0;
    int number=0;
    unsigned long sum=0;
    for (br=0;s[br]!=0;br++); 
    for (i=0;i<br;i++){
        if (s[i]>='0' && s[i]<='9') {
            number = s[i] - '0';
        }
        else if (s[i]>='A' && s[i]<='F'){
            number = s[i] - 'A';
            number+=10;
        }
        else if (s[i]>='a' && s[i]<='f'){
            number = s[i] - 'a';
            number+=10;
        }
        else{
            printf ("Invalid input\n");
            break;
        }
        sum = sum*16 + (number);
    }
    return sum;
}