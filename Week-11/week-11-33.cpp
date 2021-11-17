// Author : Karan Mehra

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

vvi dp;

bool two_sets(vi &a, int n, int sum) {
    if(sum == 0) return 1;

    if(sum < 0 || n <= 0) return 0;
    if(two_sets(a, n - 1, sum) || two_sets(a, n - 1, sum - a[n - 1]))
        return 1;

    return 0;
}

void solve() {
    int n; cin >> n;
    vi a(n);

    int sum = 0;
    rep(i, 0, n) {
        cin >> a[i];
        sum += a[i];
    }
    
    if(sum % 2 == 0 && two_sets(a, n, sum / 2)) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main() {
    fast_io;
    solve();
    return 0;
}