#include <bits/stdc++.h>
using namespace std;

void merge(int * begin, int * end){
    int ara[end-begin+1];
    int * beginner = begin;
    int * mid = begin+(end-begin)/2;
    int * ender = mid+1;
    int k = 0;
    while(beginner <= mid and ender <= end){
        if(*beginner <= *ender){
            ara[k++] = *(beginner++);
        }
        else{
            ara[k++] = *(ender++);
        }
    }
    while(beginner <= mid) ara[k++] = *(beginner++);
    while(ender <= end) ara[k++] = *(ender++);
    for(int i = 0; i < k; i++){
        *(begin++) = ara[i];
    }
}

void mergeSort(int * begin, int * end){
    if(begin == end) return;
    int * mid = begin+(end-begin)/2;
    mergeSort(begin, mid);
    mergeSort(mid+1, end);
    merge(begin, end);
}

int main()
{
    int n; cin >> n;
    int ara[n];
    for(int i = 0; i < n; i++) cin >> ara[i];
    mergeSort(ara, ara+3);
    for(int i = 0; i < n; i++) cout << ara[i] << " ";
    cout << "\n";
    return 0;
}