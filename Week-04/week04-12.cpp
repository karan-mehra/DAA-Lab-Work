//Author Karan Mehra
/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
*/
#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin >> n;
    int *a= new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int k;
    cin >> k;

    priority_queue<int> maxHeap;    
    for(int i=0;i<n;i++){
        maxHeap.push(a[i]);
        if(maxHeap.size()>k){
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve()<<endl;
    }
    return 0;
}
