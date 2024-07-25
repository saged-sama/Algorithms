#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5+6;
bool isPrime[N];
vector <int> primes;

// unnecessarily optimized sieve
void sieve_of_eratosthenes(){
    for(int i = 2; i < N; i++){
        isPrime[i] = true;
    }
    for(int i = 4; i < N; i += 2){
        isPrime[i] = false;
    }
    for(int i = 3; i*i < N; i += 2){
        if(isPrime[i]){
            for(int j = i*i; j < N; j += i+i){
                isPrime[j] = false;
            }
        }
    }

    // include this when you need the complete list of primes
    for(int i = 0; i < N; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}

// this is as good as the one above
void sieve(){
    for(int i = 2; i < N; i++){
        isPrime[i] = true;
    }
    
    for(int i = 2; i < N; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i; j <= N; j += i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    sieve();
    for(auto prime: primes){
        cout << prime << " ";
    }
    cout << "\n";
    return 0;
}