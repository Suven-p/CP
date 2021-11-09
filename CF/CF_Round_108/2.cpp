#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

map<pair<ll , ll>, set<ll>> dp;

set<ll> solve(ll n, ll m) {
    auto key = mp(n, m);
    auto is_computed = dp.find(key);
    if (is_computed != dp.end()) {
        return dp[key];
    }
    if (n < 1 || m < 1) {
        return {-1};
    }
    auto opt1 = solve(n-1, m);
    auto opt2 = solve(n, m-1);
    set<ll> ans;
    for (auto opt: opt1) {
        if (opt != -1) {
            ans.insert(opt + m);
        }
    }
    for (auto opt: opt2) {
        if (opt != -1) {
            ans.insert(opt + n);
        }
    }
    dp[key] = ans;
    return dp[key];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    dp[{1, 1}] = {0};

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        ll n, m, k;
        cin >> n >> m >> k;
        auto possible_costs = solve(n, m);
        auto possible = possible_costs.find(k) != possible_costs.end();
        cout << ((possible)? "YES": "NO") << endl;
    }

    return 0;
}