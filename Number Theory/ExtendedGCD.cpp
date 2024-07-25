#include <iostream>
#include <algorithm>
using namespace std;

// using pointers
int extended_gcd(int a, int b, int * x, int  * y){
    if(b == 0){
        *x = 1, *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, &x1, &y1);
    *x = y1, *y = x1 - (a/b) * y1;
    return gcd;
}

// using the advantange of cpp data structures
pair<int, pair<int, int>> extended_gcd_cpp(int a, int b){
    if(b == 0){
        return {a, 
            {1, 0}};
    }
    pair<int, pair<int, int>> ret = extended_gcd_cpp(b, a % b);
    return {ret.first,
        {ret.second.second, ret.second.first - (a/b) * ret.second.second}};
}

int main(){
    int x, y;
    int a = 12, b = 8;
    int gcd = extended_gcd(a, b, &x, &y);
    cout << "gcd: " << gcd << "\t\tx: " << x << "\t\ty: " << y << "\n";

    pair<int, pair<int, int>> ret = extended_gcd_cpp(a, b);
    cout << "gcd: " << ret.first << "\t\tx: " << ret.second.first << "\t\ty: " << ret.second.second << "\n";
    return 0;
}