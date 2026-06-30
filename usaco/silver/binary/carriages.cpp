#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 2e18;


bool can_setup(ll mid, ll n, const vector<ll>&a, const vector<ll> &d){
    priority_queue<
        pair<ll, ll>, 
        vector<pair<ll, ll>>, 
        greater<pair<ll, ll>>
        > pq;
        
        
    vector<vector<pair<ll, ll>>> rng(n);
    for (int i{0}; i<n; ++i){
        if (a[i] > 0) {
            ll L = max(0LL, (ll)i - d[i]);
            ll R = min((ll)n - 1, (ll)i + d[i]);
            rng[L].push_back({R, a[i]});
        }
    }
    

    for (int i{0}; i<n; ++i){
        for (auto& carr : rng[i]) pq.push(carr);

        ll free = mid;

        while(free > 0 && !pq.empty()){
            auto top = pq.top();
            pq.pop();

            if (top.first < i) return false;

            ll take = min(free, top.second);
            free -= take;
            top.second -= take;

            if (top.second > 0) pq.push({top.first, top.second});
        }
        
        if (!pq.empty() && pq.top().first == i) return false;
    }
    if (pq.empty()) return true;
    else return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n{0};
    cin>>n;

    vector<ll> a(n);
    vector<ll> d(n);
    for (auto&el: a) cin>>el;
    for (auto&el: d) cin>>el;
    
    ll z{0};
    ll l{0}, r{*std::ranges::max_element(a)};
    ll mid{0};
    while(l<=r){
        mid = (l+r)/2;

        if(can_setup(mid,n,a,d)){
            r = mid - 1; 
            z = mid;
        }
        else l = mid + 1;
    }

    cout<<z<<"\n";

    return 0;
}