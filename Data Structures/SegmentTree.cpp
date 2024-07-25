#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+4;
const int maxTreeSize = 4*N;
class SegmentTree{
private:
    int * array;
    void buildTree(int node, vector<int> vec, int start, int end);
public:
    SegmentTree(vector<int> vec);
};

SegmentTree::SegmentTree(vector<int> vec){
    array = new int[4*vec.size()];
    memset(array, 0, sizeof(array));
    buildTree(1, vec, 0, vec.size()-1);
}

void SegmentTree::buildTree(int node, vector<int> vec, int start, int end){
    
}