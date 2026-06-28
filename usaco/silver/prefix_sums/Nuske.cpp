#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 2e18;

void solve(const ll x1, const ll y1, const ll x2, const ll y2, const vector<vector<ll>>& S){
    ll ans{0};

    for(int i={x1}; i <= x2; ++i){
        int cnt_1{0};
        for(int j={y1}; j <= y2; ++j){
            if (S[i][j] == 1) {
                cnt_1++;
                ans++;
                if(cnt_1>1) ans--;
                if (i > x1 && S[i-1][j] == 1) ans--;
            }else{
                cnt_1 = 0;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N{0}, M{0}, Q{0};
    cin >> N >> M >> Q;
    vector<vector<ll>> S(N, vector<ll>(M));
    for(int i = 0; i < N; ++i){
        string row;
        cin >> row;
        for(int j = 0; j < M; ++j)
            S[i][j] = row[j] - '0';
    }

    while(Q--){
        ll x1{0}, y1{0}, x2{0}, y2{0};
        cin >> x1 >> y1 >> x2 >> y2;
        vector<vector<ll>> grid;
        grid.reserve(x2 - x1 + 1);
        for (int i = x1 - 1; i <= x2-1; ++i)
            grid.emplace_back(S[i].begin() + y1-1, S[i].begin() + y2);
        
        solve(0, 0, x2 - x1, y2 - y1, grid);
        }

    return 0;
}