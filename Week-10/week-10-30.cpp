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

class activity {
    public:
        int amt, dd, no;
};

void solve() {
    int n; cin >> n;
    vector<activity> a(n);

    rep(i, 0, n) {
        cin >> a[i].amt;
        a[i].no = i + 1;
    }
    rep(i, 0, n) {
        cin >> a[i].dd;
    }

    sort(all(a), [&](activity x, activity y) {
        return x.dd > y.dd;
    });

    vi ans; ans.pb(a[0].no);

    int rem = a[0].dd - a[0].amt;
    rep(i, 1, n) {
        if(rem >= a[i].dd) {
            ans.pb(a[i].no);
            rem -= a[i].amt;
        }
    }

    sort(all(ans));
    cout << "Max number of tasks = " << ans.size() << endl;
    cout << "Selected task numbers : ";
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ((i != ans.size() - 1) ? ", " : "\n");
}

int main() {
    fast_io;
    solve();
    
    return 0;
}