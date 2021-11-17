// Author Karan Mehra
// Week-01 Problem 01
#include<bits/stdc++.h>

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
        for(int i=0;i<n;i++)  cin >> a[i];
        
        int key;
        cin >> key;
        
        cout << linearSearch(a,n,key)<<endl;
    }
    return 0;
}
