#include <bits/stdc++.h>
using namespace std;

int remainder(string largeNum, int num){
    int carry = 0;
    for (int i = 0; i < largeNum.size(); i++){
        int dividend = carry * 10 + (largeNum[i] - '0');
        carry = dividend % num;
    }
    return carry;
}

int main()
{
    string largeNum = "170";
    int num = 13;

    cout << remainder(largeNum, num) << endl;
    return 0;
}