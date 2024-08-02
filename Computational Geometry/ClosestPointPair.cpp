#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <cmath>

#define int long long int
#define point pair<int, int>
#define x first
#define y second

const int N = 1e7;

using namespace std;

int distance_squared(point a, point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// codeforces https://codeforces.com/blog/entry/58747
pair<point, point> closest_point_pair(vector<point> &points){
    sort(points.begin(), points.end());
    int min_distance = LLONG_MAX;
    pair<point, point> closest_pair;

    set<pair<int, int>> s;

    for(int i = 0, j = 0; i < points.size(); i++){
        while(j < i && (points[i].x - points[j].x)*(points[i].x - points[j].x) >= min_distance){
           s.erase({points[j].y, points[j].x});
           j++;
        }

        auto start = s.lower_bound({points[i].y - ceil(sqrt(min_distance)), points[i].x});
        auto end = s.upper_bound({points[i].y + ceil(sqrt(min_distance)), points[i].x});

        for(auto it = start; it != end; it++){  
            int dist = (points[i].x - it->second)*(points[i].x - it->second) + (points[i].y - it->first)*(points[i].y - it->first);
            if(dist < min_distance){
                min_distance = dist;
                closest_pair = {points[i], {it->second, it->first}};
            }
        }
        s.insert({points[i].y, points[i].x});
    }
    return closest_pair;
}

pair<point, point> closest_point_pair_brute_force(vector<point> points){
    int min_distance = LLONG_MAX;
    pair<point, point> closest_pair;
    for(int i = 0; i < points.size(); i++){
        for(int j = i + 1; j < points.size(); j++){
            int dist = distance_squared(points[i], points[j]);
            if(dist < min_distance){
                min_distance = dist;
                closest_pair = {points[i], points[j]};
            }
        }
    }
    return closest_pair;
}

signed main(){
    return 0;
}
