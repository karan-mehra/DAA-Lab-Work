// Author : Karan mehra
#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1e5 + 10;
const int mod = 1e9;

vvi dp;

int No_of_ways(vi &a, int n, int x) {
    if(x == 0) return 1;

    if(x < 0 || n <= 0) return 0;

    if(dp[n][x] != -1) return dp[n][x];

    dp[n][x] = No_of_ways(a, n - 1, x) + No_of_ways(a, n, x - a[n - 1]);
    return dp[n][x];
}

void solve() {
    int n; cin >> n;
    vi a(n);

    rep(i, 0, n) {
        cin >> a[i];
    }
    int x; cin >> x;

    dp = vvi(n + 1, vi(x + 1, -1));
    
    cout << No_of_ways(a, n, x) << endl;
}

int main() {
    fast_io;
    solve();
    
    return 0;
}