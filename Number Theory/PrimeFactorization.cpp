#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5+6;
bool isPrime[N];
vector <int> primes;
vector<pair<int, int>> prime_factors[N];

void sieve_of_eratosthenes(int n){
    for(int i = 2; i <= n; i++){
        isPrime[i] = true;
    }
    for(int i = 4; i <= n; i += 2){
        isPrime[i] = false;
    }
    for(int i = 3; i*i <= n; i += 2){
        if(isPrime[i]){
            for(int j = i*i; j <= n; j += i+i){
                isPrime[j] = false;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}

// good if a few numbers need to be factorized
vector<pair<int, int>> prime_factorization(int n){
    vector<pair<int, int>> pfn;

    for(auto prime: primes){
        if(prime * prime > n) break;

        int power = 0;
        while(n % prime == 0){
            n /= prime;
            power++;
        }

        if(power > 0){
            pfn.push_back({prime, power});
        }
    }

    if(n > 1) pfn.push_back({n, 1});
    return pfn;
}

// This approach is better for factorizing all numbers upto a certain range
// Doesn't require sieve_of_eratosthenes
// Uses sieve on the go
void sieve_prime_factorization(){
    for(int i = 2; i < N; i++){
        if(prime_factors[i].size() == 0){
            for(int j = i; j < N; j += i){
                int power = 0;
                int number = j;
                while(number % i == 0){
                    number /= i;
                    power++;
                }
                if(power > 0) prime_factors[j].push_back({i, power});
            }
        }
    }
} 

int main(){
    sieve_of_eratosthenes(N-1);
    sieve_prime_factorization();
    int n = 30030;
    vector<pair<int, int>> prime_fact_of_n = prime_factorization(n);
    for(auto p: prime_fact_of_n){
        cout << p.first << " " << p.second << "\n";
    }
    cout << "\n";
    for(auto p: prime_factors[n]){
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}