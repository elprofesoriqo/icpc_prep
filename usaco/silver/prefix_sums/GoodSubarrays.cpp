#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t{0};
    cin >> t;

    while (t--) {
        int n{0};
        cin >> n;
        string s;
        cin>>s;

        vector<int> pref(n+1);
        pref[0] = 0;

        map<int, ll> freq;
        freq[0] = 1;

        ll ans{0};
        for (int i{0}; i < n; ++i) {
            int curr_val = pref[i] + (s[i] - '0') - 1;
            pref[i + 1] = curr_val;
            ans += freq[curr_val]++; 
        }

        cout << ans << "\n";
    }
    return 0;
}