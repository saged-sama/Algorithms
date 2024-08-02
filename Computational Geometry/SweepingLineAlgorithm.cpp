// CPP data structures can be sooooo nightmarish when it comes to readability
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int maximum_number_of_overlapping_segments(vector<pair<int, int>> &segments){
    vector<pair<int, int>> events;
    for (auto segment: segments){
        events.push_back({segment.first, 1});
        events.push_back({segment.second, -1});
    }
    sort(events.begin(), events.end());
    int max_overlapping = 0, overlapping = 0;
    for (auto event: events){
        overlapping += event.second;
        max_overlapping = max(max_overlapping, overlapping);
    }
    return max_overlapping;
}

// finds the total number of intersection points of a set of segments
// all of which are either vertical or horizontal
int total_intersection_points(vector<pair<pair<int, int>, pair<int, int>>> &segments){
    vector<pair<int, pair<int, pair<int, int>>>> events;
    for (auto segment: segments){
        // if segment is vertical
        if(segment.first.first == segment.second.first){
            events.push_back({segment.first.first, {3, {segment.first.second, segment.second.second}}});
        }
        // if segment is horizontal
        else{
            events.push_back({segment.first.first, {1, {segment.first.second, segment.second.second}}});
            events.push_back({segment.second.first, {2, {segment.first.second, segment.second.second}}});
        }
    }
    sort(events.begin(), events.end());
    multiset<int> active_horizontal_segments;
    int total_intersection = 0;
    for(auto event: events){
        if(event.second.first == 1){
            active_horizontal_segments.insert(event.second.second.first);
        }
        else if(event.second.first == 2){
            active_horizontal_segments.erase(active_horizontal_segments.find(event.second.second.first));
        }
        else{
            total_intersection += distance(active_horizontal_segments.lower_bound(event.second.second.first), active_horizontal_segments.upper_bound(event.second.second.second));
        }
    }
    return total_intersection;
}

int main()
{
    vector<pair<int, int>> segments = {{10, 15}, {6, 12}, {14, 16}, {5, 13}};
    cout << maximum_number_of_overlapping_segments(segments) << endl;
    
    vector<pair<pair<int, int>, pair<int, int>>> allsegments = {
        {{-2, 0}, {3, 0}},
        {{0, -1}, {0, 4}},
        {{-1, 2}, {4, 2}},
        {{4, 1}, {8, 1}},
        {{6, 0}, {6, 3}}
    };
    cout << total_intersection_points(allsegments) << endl;
    return 0;
}