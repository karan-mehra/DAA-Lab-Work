//Author Karan Mehra
// Week-01 Problem 03
/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] <
key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):
Jump Search
*/
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int jumpSearch(int *a, int n, int key){
    int i=0,j=2;
    int comp=0;
    while(comp++ && a[j]<=key && j<n){
        if(a[j]==key){
            cout << "Present ";
            return j;
        }
        i=j;
        j*=2;
        if(j>=n){
            j=n-1;
        }
    }
    for(int k=i; k<=j; k++,comp++){
        if(a[k]==key){
            cout << "Present ";
            return j;
        }  
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
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int key;
        cin >> key;
        cout << jumpSearch(a,n,key) << endl;
    }
    return 0;
}
