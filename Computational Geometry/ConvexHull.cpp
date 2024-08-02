#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

#define ctype long long int
#define point complex<ctype>
#define x real()
#define y imag()

using namespace std;

ctype cross_product(complex<ctype> a, complex<ctype> b){
    return (conj(a) * b).y;
}

bool is_clockwise(complex<ctype> a, complex<ctype> b){
    return cross_product(a, b) < 0;
}

vector<point> convex_hull(vector<point> &points){
    int n = points.size();
    if(n <= 3){
        return points;
    }
    sort(points.begin(), points.end(), [](point a, point b){
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });

    vector<point> top_hull;
    top_hull.push_back(points[0]);
    top_hull.push_back(points[1]);
    for(int i = 2; i < n; i++){
        while(top_hull.size() >= 2 && !is_clockwise(top_hull[top_hull.size() - 1] - top_hull[top_hull.size() - 2], points[i] - top_hull[top_hull.size() - 1])){
            top_hull.pop_back();
        }
        top_hull.push_back(points[i]);
    }

    vector<point> bottom_hull;
    bottom_hull.push_back(points[0]);
    bottom_hull.push_back(points[1]);
    for(int i = 2; i < n; i++){
        while(bottom_hull.size() >= 2 && is_clockwise(bottom_hull[bottom_hull.size() - 1] - bottom_hull[bottom_hull.size() - 2], points[i] - bottom_hull[bottom_hull.size() - 1])){
            bottom_hull.pop_back();
        }
        bottom_hull.push_back(points[i]);
    }

    vector<point> hull = top_hull;
    for(int i = bottom_hull.size() - 2; i > 0; i--){
        hull.push_back(bottom_hull[i]);
    }
    
    return hull;
}

int main()
{
    vector<point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    vector<point> hull = convex_hull(points);
    
    for(auto p : hull){
        cout << p.x << " " << p.y << "\n";
    }
    return 0;
}