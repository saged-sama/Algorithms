#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3e5+6;
const long long int MOD = 1e9+7;
bool isPrime[N];
vector <int> primes;
vector <int> phi(N);

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

// this is the most standard way of calculating phi
int euler_phi_v1(int n){
    vector<pair<int, int>> factorization_of_n = prime_factorization(n);
    int d = n;
    for(auto p_div: factorization_of_n){
        d /= p_div.first;
        d *= p_div.first - 1;
    }
    return d;
}

// this is the ugly way of calculating phi
int euler_phi_v2(int n){
    vector<pair<int, int>> factorization_of_n = prime_factorization(n);
    int d = 1;
    for(auto p_div: factorization_of_n){
        d *= ((int) recursive_big_mod(p_div.first, p_div.second-1)) * (p_div.first - 1);
    }
    return d;
}

// no need to use the prime_factorization function here
// this needs sieve to calculate the primes
// also can be done without knowing the primes
int euler_phi_while_factorizing(int n){
    int d = n;
    for(auto prime: primes){
        if(prime * prime > n){
            break;
        }
        if(n % prime == 0){
            d /= prime;
            d *= prime-1;
        }
        while(n % prime == 0) n /= prime;
    }
    
    if(n > 1) {
        d /= n;
        d *= n-1;
    }
    return d;
}

// may also be done without the help of sieve of eratosthenes
int euler_phi_without_sieve(int n){
    int d = n;
    for(int i = 2; i*i <= n; i++){
        int power = 0;
        if(n % i == 0){ 
            d /= i;
            d *= i-1;
        }
        while(n % i == 0) n /= i;
    }
    if(n > 1) {
        d /= n;
        d *= n-1;
    }
    return d;
}

int __gcd(int a, int b){
    if(b == 0) return a;
    return __gcd(b, a % b);
}

// brute force is beautiful
int brute_force_euler_phi(int n){
    int d = 0;
    for(int i = 1; i <= n; i++){
        if(__gcd(n, i) == 1){
            d++;
        }
    }
    return d;
}

// this is the best approach to calculate the phi of all numbers upto a certain limit
void euler_phi_of_all_numbers(){
    for(int i = 1; i < N; i++) phi[i] = i;
    
    for(int i = 2; i < N; i++){
        if(phi[i] == i){
            for(int j = i; j < N; j += i){
                phi[j] /= i;
                phi[j] *= i-1;
            }
        }
    }
}

int main(){
    sieve_of_eratosthenes(N-1);
    int n = 72726;
    cout << brute_force_euler_phi(n) << "\n";
    cout << euler_phi_v1(n) << "\n";
    cout << euler_phi_v2(n) << "\n";
    cout << euler_phi_while_factorizing(n) << "\n";
    cout << euler_phi_without_sieve(n) << "\n";
    euler_phi_of_all_numbers();
    cout << phi[n] << "\n";
    return 0;
}