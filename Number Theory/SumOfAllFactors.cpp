#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5+6;
const int MOD = 1e9+7;
bool isPrime[N];
vector <int> primes;
long long int sum_of_divs[N];

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

long long int recursive_big_mod(long long int n, long long int p){
    if(p == 0) return 1ll;
    long long int ret = recursive_big_mod(n, p >> 1);
    ret = (ret * ret) % MOD;
    if(p & 1){
        ret = (ret * n) %  MOD;
    }
    return ret;
}

long long int recursive_exponentiation(long long int n, long long int p){
    if(p == 0) return 1ll;
    long long int ret = recursive_exponentiation(n, p >> 1);
    ret = ret * ret;
    if(p & 1){
        ret = ret * n;
    }
    return ret;
}

// when all of the factors are known, then this function is coolest
// this uses modular inverse, this is especially useful when the sum is very large
long long int sum_of_all_factors_from_prime_factorization(vector<pair<int, int>> factorization){
    long long int sum = 1;
    for(auto p_factor: factorization){
        sum = (sum * ((recursive_big_mod(p_factor.first, (p_factor.second + 1) % (MOD-1)) - 1 + MOD) % MOD)) % MOD;
        sum = (sum * recursive_big_mod(p_factor.first-1, MOD-2)) % MOD;
    }
    return sum;
}

// when the sum is not that large, no need to mod
long long int sum_of_all_factors_from_prime_factorization_without_modular_inverse(vector<pair<int, int>> factorization){
    long long int sum = 1;
    for(auto p_factor: factorization){
        sum *= (recursive_exponentiation(p_factor.first, p_factor.second + 1) - 1)/(p_factor.first - 1);
    }
    return sum;
}

// this is the most standard "easy approach" with a good complexity of sqrt(n)
// this is the best implementation in all cases; unless the factorization is given
long long int sum_without_prime_factorization(int n){
    long long int sum = 0;
    for(int i = 1; i * i <= n; i++){
        if(i*i == n){
            sum += i;
        }
        else if(n % i == 0){
            sum += i + n/i;
        }
    }
    return sum;
}

// best for calculating sum of all divisors of every number upto a certain limit
void sum_of_all_factors_of_all_numbers(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            sum_of_divs[j] += i;
        }
    }
}

int main()
{
    sieve_of_eratosthenes(N-1);
    int n = 100000;
    cout << sum_without_prime_factorization(n) << "\n";
    cout << sum_of_all_factors_from_prime_factorization(prime_factorization(n)) << "\n";
    cout << sum_of_all_factors_from_prime_factorization_without_modular_inverse(prime_factorization(n)) << "\n";
    sum_of_all_factors_of_all_numbers();
    cout << sum_of_divs[n] << "\n";
    return 0;
}