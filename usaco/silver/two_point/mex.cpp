#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 2e18;

void solve(ll n, vector<ll>& p) {
    ll ans{0};
    ll mex{0};
    vector<ll> pos(n+1);
    for(int i{0}; i<n; i++) pos[p[i]] = i;
    
    ll l{pos[0]}, r{pos[0]};

    while(++mex < n){
        
        ll curr_l{0}, curr_r{0};
        ll rng = 2LL * mex - (r - l + 1);
        if (rng >= 0){
            if (pos[mex] < l) {
                curr_l = min((ll)rng, l - pos[mex] - 1);
                curr_r = min((ll)rng, (n - 1) - r);
            } else if (pos[mex] > r) {
                curr_l = min((ll)rng, l - 0);
                curr_r = min((ll)rng, pos[mex] - 1 - r);
            } else continue;
        

            ll curr_ans{1LL * (curr_l+1) * (curr_r+1)};
            if (curr_l + curr_r - rng > 0)
                curr_ans-= (curr_l + curr_r - rng) * (curr_l + curr_r - rng + 1) / 2;
            ans += curr_ans;
        }
    
        l = min(l, pos[mex]);
        r = max(r, pos[mex]);

    }
    cout << ++ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t{0};
    cin >> t;
    while (t--) {
        ll n{0};
        cin >> n;
        vector<ll> p(n);
        for (auto& el : p) cin >> el;
        solve(n,p);
    }
    return 0;
}