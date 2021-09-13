//Author Karan Mehra
/* Week02 : problem 03
Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.
*/
#include<bits/stdc++.h>
#define ll long long
#define Vi vector<int>
#define mod 1000000007
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int solve(){
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(a[i]-a[j])==k){
                count++;
            }
        }
    }
    return count;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve()<< endl;
    }
    return 0;
}
