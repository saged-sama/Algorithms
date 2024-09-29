#include <bits/stdc++.h>
#define int long long int
using namespace std;

string numToString(int num){
    string ret = "";
    while(num){
        ret.append(to_string(num % 10));
        num /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

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

string divide(string largeNum, int num){
    string result = "";
    int carry = 0;
    for (int i = 0; i < largeNum.size(); i++){
        int dividend = carry * 10 + (largeNum[i] - '0');
        result.push_back('0' + dividend / num);
        carry = dividend % num;
    }

    while (result.size() > 1 && result[0] == '0') result.erase(0, 1);

    return result;
}

int remainder(string largeNum, int num){
    int carry = 0;
    for (int i = 0; i < largeNum.size(); i++){
        int dividend = carry * 10 + (largeNum[i] - '0');
        carry = dividend % num;
    }
    return carry;
}

int gcd(string a, int b){
    if(b == 0){
        return stoi(a);
    }
    return gcd(to_string(b), remainder(a, b)); 
}

string lcm(string a, int b){
    return product(divide(a, gcd(a, b)), b);
}

signed main()
{
    string a = "0";
    int b = 0;

    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl;
    return 0;
}