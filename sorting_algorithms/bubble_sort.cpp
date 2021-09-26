#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& A){
    int n = A.size();
    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(A[j] > A[j+1])
                swap(A[j], A[j+1]);
        }
    }
}

int main(){
    vector<int> input = {5,1,3,68,9,1,2,23};
    bubble_sort(input);
    for(auto i : input)
        cout << i << " ";
    return 0;
}