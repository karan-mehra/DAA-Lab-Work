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

int Matrix_chainMul(vi &a, int i, int j) {
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;

    rep(k, i, j) {
        dp[i][j] = min(dp[i][j], Matrix_chainMul(a, i, k) + Matrix_chainMul(a, k + 1, j) + (a[i - 1] * a[k] * a[j]));
    }
    return dp[i][j];
}

void solve() {
    int n; cin >> n;
    n++;
    vi a(n);
    dp = vvi(n, vi(n, -1));
    
    rep(i, 1, n) {
        int x, y; cin >> x >> y;
        if(i == 1) a[i - 1] = x;
        a[i] = y;
    }
    
    cout << Matrix_chainMul(a, 1, n - 1) << endl;
}

int main() {
    fast_io;
    solve();
    return 0;
}