#include <bits/stdc++.h>
using namespace std;

vector<double>::iterator partition(vector<double>::iterator begin, vector<double>::iterator end){
    vector<double>::iterator pivot = begin-1;
    for(vector<double>::iterator i = begin; i < end; i++){
        if((*i) < (*end)) swap(*i, *(++pivot));
    }
    swap(*(++pivot), *end);
    return pivot;
}

void quickSort(vector<double>::iterator begin, vector<double>::iterator end){
    if(begin < end){
        vector<double>::iterator pivot = partition(begin, end);
        quickSort(begin, pivot-1);
        quickSort(pivot+1, end);
    }`
}

void bucketSort(double * begin, double * end, int number_of_buckets){
    double mx = *max_element(begin, end);
    double mn = *min_element(begin, end);
    double bucket_size = (mx - mn + 1.0)/((double)number_of_buckets);
    vector<double> bucket[number_of_buckets+1];
    for(double * i = begin; i < end; i++){
        bucket[(int)(((*i)-mn)/bucket_size)].push_back(*i);
        // cout << "Element " << *i << " goes to bucket no " << (int)(((*i) - mn)/bucket_size) << endl;
    }
    for(int i = 0; i < number_of_buckets; i++){
        if(bucket[i].size() > 0){
            quickSort(bucket[i].begin(), bucket[i].end()-1);
        }
    }
    double * k = begin;
    for(int i = 0; i <= number_of_buckets; i++){
        if(bucket[i].size() > 0){
            for(auto item: bucket[i]){
                *(k++) = item;
            }
        }
    }
}

int main()
{
    int n; cin >> n;
    double ara[n];
    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }
    bucketSort(ara, ara+n, 10);
    for(int i = 0; i < n; i++){
        cout << ara[i] << " ";
    }
    cout << "\n";
    return 0;
}