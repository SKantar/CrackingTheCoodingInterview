/**
*   URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
*   has sufficient space at the end to hold the additional characters, and that you are given the "true"
*   length of the string. (Note: if implementing in Java, please use a character array so that you can
*   perform this operation in place.)
*   EXAMPLE
*
*   Input: "Mr John Smith   ", 13
*   Output: "Mr%20John%20Smith"
**/

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 100
using namespace std;


/***************************************************
*  We have counter of every char in string (max 256)
*  Time Complexity: O(n + m) = O(3n)
*                   O(n) 'n' - string lenght
*  Memory Compleity: O(1)
***************************************************/
void change(char *str, int n){

    int space = 0;
    for(int i = 0; i < n; i++)
        if(str[i] == ' ')
            space ++;

    int lenght = n-- + 2 * space;
    str[lenght--] = '\0';

    while(n > -1){
        if(str[n] == ' '){
            str[lenght--] = '0';
            str[lenght--] = '2';
            str[lenght--] = '%';
        }else{
            str[lenght--] = str[n];
        }
        n --;
    }
}

int main(){
    char str[MAXN];
    strcpy(str, "Kantar Sladjan");
    change(str, strlen(str));
    puts(str);
    return 0;
}
