#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode * bit[2];
    TrieNode(){
        this->bit[0] = this->bit[1] = NULL;
    }

    void insert(char s[], int i){
        if(i == 32) return;
        if(bit[s[i]-'0'] == NULL){
            bit[s[i]-'0'] = new TrieNode();
        }
        bit[s[i]-'0']->insert(s, i+1);
    }

    void searchMax(char s[], int i, char c[]){
        if(i == 32) return;
        int next = s[i]-'0';
        if(bit[1-next] == NULL){
            c[i] = '0';
            bit[next]->searchMax(s, i+1, c);
        }
        else {
            c[i] = '1';
            bit[1-next]->searchMax(s, i+1, c);
        }
    }

    void searchMin(char s[], int i, char c[]){
        if(i == 32) return;
        int next = s[i]-'0';
        if(bit[next] == NULL){
            c[i] = '1';
            bit[1-next]->searchMin(s, i+1, c);
        }
        else{
            c[i] = '0';
            bit[next]->searchMin(s, i+1, c);
        } 
    }

    void exterminate(){
        if(bit[0]) bit[0]->exterminate();
        if(bit[1]) bit[1]->exterminate();
        delete this;
    }
};

void to_binary(int n, char c[]){
    for(int i = 0; i < 32; i++){
        if(n&1) c[i] = '1';
        else c[i] = '0';
        n >>= 1;
    }
    reverse(c, c+32);
}

int to_decimal(char c[]){
    int x = 0;
    for(int i = 0; i < 32; i++){
        x = 2*x + (c[i]-'0');
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; scanf("%d", &T);

    int n, ar, mx, mn, cxor;
    char bin[32];
    char mns[32], mxs[32];

    for(int t = 1; t <= T; t++){
        int n; scanf("%d", &n);
        mx = cxor = 0;
        mn = INT_MAX;

        TrieNode * root = new TrieNode();
        for(int i = 0; i < 32; i++){
            bin[i] = '0';
        }
        to_binary(0, bin);
        root->insert(bin, 0);

        for(int i = 0; i < n; i++){
            for(int i = 0; i < 32; i++){
                bin[i] = '0';
                mxs[i] = '0';
                mns[i] = '0';
            }
            scanf("%d", &ar);

            cxor = cxor ^ ar;
            to_binary(cxor, bin);

            root->searchMax(bin, 0, mxs);
            mx = max(mx, to_decimal(mxs));

            root->searchMin(bin, 0, mns);
            mn = min(mn, to_decimal(mns));

            root->insert(bin, 0);
        }
        printf("Case %d: %d %d\n", t, mx, mn);
        root->exterminate();
    }
    return 0;
}