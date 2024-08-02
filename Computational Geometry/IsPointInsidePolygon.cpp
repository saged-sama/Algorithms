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

int point_location(complex<long long int> a, complex<long long int> b, complex<long long int> p){
    long long int cp = cross_product(p - a, p - b);
    if(cp > 0) return -1; // left
    if(cp < 0) return 1;  // right
    return 0;             // on the line
}

// check if two segments intersect
// two segments are intersecting if the endpoints of one segment are either on the opposite sides of or on the other segment
bool segment_intersection(complex<long long int> a, complex<long long int> b, complex<long long int> c, complex<long long int> d){
    if(point_location(a, b, c) != point_location(a, b, d) && point_location(c, d, a) != point_location(c, d, b)){
        return true; 
    }
    return false;
}

class Polygon{
  public:
    vector<complex<ctype>> vertices;
    
    Polygon(vector<complex<ctype>>& vertices){
        for(auto p: vertices){
            this->vertices.push_back(p);
        }
    }

    bool is_inside(complex<ctype> P){
        int n = this->vertices.size();
        bool inside = false;
        complex<ctype> ref = {MAXN, MAXN};
        for(int i = 0, j = n - 1; i < n; j = i++){
            // if point lies on the same line as the side
            if(point_location(vertices[i], vertices[j], P) == 0){
                // if point is on the side or not
                return abs(abs(P-vertices[i]) + abs(P-vertices[j]) - abs(vertices[i]-vertices[j])) < e;
            }
            // if vertex lies on the arbitrary line
            if(point_location(ref, P, vertices[i]) == 0){
                complex<ctype> prev = ((i == 0) ? vertices[n - 1] : vertices[i - 1]);
                complex<ctype> next = ((i == n - 1) ? vertices[0] : vertices[i + 1]);
                // check if the adjacent vertices are on the same side of the line
                if(point_location(ref, P, prev) != point_location(ref, P, next)){
                    inside = !inside;
                }
            }
            // if the line intersects the side
            else if(segment_intersection(ref, P, vertices[i], vertices[j])){
                inside = !inside;
            }
        }
        return inside;
    }
};

int main()
{
    vector<complex<ctype>> vertices = {{4, 4}, {0, 0}, {-4, -2}, {-5, 0}, {-6, 4}, {-3, 2}};
    Polygon polygon(vertices);
    complex<ctype> P = {-3, 2};
    cout << polygon.is_inside(P) << "\n";
    return 0;
}