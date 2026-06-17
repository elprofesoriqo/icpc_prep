#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 2e18;

void solve(const int n, const vector<int>& b){
    vector<int> pref(n);
    pref[0] = b[0];
    for (int i{1}; i < n; ++i)
        pref[i] = max(pref[i - 1], b[i] + i);

    vector<int> suff(n);
    suff[n - 1] = b[n - 1] - (n-1);
    for (int i{n-2}; i >= 0; --i) {
        suff[i] = max(suff[i + 1], b[i] - i);
    }

    ll ans{-INF};
    for (int m{1}; m<n-1; ++m)
        ans = max<ll>(ans, pref[m-1] + b[m] + suff[m+1]);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{0};
    cin >> t;
    while (t--) {
        int n{0};
        cin>>n;
        vector<int> b(n);
        for (auto& el : b) cin >> el;
        solve(n,b);
    }
    return 0;
}