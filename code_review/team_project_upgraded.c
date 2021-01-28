/* Използвайте do-while цикъл, за да напишете функцията void itoa(int n, char s[]), 
която преобразува число в символен низ (обратната функция на atoi). do-while цикълът 
e необходим, тъй като в масива с ще трябва да се постави поне един символ, дори ако 
n е нула. Ако n = 123, за да вземем последната цифра, трябва да разделим n по модул(%) 
на основата на бройната система 10. За да получите чаръктър число, трябва да съберете
резултата с '0'. За да вземете следващото число, трябва да разделите n на 10. Това продължава 
докато n е различно от нула. Това генерира низа в обратен ред – 321, затова обърнете низа. */

#include <stdio.h>
//#include <math.h> // работи без него

void itoa(int n, char s[]);
int get_reversed(int n, char buf[]);

int main(){
    int n = 0;
    char s[20]=""; //добавя символи в края според размера. Не трие предишно?
    printf ("Value: ");
    scanf ("%d", &n);
    itoa(n,s);
    return 0;
}

void itoa(int n, char s[]){
    int i = 0;
    if(n < 0){
        s[i] = '-';
        i++;
        n = -n; //защо не работи без abs()
    }
    char buf[11];
    int cnt = get_reversed(n, buf);
    for(cnt; cnt >= 0; cnt--){
        s[i] = buf[cnt];
        i++;
    }
    s[i] = '\0'; 
    printf("Result: %s\n",s); //добавен printf във функ.
}

int get_reversed(int n, char buf[]){
    int cnt = 0;   
    do{
        char ch = n % 10;
        n /= 10;
        buf[cnt] = ch + '0';
        cnt++;
    }
    while(n != 0);
    return cnt - 1;
}