/**
*   One Away: There are three types of edits that can be performed on strings: insert a character,
*   remove a character, or replace a character. Given two strings, write a function to check if they are
*   one edit (or zero edits) away.
*   EXAMPLE
*       pales,  pale    -> true
*       pale,   bale    -> true
*       pale,   bake    -> true
*       pale,   ple     -> false
**/

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

bool check(char str1[], char str2[]){
    int n = strlen(str1);
    int m = strlen(str2);

    if(abs(n - m) > 1)
        return false;

    int i = 0;
    while(str1[i] == str2[i])
        i++;
    if(i == n || i == m)
        return true;
    i++;
    int k = 0;
    if(n == m)
        k = 0;
    else if (n > m)
        k = 1;
    else
        k = -1;

    while(1){
        if(!str2[i])
            break;

        if(str1[i + k] == str2[i])
            i++;
        else
            return false;
    }
    return true;
}

int main(){
    char str11[] = "pale";
    char str12[] = "ple";

    char str21[] = "pales";
    char str22[] = "pale";

    char str31[] = "pale";
    char str32[] = "bale";

    char str41[] = "pale";
    char str42[] = "bake";

    printf("%s\n", check(str11, str12) ? "Yes" : "No");
    printf("%s\n", check(str21, str22) ? "Yes" : "No");
    printf("%s\n", check(str31, str32) ? "Yes" : "No");
    printf("%s\n", check(str41, str42) ? "Yes" : "No");

    return 0;
}
