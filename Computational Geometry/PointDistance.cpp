#include <iostream>
#include <complex>
#include <iomanip>

#define X real()
#define Y imag()

using namespace std;

long double cross_product(complex<long double> a, complex<long double> b){
    return (conj(a) * b).Y;
}

long double point_distance(complex<long double> a, complex<long double> b, complex<long double> p){
    return abs(cross_product(a-p, b-p)/abs(a-b));
}

int main(){
    complex<long double> a(1.0, 5.0), b(2.0, 4.0), c(10.0, 3.0);
    cout << fixed << setprecision(6) << point_distance(a, b, c) << "\n";
    return 0;
}