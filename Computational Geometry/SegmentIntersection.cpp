#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

#define X real()
#define Y imag()

using namespace std;

long long int cross_product(complex<long long int> a, complex<long long int> b){
    return (conj(a) * b).Y;
}

int point_location(complex<long long int> a, complex<long long int> b, complex<long long int> p){
    long long int cp = cross_product(p - a, p - b);
    if(cp > 0) return -1; //left
    if(cp < 0) return 1;  //right
    return 0;             //on the segment
}

// check if two segments intersect
// two segments are intersecting if the endpoints of one segment are either on the opposite sides of or on the other segment
bool segment_intersection(complex<long long int> a, complex<long long int> b, complex<long long int> c, complex<long long int> d){
    if(point_location(a, b, c) != point_location(a, b, d) && point_location(c, d, a) != point_location(c, d, b)){
        return true; 
    }
    return false;
}

int main(){
    complex<long long int> a, b, c, d;
    a = {2, 2};
    b = {10, 8};
    c = {10, 3};
    d = {6, 5};
    cout << segment_intersection(a, b, c, d) << endl;
    return 0;
}