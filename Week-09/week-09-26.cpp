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
const int INF = 1e9;

int n;
vvi adj;

int main() {
    fast_io;
    cin >> n;
    adj = vvi(n + 1, vi(n + 1, INF));

    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            string a; cin >> a;
            if(a != "INF") {
                adj[i][j] = stoi(a);
            }
        }
    }

    vvi dis = adj;

    rep(k, 1, n + 1) {
        rep(i, 1, n + 1) {
            rep(j, 1, n + 1) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cout << "Shortest Distance Matrix:" << endl;
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            if(dis[i][j] >= INF) cout << "INF ";
            else cout << dis[i][j] << " ";
        }cout << endl;
    }
    return 0;
}