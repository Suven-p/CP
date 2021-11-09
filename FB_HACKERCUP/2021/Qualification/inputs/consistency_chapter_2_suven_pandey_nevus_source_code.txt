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
#define FOR(i, j, k, inc) for (int i = j; i < k; i += inc)
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
#ifdef TEST
    freopen("/media/nevus/data/CP/input.in", "r", stdin);
    freopen("/media/nevus/data/CP/output.out", "w", stdout);
    freopen("/media/nevus/data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        string inputString;
        cin >> inputString;
        int K;
        cin >> K;
        // Construct a graph of all replacements possible
        vector<char> tree[26];
        REP(i, K) {
            char temp1, temp2;
            cin >> temp1 >> temp2;
            tree[temp1 - 'A'].push_back(temp2 - 'A');
        }
        if (inputString.find_first_not_of(inputString[0]) == inputString.npos) {
            cout << "Case #" << numTest << ": " << 0 << endl;
            continue;
        }
        int grid[26][26];
        REP(i, 26) {
            REP(j, 26) { grid[i][j] = 1e9; }
        }
        for (auto inputChar : set<char>(inputString.begin(), inputString.end())) {
            int source = inputChar - 'A';
            vector<bool> visited(26, false);
            list<pair<int, int>> queue;
            visited[source] = true;
            queue.push_back({source, 0});
            while (!queue.empty()) {
                auto [character, level] = queue.front();
                grid[source][character] = min(grid[source][character], level);
                queue.pop_front();
                for (auto it = tree[character].begin(); it != tree[character].end(); ++it) {
                    if (!visited[*it]) {
                        visited[*it] = true;
                        queue.push_back({*it, level + 1});
                    }
                }
            }
        }

        // Max-operations = len(grid[0]) * len(S) = 2600
        int ans = 1e9;
        REP(i, 26) {
            int tempAns = 0;
            bool isInvalid = false;
            for (auto c : inputString) {
                int value = grid[c - 'A'][i];
                if (value == 1e9) {
                    isInvalid = true;
                    break;
                }
                tempAns += value;
            }
            if (isInvalid) {
                continue;
            }
            ans = min(ans, tempAns);
        }
        if (ans == 1e9) {
            ans = -1;
        }
        cout << "Case #" << numTest << ": " << ans << endl;

    }  // end of numtest
    return 0;
}