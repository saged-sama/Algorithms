#include <bits/stdc++.h>
using namespace std;

string product(string largeNum, int num){
    string result = "";
    int carry = 0;
    for (int i = largeNum.size() - 1; i >= 0; i--){
        int product = (largeNum[i] - '0') * num + carry;
        result.push_back('0' + product % 10);
        carry = product / 10;
    }
    while (carry){
        result.push_back('0' + carry % 10);
        carry /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string largeNum = "130";
    int num = 13;
    cout << product(largeNum, num) << endl;
    return 0;
}