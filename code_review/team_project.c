/* Използвайте do-while цикъл, за да напишете функцията void itoa(int n, char s[]), 
която преобразува число в символен низ (обратната функция на atoi). do-while цикълът 
e необходим, тъй като в масива с ще трябва да се постави поне един символ, дори ако 
n е нула. Ако n = 123, за да вземем последната цифра, трябва да разделим n по модул(%) 
на основата на бройната система 10. За да получите чаръктър число, трябва да съберете
резултата с '0'. За да вземете следващото число, трябва да разделите n на 10. Това продължава 
докато n е различно от нула. Това генерира низа в обратен ред – 321, затова обърнете низа. */

#include <stdio.h>
#include<math.h>

void itoa(int n, char s[]);
int get_reversed(int n, char buf[]);

int main(){
    char s[1000];
    itoa(-1234,s);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[]){
    int i = 0;
    
    // if n < 0 add - to the final string
    if(n < 0){
        // add '-' as first element of the return string and offset the counter
        s[i] = '-';
        i++;
        n = abs(n);
    }
    
    char buf[11]; // 10 digits and the - sign
    int cnt = get_reversed(n, buf);
    
    //reverse the string in str_out
    for(cnt; cnt >= 0; cnt--){
        s[i] = buf[cnt];
        i++;
    }
    // Add '/0' to terminate the string
    s[i+1] = '\0';
}

int get_reversed(int n, char buf[]){
    // get reversed number as string
    int cnt = 0;   
    do{
        char ch = n % 10;
        n /= 10;
        buf[cnt] = ch + '0';
        cnt++;
    }
    while(n != 0);
    
    return cnt - 1; // return the number of charecters

}