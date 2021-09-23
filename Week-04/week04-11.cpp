//Author Karan Mehra
/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array.
*/
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vecto<int>>
#define N 10000
#define mod 1000000007
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void swap(int *a,int i,int j){
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int partition(int *a,int l,int h){
    int i=l-1;
    for(int j=l;j<=h;j++){
        if(a[j]<=a[h]){
            i++;
            swap(a,i,j);
        }
    }
    return i;
}

void QS(int *a,int l,int h){
    if(l<h){
        int pi=partition(a,l,h);
        QS(a,l,pi-1);
        QS(a,pi+1,h);
    }
}

void solve(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    QS(a,0,n-1);
    for(int i=0;i<n;i++){
        cout << a[i]<<" ";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
