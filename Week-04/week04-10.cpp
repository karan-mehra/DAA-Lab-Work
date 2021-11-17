//Author Karan Mehra
/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array.
*/
#include<bits/stdc++.h>
using namespace std;

void merge(int *a,int l,int mid,int h,int& comp,int& inversion){
    int n1=mid-l+1;
    int n2=h-mid;
    int *a1=new int[n1];
    int *a2=new int[n2];
    for(int i=0;i<n1;i++){
        a1[i]=a[l+i];
    }
    for(int i=0;i<n2;i++){
        a2[i]=a[mid+i+1];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            a[k]=a1[i];
            i++;
        }
        else if(a1[i]>a2[j]){
            a[k]=a2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=a2[j];
        j++;
        k++;
    }
}

void sort(int *a,int l,int h,int& comp,int& inversion){
    if(l<h){
        int mid=l+(h-l)/2;
        sort(a,l,mid,comp,inversion);
        sort(a,mid+1,h,comp,inversion);
        merge(a,l,mid,h,comp,inversion);
    }
}
void solve(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int comp=0,inversion=0;
    sort(a,0,n-1,comp,inversion);
    for(int i=0;i<n;i++){
        cout << a[i]<<" ";
    }
    cout << endl<< comp <<" "<<inversion << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
