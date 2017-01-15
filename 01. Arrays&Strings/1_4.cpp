/**
*   Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin­
*   drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
*   is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
**/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 256
using namespace std;

/***************************************************
*  Brute force solution
*  Check is palinrom, every permutation of str
*  Time Complexity: O(n! * n) 'n' - string lenght
*  Memory Compleity: O(1)
****************************************************
bool is_palindrome(char *str, int n){
    for(int i = 0; i < n / 2; i++)
        if(str[i] != str[n - 1 - i])
            return false;
    return true;
}

bool check(char *str){

    int n = strlen(str);
    do{
        if(is_palindrome(str, n))
            return true;
    }while(next_permutation(str, str + n));

    return false;
}
***************************************************/

/***************************************************
*  Dinamic solution
*  We have counter of every char in string (max 256)
*  Time Complexity: O(2*n + 2 * 256)
*                   O(n) 'n' - string lenght
*  Memory Compleity: O(256) => O(1)
***************************************************/
bool check(char *str){
    int mark[MAXN];
    memset(mark, 0, MAXN * sizeof(int));

    while(*str){
        mark[*str] ++;
        str++;
    }

    bool odd = false;
    for(int i = 0; i < MAXN; i++){
        if(mark[i] % 2)
            if(odd)
                return false;
            else
                odd = true;
    }
    return true;
}

int main(){

    char str[] = "aaaab";
    printf("%s\n", check(str) ? "Yes" : "No");
}
