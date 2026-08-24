#include <iostream>
#define lli long long int
using namespace std;

const lli MOD = 1e9+7;
const lli N = 2e3+5;

lli facto[N];
lli invFacto[N];

long long int loop_big_mod(long long int n, long long int p){
    long long int ret = 1ll;
    while(p){
        if(p & 1) ret = (ret * n) % MOD;
        p >>= 1;
        n = (n * n) % MOD;
    }
    return ret;
}

void initFacto(){
    facto[0] = 1ll;
    for(int i = 1; i < N; i++){
        facto[i] = (facto[i-1] * 1ll * i) % MOD; 
    }
    
    invFacto[N-1] = loop_big_mod(facto[N-1], MOD-2);

    for(int i = N-2; i >= 0; i--){
        invFacto[i] = (invFacto[i+1] * (i+1)) % MOD;
    }
}

lli recursiveFactorial(int n){
    if(n == 0) return 1ll;
    return (n * 1ll * recursiveFactorial(n-1)) % MOD;
}

lli loopFacto(int n){
    lli ans = 1ll;
    for(int i = 1; i <= n; i++){
        ans = (ans * i) % MOD;
    }
    return ans;
}

lli permutation(int n, int r){
    if(r > n) return 0;
    lli ans = 1ll;
    for(int i = n; i > n-r; i--){
        ans = (ans * i) % MOD;
    }
    return ans;
}

lli permutationFacto(int n){
    return permutation(n, n);
}

int main(){
    initFacto();
    cout << facto[5] << "\n";
    cout << recursiveFactorial(5) << "\n";
    cout << loopFacto(5) << "\n";
    cout << permutationFacto(5) << "\n";
    cout << invFacto[5] << "\n";
    return 0;
}