#include <bits/stdc++.h>
using namespace std;

int merge_em(vector<int>& vec, int start, int mid, int end){
    int i = start, j = mid+1;
    int cnt = 0;
    vector<int> v(end - start + 1);
    int idx = 0;
    while(i <= mid and j <= end){
        if(vec[i] > vec[j]){
            cnt += mid - i + 1;
            v[idx++] = vec[j++];
        }
        else{
            v[idx++] = vec[i++];
        }
    }
    while(i <= mid){
        v[idx++] = vec[i++];
    }
    while(j <= end){
        v[idx++] = vec[j++];
    }
    for(int k = start; k <= end; k++){
        vec[k] = v[k-start];
    }
    return cnt;
}

int inv_count(vector<int>& vec, int n, int start, int end){
    if(start == end){
        return 0;
    }
    int mid = (start + end)/2;
    int cnt1 = inv_count(vec, n, start, mid);
    int cnt2 = inv_count(vec, n, mid+1, end);
    int cnt = merge_em(vec, start, mid, end);
    return cnt + cnt1 + cnt2;
}

int main()
{
    int n; cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    cout << inv_count(vec, n, 0, n-1) << "\n";
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
    return 0;
}
