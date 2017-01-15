/**
*   Conversion: Write a function to determine the number of bits you would need to flip to convert
*   integer A to integer B.
*   EXAMPLE
*   Input: 29 (or: 11101), 15 (or: 01111)
*   Output: 2
**/

#include <iostream>

using namespace std;

int difference(int a, int b){
    int res = 0;
    while(a || b){
        res += (a ^ b) & 1;

        a >>= 1;
        b >>= 1;
    }
    return res;
}


int main(){

    cout << difference(29, 15) << endl;
    return 0;
}
