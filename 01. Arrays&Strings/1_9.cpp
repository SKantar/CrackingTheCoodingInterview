/**
*   String Rotation:Assumeyou have a method isSubstringwhich checks if one word is a substring
*   of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one
*   call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").
**/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 256
using namespace std;

int main(){
    char str1[MAXN];
    char str2[MAXN];
    strcpy(str1, "erbottlewat");
    strcpy(str2, "waterbottle");
    strcat(str1, str1);



    printf("%s\n", strstr(str1, str2) == NULL ? "No" : "Yes");
    return 0;
}
