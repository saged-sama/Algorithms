#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5+4;
vector<int> m(N), r(N);

pair<int, pair<int, int>> extended_gcd_cpp(int a, int b){
    if(b == 0){
        return {a, 
            {1, 0}};
    }
    pair<int, pair<int, int>> ret = extended_gcd_cpp(b, a % b);
    return {ret.first,
        {ret.second.second, ret.second.first - (a/b) * ret.second.second}};
}

long long int chinese_remainder_theorem_solution(vector<int>& r, vector<int>& m, int n){
    long long int bigX = 1ll;
    for(int i = 0; i < n; i++){
        bigX *= m[i] * 1ll;
    }
    
    long long int x = 0;
    for(int i = 0; i < n; i++){
        long long int bigXi = bigX / (m[i] * 1ll);

        pair<int, pair<int, int>> extgcd = extended_gcd_cpp(m[i], (int)(bigXi % (m[i] * 1ll)));
        long long int bigXinverse = (extgcd.second.second > 0) ? extgcd.second.second : (extgcd.second.second + m[i]) % m[i];

        x += r[i] * bigXi * bigXinverse;
    }
    return x;
}

int main()
{
    int n = 3; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> r[i] >> m[i];
    }
    
    int sol = chinese_remainder_theorem_solution(r, m, n);
    cout << "\nSolution: " << sol << "\n";
    for(int i = 0; i < n; i++){
        cout << sol << " = " << (sol % m[i]) << " mod " << m[i] << "\n";
    }
    return 0;
}