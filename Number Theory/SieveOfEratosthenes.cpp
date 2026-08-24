#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5+6;
bool isPrime[N];
vector <int> primes;

int lp[N];
vector <int> lpPrimes;

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

void linearSieve(){
    for(int i = 2; i <= N; i++){
        if(lp[i] == 0){
            lp[i] = i;
            lpPrimes.push_back(i);
        }
        for(int j = 0; i * lpPrimes[j] <= N; j++){
            lp[i * lpPrimes[j]] = lpPrimes[j];
            if(lpPrimes[j] == lp[i]){
                break;
            }
        }
    }
}

int main(){
    sieve();
    // for(auto prime: primes){
    //     cout << prime << " ";
    // }
    // cout << "\n";

    linearSieve();
    // for(auto prime: lpPrimes){
    //     cout << prime << " ";
    // }
    // cout << "\n";

    cout << primes.size() << " " << lpPrimes.size() << "\n";

    for(int i = 0; i < lpPrimes.size(); i++){
        if(primes[i] != lpPrimes[i]){
            cout << "Blunder\n";
        }
    }
    return 0;
}