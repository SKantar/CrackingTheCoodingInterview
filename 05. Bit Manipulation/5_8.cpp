/**
*   Draw Line: A monochrome screen is stored as a single array of bytes, allowing eight consecutive
*   pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will
*   be split across rows). The height of the screen, of course, can be derived from the length of the array
*   and the width. Implement a function that draws a horizontal line from ( xl, y) to ( x2, y).
*   The method signature should look something like:
*   drawline(byte[] screen, int width, int xl, int x2, int y)
**/

#include <iostream>
#include <bitset>
#include <cstdlib>
#include <cstring>
#define MAXN 256
using namespace std;

void drawline(char screen[], int width, int x1, int x2, int y){
    int t1 = (y * width << 3) + x1;
    int t2 = (y * width << 3) + x2;

    if(t1 / 8 == t2 / 8){
        char mask1 = 0xff;
        mask1 = ~(mask1 << (8 - (t1 % 8)));

        char mask2 = 0xff;
        mask2 = mask2 << (7 - (t2 % 8));

        screen[t2 / 8] = mask1 & mask2;

    }else{

        for(int i = t1 / 8 + 1; i < t2 / 8; i++){
             screen[i] = ~screen[i];
        }

        char mask = 0xff;
        mask = ~(mask << (8 - (t1 % 8)));

        screen[t1 / 8] = mask;

        mask = 0xff;
        mask = mask << (7 - (t2 % 8));

        screen[t2 / 8] = screen[t2 / 8] | mask;
    }
}

void print(char screen[], int width){

    for(int i = 0; i < MAXN; i++){

        if(i && i % width == 0)
            cout << endl;
        cout << bitset<8>(screen[i]);
    }

}

int main(){
    char screen[MAXN];
    memset(screen, 0, MAXN * sizeof(char));

    int width = 4;

    drawline(screen, width, 0, 29, 3);

    print(screen, width);

    return 0;
}
