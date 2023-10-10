#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

bool compx(Point A, Point B){
    return A.x < B.x;
}

bool compy(Point A, Point B){
    return A.y < B.y;
}

int dist(Point A, Point B){
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

pair<Point, Point> closest_among_three(Point A, Point B, Point C){
    int dst1 = dist(A, B);
    int dst2 = dist(B, C);
    int dst3 = dist(C, A);

    int mn = min(dst1, min(dst2, dst3));

    if(mn == dst1) return {A, B};
    if(mn == dst2) return {B, C};
    return {C, A};
}

pair<Point, Point> closest(vector<Point>& point, int start, int end){
    if(start == end-1){
        return {point[start], point[end]};
    }
    if(start == end-2){
        return closest_among_three(point[end], point[end-1], point[end-2]);
    }

    int mid = (start + end)/2;
    pair<Point, Point> p1 = closest(point, start, mid);
    pair<Point, Point> p2 = closest(point, mid+1, end);

    int dist1 = dist(p1.first, p1.second);
    int dist2 = dist(p2.first, p2.second);
    int d = min(dist1, dist2);

    vector<Point> strip;
    for(int i = start; i <= end; i++){
        if(dist(point[i], point[mid]) < d) strip.push_back(point[i]);
    }
    sort(strip.begin(), strip.end(), compy);

    int sxz = strip.size();

    pair<Point, Point> ret;
    if(d == dist1) ret = p1;
    else ret = p2;

    for(int i = 0; i < sxz; i++){
        for(int j = i+1; j < sxz and j <= i + 7; j++){
            int dst = dist(point[i], point[j]);
            if(dst < d){
                ret = {point[i], point[j]};
                d = dst;
            }
        }
    }

    strip.clear();

    return ret;
}

int main()
{
    int n; cin >> n;
    
    vector<Point> point(n);
    for(int i = 0; i < n; i++){
        cin >> point[i].x >> point[i].y;
    }

    sort(point.begin(), point.end(), compx);

    pair<Point, Point> clos = closest(point, 0, n-1);

    cout << sqrt(dist(clos.first, clos.second)*1.0) << "\n";

    cout << clos.first.x << " " << clos.first.y << "\n";
    cout << clos.second.x << " " << clos.second.y << "\n";

    return 0;
}
