#include <bits/stdc++.h>
using namespace std;
#define int long long int

int mod = 1e9+7;

int exponentiate(int n, int p){
    if(p == 0) return 1;
    if(p == 1) return (n % mod);
    int e = exponentiate(n, p >> 1);
    if(p&1){
        return (((e*e) % mod) * (n % mod)) % mod;
    }
    return (e * e) % mod;
}

int eexp(int n, int p){
    int ret = 1;
    while(p){
        if(p & 1) ret = (ret * n) % mod;
        p >>= 1;
        n = (n * n) % mod;
    }
    return ret;
}

signed main()
{
    int n, p; cin >> n >> p;
    cout << exponentiate(n, p) << "\n" << eexp(n, p) << "\n";
    return 0;
}
