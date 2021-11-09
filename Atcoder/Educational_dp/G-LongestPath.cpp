#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int> edges[], int current, vector<int> &memo) {
    if (memo[current] != -1) {
        return memo[current];
    }
    if (edges[current].size() == 0) {
        memo[current] = 0;
        return memo[current];
    }
    int ans = -10e8;
    for (auto c:edges[current]) {
        ans = max(ans, solve(edges, c, memo) + 1);
    }
    memo[current] = ans;
    return memo[current];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    // cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int N, M;
        cin >> N >> M;
        vector<int> edges[N+1];
        int x, y;
        for (int i=0; i < M; i++) {
            cin >> x >> y;
            edges[x].push_back(y);
        }
        vector<int> memo(N + 1, -1);
        int ans = -10e7;
        for (int i=1; i <= N; i++) {
            ans = max(ans, solve(edges, i, memo));
        }
        cout << ans << endl;
    }

    return 0;
}