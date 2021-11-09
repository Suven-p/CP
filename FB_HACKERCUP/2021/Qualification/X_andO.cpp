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
#ifdef TEST
#define debug(x...) cerr << #x << x << endl;
#else
#define debug(x...)
#endif

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
        int N;
        cin >> N;
        vector<string> data(N);
        REP(i, N) { cin >> data[i]; }
        vector<int> rowsToComplete, colsToComplete;
        int minPieces = 1e9;
        REP(i, N) {
            int hasO_row = 0, hasX_row = 0;
            int hasO_col = 0, hasX_col = 0;
            REP(j, N) {
                if (data[i][j] == 'O') {
                    hasO_row++;
                } else if (data[i][j] == 'X') {
                    hasX_row++;
                }
                if (data[j][i] == 'O') {
                    hasO_col++;
                } else if (data[j][i] == 'X') {
                    hasX_col++;
                }
            }
            if (hasO_row == 0) {
                int required = N - hasX_row;
                if (required < minPieces) {
                    rowsToComplete.clear();
                    colsToComplete.clear();
                    minPieces = required;
                    rowsToComplete.push_back(i);
                } else if (required == minPieces) {
                    rowsToComplete.push_back(i);
                }
            }
            if (hasO_col == 0) {
                int required = N - hasX_col;
                if (required < minPieces) {
                    rowsToComplete.clear();
                    colsToComplete.clear();
                    minPieces = required;
                    colsToComplete.push_back(i);
                } else if (required == minPieces) {
                    colsToComplete.push_back(i);
                }
            }
        }
        if (minPieces == 1e9) {
            cout << "Case #" << numTest << ": "
                 << "Impossible\n";
            continue;
        }
        int numWays = rowsToComplete.size() + colsToComplete.size();
        if (minPieces == 1) {
            for (auto __row : rowsToComplete) {
                for (auto __col : colsToComplete) {
                    if (data[__row][__col] == '.') {
                        numWays--;
                    }
                }
            }
        }
        cout << "Case #" << numTest << ": " << minPieces << " " << numWays << "\n";
    }

    return 0;
}