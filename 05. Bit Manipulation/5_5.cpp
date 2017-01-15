/**
*   Debugger: Explain what the following code does: ( ( n & ( n-1)) == 0).
**/

#include <cstdio>
using namespace std;

bool is_power_of_2(int n){
    return !(n & (n - 1));
}

int main(){
    printf("%s\n", is_power_of_2(16) ? "Yes" : "No");
    printf("%s\n", is_power_of_2(15) ? "Yes" : "No");
    return 0;
}
