//Author Karan Mehra
/*
You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int *a1=new int[n];
    for(int i=0;i<n;i++){
        cin >> a1[i];
    }
    int m;
    cin >> m;
    int *a2=new int[m];
    for(int i=0;i<m;i++){
        cin >> a2[i];
    }
    sort(a1, a1 + n);
    sort(a2, a2 + m);

    int i=0,j=0;
    while(i<n && j<m){
        if(a1[i]==a2[j]){
            cout << a2[j]<<" ";
            i++;
            j++;
        }
        else if(a1[i]>a2[j]){
            j++;
        }
        else{
            i++;
        }
    }
}

int main(){
    solve();
    return 0;
}
