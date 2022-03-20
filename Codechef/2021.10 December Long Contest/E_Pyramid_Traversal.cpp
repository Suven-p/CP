#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#pragma GCC optimize "trapv"
#define TEST
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define mp make_pair
#define FOR(i, j, k, inc) for (int i=j ; i<k ; i+=inc)
#define REP(i, n) for(int i=0; i < n; i++)
#ifdef TEST
    #define debug(x...) cerr << #x << x << endl;
#else
    #define debug(x...)
#endif

constexpr ll MOD = 1e9 + 7;
ll row_start[50000], row_end[50000];
map<pair<int, int>, ll> memo;
ll count_ = 0;
ll solve(ll start, ll end) {
    if (memo.find({start, end}) != memo.end()) return memo[{start, end}];
    count_++;
    auto start_row = distance(row_start, lower_bound(row_start, row_start + 45000, start));
    auto end_row = distance(row_end, lower_bound(row_end, row_end + 45000, end));
    if (start_row >= end_row) {
        memo[{start, end}] = 0;
        return memo[{start, end}];
    }
    auto end_col = end - row_start[end_row];
    auto val1 = row_start[end_row - 1] + end_col;
    auto val2 = row_start[end_row - 1] + end_col - 1;
    if (val1 == start || val2 == start) {
        memo[{start, end}] = 1;
        return memo[{start, end}];
    }
    if (end_col == 0) {
        memo[{start, end}] = solve(start, val1) % MOD;
        return memo[{start, end}];
    }
    if (end == row_end[end_row]) {
        memo[{start, end}] = solve(start, val2) % MOD;
        return memo[{start, end}];
    }
    memo[{start, end}] = ((solve(start, val1) % MOD) + (solve(start, val2) % MOD) % MOD);
    return memo[{start, end}];
}
int main() {
#ifdef TEST
    freopen("/media/nevus/Data/CP/input.in", "r", stdin);
    freopen("/media/nevus/Data/CP/output.out", "w", stdout);
    freopen("/media/nevus/Data/CP/output.out", "w", stderr);
        auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;
    row_start[0] = 1;
    for(int i = 0; i < 45000; i++) {
        row_end[i] = i * (i + 1) / 2;
        row_start[i + 1] = row_end[i] + 1;
    }
    for (int numTest = 1; numTest <= totalTests; numTest++) {
        ll start, end;
        cin >> start >> end;
        if (start >= end) {
            cout << 0 << endl;
            continue;
        }
        cout << solve(start, end) << endl;
    }
    cout << "Count: " << count_ << endl;
    cout << memo.size() << endl;

#ifdef TEST
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        cout << "Time taken by program is : " << endl << fixed
             << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}
