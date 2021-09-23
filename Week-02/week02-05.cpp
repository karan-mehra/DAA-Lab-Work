//Author Karan Mehra
// Week-02 Problem 02
/*
Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].
*/
#include<bits/stdc++.h>
#define ll long long
#define Vi vector<int>
#define mod 1000000007
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int binarySearch(int *a,int n,int key){
    int start=0;
    int end=n-1;
    int comp=0;
    while(start<=end){
        comp++;
        int mid=start + (end-start)/2;
        if(a[mid]==key){
            return mid; 
        }
        else if(a[mid]>key){
            end=mid-1;
        }
        else start=mid+1;
    }
    return 0;
}
void solve(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(int k=binarySearch(a,n,a[i]+a[j])){
                cout << i<<", "<<j<<", "<<k<<endl;
                return;
            }
        }
    }
    cout << "No sequence found"<<endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
