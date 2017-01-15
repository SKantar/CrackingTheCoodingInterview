/**
*   Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
*   cannot use additional data structures?
**/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 256

using namespace std;

/***************************************************
*  Brute force solution
*  Check every possible pair
*  Time Complexity: O(n ^ 2) 'n' - string lenght
*  Memory Compleity: O(1)
****************************************************

bool check(char *str){
    for(int i = 0; i < strlen(str); i ++)
        for(int j = i + 1; j < strlen(str); j++)
            if(str[i] == str[j])
                return false;
    return true;
}
***************************************************/

/***************************************************
*  Dinamic solution
*  We have marker for every char (max 256)
*  Time Complexity: O(n) 'n' - string lenght
*  Memory Compleity: O(256) => O(1)
***************************************************/
bool check(char *str){
    bool mark[MAXN];
    memset(mark, false, MAXN);

    while(*str){
        if(mark[*str])
            return false;
        else
            mark[*str] = true;
        str++;
    }
    return true;
}

int main(){
    char str[] = "Sladjan Kantar";
    printf("%s", check(str) ? "Yes" : "No");

    return 0;
}
