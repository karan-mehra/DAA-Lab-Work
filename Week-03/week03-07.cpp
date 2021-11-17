
//Author Karan Mehra
// Week-03 Problem 01
/*
Given an unsorted array of integers, design an algorithm and a program to sort the array using
insertion sort. Your program should be able to find number of comparisons and shifts ( shifts -
total number of times the array elements are shifted from their place) required for sorting the
array.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void swap(int *a,int i,int j,int& swaps){
    swaps++;
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void solve(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int swaps=0;
    int comp=0;
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            comp++;
            a[j+1]=a[j];
            j--;
        }
        swaps++;
        a[j+1]=key;
    }
    for(int i=0;i<n;i++){
        cout << a[i]<<" ";
    }
    cout << endl << "Comparisons:" << comp;
    cout << endl << "Swaps:" << swaps;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
