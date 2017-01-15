/**
*   Check Permutation: Given two strings, write a method to decide if one is a permutation of the
*   other.
**/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MAXN 256

using namespace std;
/***************************************************
*  Brute force solution
*  Compare every permutation of str1 with str2
*  Time Complexity: O(n! * n) 'n' - string lenght
*  Memory Compleity: O(1)
****************************************************
bool check(char *str1, char *str2){
    int n = strlen(str1);

    do {
        if(!strcmp(str1, str2))
            return true;
    } while ( next_permutation(str1, str1 + n) );

    return false;
}
***************************************************/

/***************************************************
*  Dinamic solution
*  We have counter of every char in string (max 256)
*  Time Complexity: O(n + m + 2 * 256) = O(max(m, n))
*                   O(n) 'n' - string lenght
*  Memory Compleity: O(256) => O(1)
***************************************************/
bool check(char *str1, char *str2){
    int mark[MAXN];
    memset(mark, 0, MAXN * sizeof(int));

    while(*str1){
        mark[*str1] ++;
        str1++;
    }

    while(*str2){
        mark[*str2] --;
        str2++;
    }

    for(int i = 0; i < MAXN; i++)
        if(mark[i] != 0)
            return false;
    return true;
}


int main(){
    char str1[] = "Sladjan";
    char str2[] = "najdalS";
    printf("%s\n", check(str1, str2) ? "Yes" : "No");
    return 0;
}
