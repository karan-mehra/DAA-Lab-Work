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

int n;
vvi adj;

vi parent(N);
vi sz(N);

void make_set(int x) {
    parent[x] = x;
    sz[x] = 1;
}

int find_set(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if(a == b) {
        return;
    }
    if(sz[a] < sz[b]) {
        swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
}

int solve() {
    int cost = 0;

    vvi Weight;
    rep(i, 1, n + 1) {
        rep(j, i, n + 1) {
            if(adj[i][j]) {
                Weight.pb({i, j, adj[i][j]});
            }
        }
    }

    sort(all(Weight), [&](vi a, vi b){
        return a[2] < b[2]; 
    });


    for(auto &it: Weight) {
        int a = find_set(it[0]);
        int b = find_set(it[1]);
        if(a == b) {
            continue;
        }

        cost += it[2];
        union_set(it[0], it[1]);
    }

    return cost;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;

    cin >> n;

    rep(i, 1, n + 1) {
        make_set(i);
    }
    adj = vvi(n + 1, vi(n + 1));
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            cin >> adj[i][j];
        }
    }
    cout << "Minimum Spanning Weight: " << solve() << endl;
    return 0;
}