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
vvi a;
int wt;

int main() {
    fast_io;

    cin >> n;
    a = vvi(n + 1, vi(3));
    rep(i, 1, n + 1) cin >> a[i][0];
    rep(i, 1, n + 1) cin >> a[i][1], a[i][2] = i;
    cin >> wt;

    sort(all(a), [&](vi x, vi y) {
        return (float)x[1] / x[0] > (float)y[1] / y[0];
    });

    float ans = 0;
    vector<pii> selected_item;
    rep(i, 1, n + 1) {
        if(a[i][0] <= wt) {
            ans += a[i][1];
            wt -= a[i][0];
            selected_item.pb({a[i][2], a[i][0]});
        }else {
            float vpw = (float)a[i][1] / a[i][0];
            ans += (vpw * wt);
            selected_item.pb({a[i][2], wt});
            wt = 0;
            break;
        }
    }

    cout << "Maximum value : " << fixed << setprecision(2) << ans << endl;
    cout << "item-weight: " << endl;
    for(auto &it: selected_item) {
        cout << it.ff << "-" << it.ss << endl;
    }
    return 0;
}