#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 2e18;



bool check_med(const int mid, const int n, const int k, vector<ll>& a){
    vector<int> diff(n);
    int cnt_bigger{0};
    for (int i{0}; i<n; ++i){
        if (a[i] < mid) diff[i]=-1;
        else {
            diff[i] = 1;
            cnt_bigger++;
        }
    }

    vector<int> pref(n+1);
    pref[0]=0;
    for (int i{1}; i<=n; ++i) pref[i] = pref[i-1] + diff[i-1];

    int minn = pref[0];
    for (int i{k}; i<=n; ++i){
        minn = min(minn, pref[i-k]);
        if(pref[i] - minn > 0) return 1;
    }
    
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n{0}, k{0};
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& el : a) cin >> el;   

    ll l{0}, r{n}, mid{0};
    ll med{0};
    while(l<=r){
        mid = (l+r)/2;
        if (check_med(mid, n, k, a)){
            med = mid;
            l = mid+1;
        }
        else r = mid - 1;
    }

    cout<<med<<"\n";

    return 0;
}