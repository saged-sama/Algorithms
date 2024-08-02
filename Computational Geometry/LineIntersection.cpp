#include <iostream>
#include <complex>
#include <climits>
#include <algorithm>
#include <utility>

#define ctype double
#define point complex<ctype>
#define x real()
#define y imag()

#define line pair<point, point>
#define p1 first
#define p2 second

const ctype eps = 1e-9;

using namespace std;

point intersection(line line1, line line2){
    point a = line1.p1, b = line1.p2, c = line2.p1, d = line2.p2;
    point denominator = (conj(a) - conj(b)) * (c - d) - (a - b) * (conj(c) - conj(d));
    if(abs(denominator.x) < eps && abs(denominator.y) < eps){
        return {LLONG_MAX*1.0, LLONG_MAX*1.0};
    }
    point numerator = (conj(a) * b - a * conj(b)) * (c - d) - (a - b) * (conj(c) * d - c * conj(d));
    return numerator / denominator;
}

int main()
{
    complex<ctype> a(0, 2), b(4, 6), c(8, 4), d(4, 2); 
    cout << intersection({a, b}, {c, d}) << endl;
    return 0;
}