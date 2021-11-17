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

void solve() {
    int n; cin >> n;
    priority_queue<int> max_heap;
    unordered_map<int, int> mp;
    int ans = -1;
    rep(i, 0, n) {
        int a; cin >> a;
        mp[a]++;
        if(mp[a] > n / 2) ans = a;
        max_heap.push(a);
        if(max_heap.size() > n / 2 + 1) {
            max_heap.pop();
        }
    }
    if(ans != -1) cout << "yes" << endl;
    else cout << "no" << endl;

    if(n % 2 == 0) {
        ans = max_heap.top(), max_heap.pop();
        ans += max_heap.top(), max_heap.pop();
        ans /= 2;
        cout << ans << endl;
        return;
    }
    ans = max_heap.top(), max_heap.pop();
    cout << ans << endl;
}

int main() {
    fast_io;
    solve();
    return 0;
}