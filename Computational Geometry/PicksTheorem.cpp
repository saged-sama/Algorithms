#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

#define ctype int
#define X real()
#define Y imag()

using namespace std;

ctype number_of_lattice_points_on_a_line(complex<ctype> a, complex<ctype> b){
    // linear diophantine equation
    return __gcd(abs(a.X - b.X), abs(a.Y - b.Y)) + 1;
}

long long int cross_product(complex<long long int> a, complex<long long int> b){
    return (conj(a) * b).Y;
}

class Polygon{
  public:
    vector<complex<ctype>> vertices;
    
    Polygon(vector<complex<ctype>>& vertices){
        for(auto p: vertices){
            this->vertices.push_back(p);
        }
    }

    ctype area_times_2(){
        int n = this->vertices.size();
        ctype area = 0;
        for(int i = 0, j = n - 1; i < n; j = i++){
            area += cross_product(this->vertices[j], this->vertices[i]);
        }
        return abs(area);
    }

    ctype boundary(){
        int n = this->vertices.size();
        // the vertices are counted twice
        ctype boundary = -n;
        for(int i = 0, j = n - 1; i < n; j = i++){
            boundary += number_of_lattice_points_on_a_line(this->vertices[j], this->vertices[i]);
        }
        return boundary;
    }

    ctype number_of_lattice_points_inside_polygon(){
        // picks theorem: Area = i + b/2 - 1 => i = (2*Area - b + 2)/2
        return (this->area_times_2() - this->boundary() + 2)/2;
    }
};

int main() {
    complex<ctype> a(0, 0), b(-4, -2);
    cout << number_of_lattice_points_on_a_line(a, b) << "\n";

    vector<complex<ctype>> vertices = {{4, 4}, {0, 0}, {-4, -2}, {-5, 0}, {-6, 4}, {-3, 2}};
    Polygon polygon(vertices);
    cout << polygon.number_of_lattice_points_inside_polygon() << "\n";
    return 0;
}