#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 2e18;

void solve(const ll n, const ll m, const vector<ll>&a){
    ll x{0};

    vector<ll> circle(2*n);
    for (int i{0}; i<n; ++i) {
        circle[i] = a[i];
        circle[i+n] = a[i]+m;
    }

    vector<ll>pref(2*n +1,0);
    for (int i{0}; i<2*n; ++i)
        pref[i+1] = circle[i]+ pref[i];

    ll ans{INF};
    for (int i{0}; i<n; ++i) {
        ll l = i, r= i+n-1, mid = l+n/2;
        ll l_cnt = mid-l, r_cnt = r-mid;

        ll left_cost = (l_cnt * circle[mid]) - (pref[mid] - pref[l]);
        ll right_cost = pref[r + 1] - pref[mid + 1] - (r_cnt * circle[mid]);

        ans = min(ans,left_cost + right_cost);
    }
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{0};
    cin >> t;
    while (t--) {
        ll n{0}, m{0};
        cin >> n >> m;
        vector<ll> a(n);
        for (auto&el : a) cin>>el;
        for (auto&el : a) el=el%m;
        sort(a.begin(), a.end());
        solve(n,m,a);
    }
    return 0;
}