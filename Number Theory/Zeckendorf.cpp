#include <iostream>
#include <vector>
using namespace std;

const long long int N = 88;
long long int fib[N];

long long int fibonacci(long long int n){
    if(fib[n] > 0) return fib[n];
    if(n == 0) return fib[0] = 0;
    if(n == 1) return fib[1] = 1;
    return fib[n] = (fibonacci(n-1) + fibonacci(n-2));
}

vector<long long int> Zeckendorf(long long int n){
    vector<long long int> zeck_of_n;
    while(n){
        long long int z = lower_bound(fib, fib + N, n) - fib;
        if(fib[z] > n){
            z--;
        }
        zeck_of_n.push_back(fib[z]);
        n -= fib[z];
    }
    return zeck_of_n;
}

void print_vector(vector<long long int> vec){
    int len = vec.size();
    for(int i = 0; i < len; i++){
        if(i == len-1){
            cout << vec[i] << "\n";
        }
        else {
            cout << vec[i] << " + ";
        }
    }
}

int main(){
    fibonacci(N-1);
    int n = 209000;
    vector<long long int> zeck_of_n = Zeckendorf(n);
    cout << n << " = ";
    print_vector(zeck_of_n);
    return 0;
}