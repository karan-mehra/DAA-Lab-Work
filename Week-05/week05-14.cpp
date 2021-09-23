//Author Karan Mehra
/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n))
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
    int k;
    cin >> k;

    sort(a,a+n);

    int i=0;
    int j=n-1;
    while(i<=j){
        int sum=a[i]+a[j];
        if(sum==k){
            cout << a[i] <<","<<a[j]<<endl;
            return;
        }
        else if(sum<k){
            i++;
        }
        else{
            j--;
        }
    }
    cout << "No Such Element Exist"<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
