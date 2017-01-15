/**
*   Flip Bit to Win: You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to
*   find the length of the longest sequence of ls you could create.
*   EXAMPLE
*   Input: 1775
*   Output: 8
**/

#include <cstdio>
using namespace std;

int longest(int n){
    int right = 1; int left = 1;
    int t = 0;
    int z = 0;
    int tmp = 0;
    while(right < (1 << 32))
    {
        z += ((n & right) > 0) ? 0 : 1;
        if(z > 1)
            z -= ((n & left) > 0) ? 0 : 1;

    }


}
