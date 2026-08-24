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

lli catalan(int n){
    return (combo[n+n][n] - combo[n+n][n+1] + MOD) % MOD;
}

int main(){
    initCombo();
    cout << combo[4][2] << " " << combo[10][4] << "\n";
    cout << loop_big_mod(2, 5) << " " << loop_big_mod(2, MOD-2) << "\n";

    cout << catalan(10) << "\n";
    return 0;
}