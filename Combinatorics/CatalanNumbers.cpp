#include <iostream>
#define lli long long int
using namespace std;

const lli MOD = 1e9+7;
const lli N = 1e3+5;

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

lli loop_big_mod(lli n, lli p){
    lli ret = 1ll;
    while(p){
        if(p & 1) ret = (ret * n) % MOD;
        p >>= 1;
        n = (n * n) % MOD;
    }
    return ret % MOD;
}

lli catalan(int n){
    return (combo[n+n][n] * loop_big_mod(n+1ll, MOD-2ll))%MOD;
}

int main(){
    initCombo();
    cout << combo[4][2] << " " << combo[10][4] << "\n";
    cout << loop_big_mod(2, 5) << " " << loop_big_mod(2, MOD-2) << "\n";

    cout << catalan(10) << "\n";
    return 0;
}