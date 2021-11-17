// By Karan Mehra
#include<bits/stdc++.h>

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
    clock_t begin_69 = clock();
    fast_io;
    int n; cin >> n;
    n++;
    vvi adj(n, vi(n));
    rep(i, 1, n) {
        rep(j, 1, n) {
            cin >> adj[i][j];
        }
    }
    int sc; cin >> sc;
    vi dis(n, N);
    vi par(n);

    multiset<pii> s;
    s.insert({0, sc});
    dis[sc] = 0;

    while(!s.empty()) {
        auto p = *(s.begin());
        s.erase(p);

        rep(i, 1, n) {
            if(adj[p.ss][i]) {
                if(dis[i] > dis[p.ss] + adj[p.ss][i]) {
                    par[i] = p.ss;
                    s.erase({dis[i], i});
                    dis[i] = dis[p.ss] + adj[p.ss][i];
                    s.insert({dis[i], i});
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
