//By Karan Mehra
#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

const int N = 1e5;

int main() {
    fast_io;
    int n; cin >> n;
    n++;
    vvi adj(n, vi(n));
    int edge = 0;
    rep(i, 1, n) {
        rep(j, 1, n) {
            cin >> adj[i][j];
            if(adj[i][j]) edge++;
        }
    }
    int sc; cin >> sc;
    vi dis(n, N);
    vi par(n);

    dis[sc] = 0;

    edge--;
    while(edge--) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                if(adj[i][j] and dis[j] > dis[i] + adj[i][j]) {
                    dis[j] = dis[i] + adj[i][j];
                    par[j] = i;
                }
            }
        }
    }

    vvi ans(n);
    rep(i, 1, n) {
        ans[i].pb(i);
        int tmp = i;
        while(tmp != sc) {
            ans[i].pb(par[tmp]);
            tmp = par[tmp];
        }
    }
    rep(i, 1, n) {
        for(auto it: ans[i]) {
            cout << it << " ";
        }cout << ": " << dis[i] << endl;
    }
    return 0;
}
