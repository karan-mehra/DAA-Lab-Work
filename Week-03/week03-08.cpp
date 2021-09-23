//Author Karan Mehra
/*
Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.
*/
#include<bits/stdc++.h>
#define ll long long
#define Vi vector<int>
#define mod 1000000007
#define rep(i,a,b) for(int i=a;i<b;i++)
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
    for(int i=0;i<n;i++){
        int minIdx=i;
        for(int j=i;j<n;j++){
            if(++comp && a[minIdx]>a[j]){
                minIdx=j;
            }
        }
        swap(a,minIdx,i,swaps);
    }

    for(int i=0;i<n;i++){
        cout<< a[i]<<" ";
    }
    cout << endl << "Comparisons:" << comp;
    cout << endl << "Swaps:"<<swaps;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
