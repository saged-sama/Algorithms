#include <iostream>
#define lli long long int
using namespace std;

const lli MOD = 1e9+7;
const lli N = 1e3+5;

lli combo[N][N];
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
        invFacto[i] = loop_big_mod(facto[i], MOD-2);
    }
}

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

lli combination(int n, int r){
    if(r > n ){
        return 0ll;
    }
    return (((facto[n] * invFacto[r]) % MOD) * invFacto[n-r]) % MOD;
}

int main(){
    initFacto();
    initCombo();
    cout << combo[10][4] << "\n";
    cout << combination(10, 4) << "\n";
    return 0;
}