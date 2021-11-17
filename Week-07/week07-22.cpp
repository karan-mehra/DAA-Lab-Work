// By Karan Mehra
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

using namespace std;
const int N = 1e5;
vvi adj;
int sc, ds;
int n;
int ans = N;

bool DFS(int node, int k, int wt) {
    if(k < 0) {
        return false;
    }
    if(k == 0) {
        if(node == ds) {
            ans = min(ans, wt);
            return true;
        }
        return false;
    }
    bool f = false;
    rep(i, 1, n) {
        if(adj[node][i] and DFS(i, k - 1, wt + adj[node][i])) {
            f = true;
        }
    }
    if(f) return true;
    return false;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    cin >> n;
    n++;
    adj = vvi(n, vi(n));
    int edge = 0;
    rep(i, 1, n) {
        rep(j, 1, n) {
            cin >> adj[i][j];
        }
    }
    cin >> sc >> ds;
    int k; cin >> k;

    if(DFS(sc, k, 0)) {
        cout << "Weight of shortest path from (" << sc << ", " << ds << ") with " << k << " edges : " << ans << endl;
    }else {
        cout << "no path of length " << k << " is available." << endl;
    }
    return 0;
}
