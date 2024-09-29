#include <bits/stdc++.h>
using namespace std;

string product(string num1, string num2){
    int n = num1.size();
    int m = num2.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0; j--){
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = product + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    
    string res = "";
    for (int i = 0; i < result.size(); i++){
        if (res.empty() && result[i] == 0) continue;
        res += to_string(result[i]);
    }
    return res.empty() ? "0" : res;
}

int main()
{
    string num1 = "13";
    string num2 = "20";

    cout << product(num1, num2) << endl;
    return 0;
}