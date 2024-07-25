#include <iostream>
#include <cstring>
using namespace std;

void countingSort(int * begin, int * end){
    int mx = INT_MIN;
    for(int * i = begin; i < end; i++) mx = max(mx, *i);
    int count[mx+1]; memset(count, 0, sizeof(count));
    for(int * i = begin; i < end; i++) count[*i]++;
    for(int i = 1; i <= mx; i++) count[i] += count[i-1];
    int sortedArray[end-begin];
    for(int * i = end-1; i >= begin; i--) sortedArray[--count[*i]] = *i;
    for(int * i = begin; i < end; i++) *i = *(sortedArray+(i-begin));
}

int main()
{
    int n; cin >> n;
    int array[n];
    for(int i = 0; i < n; i++) cin >> array[i];
    countingSort(array, array+n);
    for(int i = 0; i < n; i++) cout << array[i] << " "; cout << "\n";
    return 0;
}