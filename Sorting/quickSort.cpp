#include <iostream>
using namespace std;

int * partition(int * begin, int * end){
    int * pivot = begin-1;
    for(int * j = begin; j < end; j++){
        if(*j < *end) swap(*(++pivot), *j);
    }
    swap(*(++pivot), *end);
    return pivot;
}

void quick_sort(int * begin, int * end){
    if(begin < end){
        int * pivot = partition(begin, end);
        quick_sort(begin, pivot-1), quick_sort(pivot+1, end);
    }
}

void quickSort(int * begin, int * end){
    quick_sort(begin, end-1);
}

int main()
{
    int n; cin >> n;
    int array[n];
    for(int i = 0; i < n; i++) cin >> array[i];
    quickSort(array, array+n);
    for(int i = 0; i < n; i++) cout << array[i] << " "; cout << "\n";
    return 0;
}