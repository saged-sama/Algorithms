#include <bits/stdc++.h>
using namespace std;

string divide(string largeNum, int num){
    string result = "";
    int carry = 0;
    bool nonZero = false;
    for (int i = 0; i < largeNum.size(); i++){
        int dividend = carry * 10 + (largeNum[i] - '0');
        if (dividend >= num) nonZero = true;
        if(nonZero) 
            result.push_back('0' + dividend / num);
        carry = dividend % num;
    }

    return result;
}

int main()
{
    string largeNum = "170";
    int num = 13;

    cout << divide(largeNum, num) << endl;

    return 0;
}