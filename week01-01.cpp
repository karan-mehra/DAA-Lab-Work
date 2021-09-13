// Author Karan Mehra
// Week-01 Problem 01
/* 
Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)
*/
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vecto<int>>
#define N 10000
#define mod 1000000007
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int linearSearch(int *a,int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            cout << "Present ";
            return i+1;
        }
    }
    cout << "Not Present ";
    return n;
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
        
        cout << linearSearch(a,n,key)<<endl;
    }
    return 0;
}
