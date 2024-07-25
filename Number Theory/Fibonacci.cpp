#include <iostream>
using namespace std;

const long long int MOD = 1e18+7;
const long long int N = 1e5+7;
long long int fib[N];

// O(n) at worst case O(1) at best
// is only good for calculating fibonacci upto a millionth term
long long int fibonacci(long long int n){
    if(fib[n] > 0) return fib[n];
    if(n == 0) return fib[0] = 0;
    if(n == 1) return fib[1] = 1;
    return fib[n] = (fibonacci(n-1) + fibonacci(n-2)) % MOD;
}

int main(){
    cout << fibonacci(200) << "\n";
    return 0;
}