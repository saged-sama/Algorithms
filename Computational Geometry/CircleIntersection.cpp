#include <iostream>
#include <complex>

#define ctype double

#define point complex<ctype>
#define x real()
#define y imag()

#define circle pair<ctype, point>
#define r first
#define c second

using namespace std;

ctype length_of_intersection_chord_of_two_circles(circle circle1, circle circle2){
    ctype d = abs(circle1.c - circle2.c);
    ctype r1 = circle1.r, r2 = circle2.r;
    ctype s = (r1 + r2 + d)/2.0;
    ctype area = 2.0 * sqrt(s * (s - r1) * (s - r2) * (s - d));                 // two of these triangles make the kite
    return 2.0 * area / d;                                                      // 0.5 * d * chord = area
}

point intersection_of_the_intersecting_chord_and_the_center_joiner(circle circle1, circle circle2){
    ctype chord = length_of_intersection_chord_of_two_circles(circle1, circle2);
    
    complex<ctype> center_joiner = circle2.c - circle1.c;                       // line that joins the centers
    complex<ctype> chord_line = {center_joiner.y, -center_joiner.x};            // perpendicular to center_joiner

    chord_line /= abs(chord_line);
    center_joiner /= abs(center_joiner);

    return circle1.c + center_joiner * sqrt(circle1.r * circle1.r - chord*chord/4.0);
}

pair<point, point> intersection_of_two_circles(circle circle1, circle circle2){
    ctype chord = length_of_intersection_chord_of_two_circles(circle1, circle2);
    
    complex<ctype> center_joiner = circle2.c - circle1.c;                       // line that joins the centers
    complex<ctype> chord_line = {center_joiner.y, -center_joiner.x};            // perpendicular to center_joiner

    chord_line /= abs(chord_line);
    center_joiner /= abs(center_joiner);

    point intersection_point = circle1.c + center_joiner * sqrt(circle1.r * circle1.r - chord*chord/4.0);

    point p1 = intersection_point + chord_line * chord/2.0;
    point p2 = intersection_point - chord_line * chord/2.0;
    return {p1, p2};
}

int main(){
    circle circle1 = {3, {3, 2}};
    circle circle2 = {2, {-1, 3}};
    cout << length_of_intersection_chord_of_two_circles(circle1, circle2) << endl;
    pair<point, point> intersection = intersection_of_two_circles(circle1, circle2);
    cout << intersection.first.x << " " << intersection.first.y << endl;
    cout << intersection.second.x << " " << intersection.second.y << endl;
    return 0;
}