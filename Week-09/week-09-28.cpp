// Author : karan mehra
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

int n;
vi a;

int main() {
    fast_io;

    cin >> n;
    a = vi(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));

    int pref_sum = a[0];
    int ans = 0;
    rep(i, 1, n) {
        pref_sum += a[i];
        ans += pref_sum;
    }

    cout << ans << endl;
    return 0;
}