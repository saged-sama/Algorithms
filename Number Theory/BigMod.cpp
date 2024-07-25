#include <iostream>
using namespace std;

const long long int MOD = 1e9+7;

long long int loop_big_mod(long long int n, long long int p){
    long long int ret = 1ll;
    while(p){
        if(p & 1) ret = (ret * n) % MOD;
        p >>= 1;
        n = (n * n) % MOD;
    }
    return ret;
}

long long int recursive_big_mod(long long int n, long long int p){
    if(p == 0) return 1ll;
    long long int ret = recursive_big_mod(n, p >> 1);
    ret = (ret * ret) % MOD;
    if(p & 1){
        ret = (ret * n) %  MOD;
    }
    return ret;
}

int main()
{
    int n = 2, p = 2918;
    cout << loop_big_mod(n, p) << "\n";
    cout << recursive_big_mod(n, p) << "\n";
    return 0;
}