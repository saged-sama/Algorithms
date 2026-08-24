#include <iostream>
#define lli long long int
using namespace std;

const lli MOD = 1e9+7;
const lli N = 2e3+5;

lli combo[N][N];

void initCombo(){
    for(int i = 0; i < N; i++){
        combo[i][0] = combo[i][i] = 1;
        combo[i][1] = i;
    }

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            combo[i][j] = 0;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 2; j < i; j++){
            combo[i][j] = (combo[i-1][j] + combo[i-1][j-1]) % MOD;
        }
    }
}

lli catalan(int n){
    return (combo[n+n][n] - combo[n+n][n+1] + MOD) % MOD;
}

lli permutation(int n, int r){
    if(r > n) return 0;
    lli ans = 1ll;
    for(int i = n; i > n-r; i--){
        ans = (ans * i) % MOD;
    }
    return ans;
}

long long int loop_big_mod(long long int n, long long int p){
    long long int ret = 1ll;
    while(p){
        if(p & 1) ret = (ret * n) % MOD;
        p >>= 1;
        n = (n * n) % MOD;
    }
    return ret;
}

lli combination(int n, int r){
    if(r > n) return 0;
    return (permutation(n, r) * loop_big_mod(permutation(r, r), MOD-2)) % MOD;
}

lli catalanV2(int n){
    return (combination(n+n, n) - combination(n+n, n+1) + MOD) % MOD;
}

int main(){
    initCombo();
    cout << catalan(10) << "\n";
    cout << catalanV2(10) << "\n";
    return 0;
}