/**
*   Given a real number between O and 1 (e.g., 0.72) that is passed in as a double, print
*   the binary representation. If the number cannot be represented accurately in binary with at most 32
*   characters, print "ERROR:'
**/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string to_binary(double n){
    ostringstream oss;

    oss << "0.";

    while(n){
        n *= 2;
        if(n >= 1){
            oss << 1;
            n -= 1;
        }
        else{
            oss << 0;
        }
    }
    string res = oss.str();
    return res.length() >= 32 ? "ERROR" : res;
}

int main(){
    cout << to_binary(0.5) << endl;
    cout << to_binary(0.3) << endl;

    return 0;
}
