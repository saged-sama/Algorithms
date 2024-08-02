#include <iostream>
#include <complex>

#define X real()
#define Y imag()

using namespace std;

long long int cross_product(complex<long long int> a, complex<long long int> b){
    return (conj(a) * b).Y;
}

int point_location(complex<long long int> a, complex<long long int> b, complex<long long int> p){
    long long int cp = cross_product(p - a, p - b);
    if(cp > 0) return -1; // left
    if(cp < 0) return 1;  // right
    return 0;             // on the line
}

int main() {
    complex<long long int> a(1, 5), b(2, 4), c(10, 3);
    cout << point_location(a, b, c) << "\n";
    return 0;
}