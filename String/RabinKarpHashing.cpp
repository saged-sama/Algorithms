#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

const int N = 1e6+2;
const int mod1 = 1e9+7, mod2 = 1e9+9;
const int p1 = 31, p2 = 37;
vector<pair<int, int>> hash1(N);
vector<pair<int, int>> hash2(N);

int modinv(int n, int mod){
    int ret = 1;
    int p = mod-2;
    while(p){
        if(p&1) ret = (ret * n) % mod;
        p >>= 1;
        n = (n * n) % mod;
    }
    return ret;
}

void hashPrecalc()
{
    hash1[0].first = hash2[0].first = 1;
    for(int i = 1; i < N; i++){
        hash1[i].first = (hash1[i-1].first * p1) % mod1;
        hash2[i].first = (hash2[i-1].first * p2) % mod2;
    }

    int modinv1 = modinv(p1, mod1);
    int modinv2 = modinv(p2, mod2);
    
    hash1[0].second = hash2[0].second = 1;
    for(int i = 1; i < N; i++){
        hash1[i].second = (hash1[i-1].second * modinv1) % mod1;
        hash2[i].second = (hash2[i-1].second * modinv2) % mod2;
    }
}

vector<pair<int, int>> hashing(string& s){
    int len = s.length();
    vector<pair<int, int>> hashVec(len+1);
    hashVec[0].first = N;
    hashVec[0].second = N;
    for(int i = 1; i <= len; i++){
        hashVec[i].first = (hashVec[i-1].first + (s[i-1] * hash1[i-1].first) % mod1) % mod1;
        hashVec[i].second = (hashVec[i-1].second + (s[i-1] * hash2[i-1].first) % mod2) % mod2;
    }
    return hashVec;
}

pair<int, int> getHash(vector<pair<int, int>>& hashVec, int i, int j){
    pair<int, int> ret;
    ret.first = (hashVec[j+1].first - hashVec[i].first + mod1) % mod1;
    ret.first = (ret.first * hash1[i].second) % mod1;
    ret.second = (hashVec[j+1].second - hashVec[i].second + mod2) % mod2;
    ret.second = (ret.second * hash2[i].second) % mod2;
    return ret;
}

int find_number_of_pattern_matches(string str, string pattern){
    int cnt = 0;
    int lenStr = str.length(), lenPattern = pattern.length();
    vector<pair<int, int>> hashStr = hashing(str);
    vector<pair<int, int>> hashPattern = hashing(pattern);
    pair<int, int> patternHash = getHash(hashPattern, 0, lenPattern-1);

    for(int i = 0; i <= lenStr-lenPattern; i++){
        pair<int, int> stringHash = getHash(hashStr, i, i+lenPattern-1);
        if(stringHash.first == patternHash.first && stringHash.second == patternHash.second){
            cnt++;
        }
    }
    return cnt;
}

signed main()
{
    hashPrecalc();
    cout << find_number_of_pattern_matches("heythere", "there") << "\n";
    cout << find_number_of_pattern_matches("amikikorebashkoriboeghorerehayretuiseamarmon", "re") << "\n";
    cout << find_number_of_pattern_matches("ababababab", "abab") << "\n";
    return 0;
}