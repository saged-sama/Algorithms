#include <bits/stdc++.h>
using namespace std;

void lpsforstring(string s, int lps[]){
    int len = s.length();

    for(int i = 0; i < len; i++){
        lps[i] = 0;
    }

    int pos = 0;

    for(int i = 1; i < len; i++){
        if(s[i] == s[pos]){
            lps[i] = pos+1;
            pos++;
        }
        else if(pos != 0){
            pos--;
            if(s[pos] == s[i]) lps[i] = pos+1;
            else pos = 0;
        }
    }
}

int kmp(string s, string pattern){
    int len = s.length();
    int ln = pattern.length();
    int lps[ln];
    lpsforstring(pattern, lps);

    int cnt = 0;
    int j = -1, i = 0;

    while(i < len){
        if(j == -1 and s[i] != pattern[j+1]){
            i++;
        }
        else if(s[i] == pattern[j+1]){
            i++;
            j++;
            if(j == ln-1){
                j = lps[j]-1;
                cnt++;
            }
        }
        else{
            j = lps[j]-1;
        }
    }
    return cnt;
}

int main()
{
    string s; cin >> s;
    string pattern; cin >> pattern;
    cout << kmp(s, pattern) << "\n";
    return 0;
}
