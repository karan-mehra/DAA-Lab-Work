//Author Karan Mehra
/*
Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n))
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
    char *a=new char[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> count(26,0);

    for(int i=0;i<n;i++){
        count[a[i]-'a']++;
    }

    int max=0;
    int maxIndex=-1;
    for(int i=0;i<26;i++){
        if(count[i]>1 && count[i]>max){
            max=count[i];
            maxIndex=i;
        }
    }
    if(max>1){
        cout << char(maxIndex+97)<<"-"<<max<<endl;
        return;
    }
    cout << "No Duplicate Present"<<endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
