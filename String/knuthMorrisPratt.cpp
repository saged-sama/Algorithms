#include <iostream>
#include <vector>
#include <string>
using namespace std;

// this one's mine
void lpsForString(string& s, int lps[]){
    int len = s.length();

    for(int i = 0; i < len; i++){
        lps[i] = 0;
    }

    int pos = 0, i = 1;
    while(i < len){
        if(s[i] == s[pos]){
            lps[i] = ++pos;
            i++;
        }
        else{
            if(pos == 0){
                i++;
            }
            else{
                pos = lps[pos-1];
            }
        }
    }
}

// pi function or LPS function by Mridul bhai
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int kmp(string& s, string& pattern){
    int len = s.length();
    int ln = pattern.length();
    int lps[ln];
    lpsForString(pattern, lps);

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
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        string s; cin >> s;
        string pattern; cin >> pattern;
        cout << "Case " << t << ": " << kmp(s, pattern) << "\n";
    }
    return 0;
}