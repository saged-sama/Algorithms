#include <iostream>
#include <complex>
#include <vector>

#define ctype double
#define X real()
#define Y imag()

const ctype MAXN = 1e5 + 5;
const ctype e = 1e-9;

using namespace std;

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

    ctype area(){
        int n = this->vertices.size();
        ctype area = 0;
        for(int i = 0, j = n - 1; i < n; j = i++){
            area += cross_product(this->vertices[j], this->vertices[i]);
        }
        return abs(area)/2.0;
    }
};

int main()
{
    vector<complex<ctype>> vertices = {{4, 4}, {0, 0}, {-4, -2}, {-5, 0}, {-6, 4}, {-3, 2}};
    Polygon polygon(vertices);
    cout << polygon.area() << "\n";
    return 0;
}