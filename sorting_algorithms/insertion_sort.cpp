#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& A){
    int n = A.size();    
    for(int i = 0; i < n; ++i){
        int temp = A[i];
        auto it = lower_bound(A.begin(), A.begin()+i, A[i]);        
        for(int p = i; p > it-A.begin(); p--){
            A[p] = A[p-1];
        }
        A[it-A.begin()] = temp;
    }    
}

int main(){
    vector<int> input = {0,45,5,12,67,8,12,6,88,12,16};
    insertion_sort(input);
    for(int i : input)
        cout << i << " ";
    return 0;
}