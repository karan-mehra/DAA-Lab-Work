// Author Karan Mehra
// Week-02 Problem 01
/*
Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
*/
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vecto<int>>
#define N 10000
#define mod 1000000007
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
void solve(){
    int n;
    cin >> n;
    
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int key;
    cin >> key;
    int start=0;
    int end=n-1;
    int firstOcc=-1;
    while(start<=end){
        int mid=start + (end-start)/2;
        if(a[mid]==key){
            firstOcc=mid;
            end=mid-1;
        }
        else if(a[mid]>key){
            end=mid-1;
        }
        else start=mid+1;
    }
    int LastOcc=-1;
    start=0;
    end=n-1;
    if(firstOcc==-1){
        cout << "Key Not Present ";
        return;
    }
    else{
        while(start<=end){
            int mid=start + (end-start)/2;
            if(a[mid]==key){
                LastOcc=mid;
                start=mid+1;
            }
            else if(a[mid]>key){
                end=mid-1;
            }
            else start=mid+1;
        }
    }
    cout<<key<<" - "<<LastOcc-firstOcc+1;
    return;
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}
