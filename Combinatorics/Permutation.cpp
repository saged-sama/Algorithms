#include <iostream>
#define lli long long int
using namespace std;

const lli MOD = 1e9+7;
const lli N = 2e3+5;

lli permu[N][N];

void initPermu(){
    for(int i = 0; i < N; i++){
        permu[i][0] = 1;
        permu[i][1] = i % MOD;
    }

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            permu[i][j] = 0;
        }
    }

    for(int i = 1; i < N; i++){
        for(int j = 1; j <= i; j++){
            permu[i][j] = (permu[i-1][j] + (j * permu[i-1][j-1]) % MOD) % MOD;
        }
    }
}

lli permutation(int n, int r){
    lli ans = 1ll;
    for(int i = n; i > n-r; i--){
        ans = (ans * i) % MOD;
    }
    return ans;
}

int main(){
    initPermu();
    cout << permutation(5, 5) << "\n";
    cout << permu[5][5] << "\n";
    return 0;
}