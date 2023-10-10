#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& vec, int start, int end)
{
    int pivot = start;
    for(int i = start; i < end; i++){
        if(vec[i] < vec[end]){
            swap(vec[pivot], vec[i]);
            pivot++;
        }
    }
    swap(vec[pivot], vec[end]);
    return pivot;
}

int quickselect(vector<int>& vec, int start, int end, int k){
    if(start == end){
        return vec[start];
    }
    int pivot = partition(vec, start, end);
    if(k == pivot){
        return vec[pivot];
    }
    if(k < pivot){
        return quickselect(vec, start, pivot-1, k);
    }
    return quickselect(vec, pivot+1, end, k);
}

int main()
{
    int n; cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    int k; cin >> k;
    cout << quickselect(vec, 0, n-1, k-1) << "\n";
    for(auto v: vec){
        cout << v << " ";
    }
    return 0;
}
