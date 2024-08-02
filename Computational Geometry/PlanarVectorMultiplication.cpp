#include <iostream>
#include <complex>

#define X real()
#define Y imag()

using namespace std;

long long int cross_product(complex<long long int> a, complex<long long int> b){
    return (conj(a) * b).Y;
}

long long int dot_product(complex<long long int> a, complex<long long int> b){
    return (conj(a) * b).X;
}

bool is_clockwise(complex<long long int> a, complex<long long int> b){
    return cross_product(a, b) < 0;
}

int main() {
    complex<long long int> a(1, 5), b(2, 4);
    cout << cross_product(a, b) << "\n";
    cout << dot_product(a, b) << "\n";
    cout << is_clockwise(a, b) << "\n";
    return 0;
}
