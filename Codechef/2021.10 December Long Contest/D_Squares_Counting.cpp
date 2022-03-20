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

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int N;
        cin >> N;
        vector<string> grid(N);
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
        }
        // dp[i][j][0] = number of 1's to right of (i,j) including (i, j)
        // dp[i][j][1] = number of 1's to bottom of (i,j) including (i, j)
        int dp[N][N][2];
        int ans = 0;
        for(int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                if (i == N - 1) {
                    dp[i][j][1] = grid[i][j] - '0';
                }
                else if (grid[i][j] == '1'){
                        dp[i][j][1] = dp[i + 1][j][1] + 1;
                    }
                if (j == N - 1) {
                    dp[i][j][0] = grid[i][j] - '0';
                }
                else if (grid[i][j] == '1'){
                        dp[i][j][0] = dp[i][j + 1][0] + 1;
                }
                int min_val = min(dp[i][j][0], dp[i][j][1]);
                // point (i, j) is upper left corner of square of size sz
                // if a) point(i, j) has at least sz 1's to its right
                // and b) point(i + sz - 1) has sz 1's to its bottom
                // and c) point(i, j + sz - 1) has sz 1's to its right
                for(int sz = 1; sz <= min_val; sz++) {
                    if (dp[i][j + sz - 1][1] >= sz && dp[i + sz - 1][j][0] >= sz) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }

#ifdef TEST
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        cout << "Time taken by program is : " << endl << fixed
             << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}
