// Author Karan Mehra
// Week-01 Problem 02
/* 
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(logn), where n is the size of input).
*/
#include<bits/stdc++.h>
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
            cout << "Present ";
            return comp; 
        }
        else if(a[mid]>key){
            end=mid-1;
        }
        else start=mid+1;
    }
    cout << "Not Present ";
    return comp;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int *a=new int[n];
        rep(i,0,n)  cin >> a[i];
        
        int key;
        cin >> key;
        
        cout << binarySearch(a,n,key)<<endl;
    }
    return 0;
}

