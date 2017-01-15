/**
*   Pairwise Swap: Write a program to swap odd and even bits in an integer with as few instructions as
*   possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
**/

#include <iostream>
#include <bitset>
using namespace std;

int even = 0xaaaaaaaa;
int odd = 0x55555555;

int swap(int n){
    return  ((n & even) >> 1 | (n & odd) << 1);
}

int main(){
    int n = 0xabcf;

    cout << bitset<32>(n) << endl;
    cout << bitset<32>(swap(n)) << endl;

    return 0;
}
