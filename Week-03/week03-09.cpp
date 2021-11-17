//Author Karan Mehra
/*
Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n))
*/
#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int i,int j){
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int part(int *a,int l,int h){
    int i=l-1;
    for(int j=l;j<=h;j++){
        if(a[j]<=a[h]){
            i++;
            swap(a,i,j);
        }
    }
    return i;
}

void sort(int *a, int l,int h){
    if(l<h){
        int pi=part(a,l,h);
        sort(a,0,pi-1);
        sort(a,pi+1,h);
    }
}

bool solve(){
    int n;
    cin >> n;
    int *a= new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a,0,n-1);

    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        if(solve()){
            cout << "YES"<<endl;
        }
        else cout << "NO"<<endl;
    }
    return 0;
}
