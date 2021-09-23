//Author Karan Mehra
/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
*/
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vecto<int>>
#define N 10000
#define mod 1000000007
#define rep(i,a,b) for(int i=a;i<b;i++)
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
