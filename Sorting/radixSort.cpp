// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;

// void countingSort(string * begin, string * end, int idx){
//     int count[10]; memset(count, 0, sizeof(count));
//     for(string * i = begin; i < end; i++){
//         int len = (*i).length();
//         if(len-idx < 0) count[0]++;
//         else count[(*i)[len-idx]-'0']++;
//     }
//     for(int i = 1; i < 10; i++) count[i]+=count[i-1];
//     string sortedString[end-begin];
//     for(string * i = end-1; i >= begin; i--) {
//         int len = (*i).length();
//         if(len - idx < 0) *(sortedString+(--count[0])) = *i;
//         else *(sortedString+(--count[(*i)[len-idx]-'0'])) = *i;
//     }
//     for(string * i = begin; i < end; i++) *i = *(sortedString+(i-begin));
// }

// void radixSort(string * begin, string * end){
//     int mx = 0;
//     for(string * i = begin; i < end; i++)
//         if(mx < (int)(*i).length()) mx = (int)(*i).length();
//     for(int i = 1; i <= mx; i++) countingSort(begin, end, i);
// }

// int main(){
//     int n; cin >> n;
//     string s[n];
//     for(int i = 0; i < n; i++) cin >> s[i];
//     radixSort(s, s+n);
//     for(int i = 0; i < n; i++) cout << s[i] << " "; cout << "\n";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void countingSort(int * begin, int * end, int mod){
    int modbyten = mod/10;
    int cnt[10]; memset(cnt, 0, sizeof(cnt));
    for(int * i = begin; i < end; i++){
        int digit = ((*i)%mod)/modbyten;
        // cout << digit << endl;
        cnt[digit]++;
    }
    for(int i = 1; i < 10; i++) cnt[i] += cnt[i-1];
    int sortedAra[end-begin];
    for(int * i = end-1; i >= begin; i--){
        int digit = ((*i)%mod)/modbyten;
        sortedAra[--cnt[digit]] = *i;
        // cout << *i << " ";
    }
    for(int * i = begin; i < end; i++) *i = sortedAra[i-begin];
}

void radixSort(int * begin, int * end){
    int mx = *max_element(begin, end);
    int lgMax = 2;
    while(mx){
        lgMax++;
        mx/=10;
    }
    int mod = 10;
    for(int i = 1; i <= lgMax; i++) {
        countingSort(begin, end, mod);
        mod *= 10;
    }
}

int main()
{
    int n; cin >> n;
    int ara[n];
    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }
    radixSort(ara, ara+n);
    for(int i = 0; i < n; i++) cout << ara[i] << " "; cout << "\n";
    return 0;
}