// Author : Karan Mehra

#include<bits/stdc++.h>

#define ll long long int
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

int n, sc;
vvi adj;

int solve() {
    vector<bool> vis(n + 1, 0);
    multiset<pii> s;

    vi dis(n + 1, N);

    dis[1] = 0;
    vis[1] = 1;
    rep(i, 1, n + 1) {
        if(adj[1][i] && !vis[i] && adj[1][i] < dis[i]) {
            s.insert(mp(adj[1][i], i));
            dis[i] = adj[1][i];
        }
    }

    int roads = n - 1;
    int cost = 0;

    while(roads--) {
        pii p = *(s.begin());
        s.erase(p);
        vis[p.ss] = 1;
        cost += p.ff;

        rep(i, 1, n + 1) {
            if(adj[p.ss][i] && !vis[i] && adj[p.ss][i] < dis[i]) {
                s.erase({dis[i], i});
                s.insert(mp(adj[p.ss][i], i));
                dis[i] = adj[p.ss][i];
            }
        }

    }
    return cost;
}

int main() {
    fast_io;

    cin >> n;
    adj = vvi(n + 1, vi(n + 1));

    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            cin >> adj[i][j];
        }
    }
    cout << "Minimum Spanning Weight: " << solve() << endl; 
    return 0;
}