/**
*   String Compression: Implement a method to perform basic string compression using the counts
*   of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
*   "compressed" string would not become smaller than the original string, your method should return
*   the original string. You can assume the string has only uppercase and lowercase letters (a - z).
**/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>

#define MAXN 256
using namespace std;

/***************************************************
*  Time Complexity: O(n)
*  Memory Compleity: O(n)
***************************************************/
string compressed(string str){
    ostringstream oss;
    int n = str.length();
    int cnt = 1;

    for(int i = 1; i < n; i++){
        if(str[i] != str[i - 1])
        {
            oss << cnt << str[i - 1];
            cnt = 1;
        }
        else
            ++cnt;
    }

    oss << cnt << str[n - 1];

    string str2 = oss.str();

    return n <= str2.length() ? str : str2;
}


int main(){
    string str = "aabcccccaaa";
    cout << compressed(str);
    return 0;
}
