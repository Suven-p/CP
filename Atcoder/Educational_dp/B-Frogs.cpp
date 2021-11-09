#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numTests=1;
    #ifndef ONLINE_JUDGE
    cin >> numTests;
    #endif

    for (int numTest = 1; numTest <= numTests; numTest++) {
        long long totalStones;
        long long K;
        cin >> totalStones >> K;
        long long dp[totalStones + 5], h[totalStones + 5];

        for (long long numStone = 1; numStone <= totalStones; numStone++)
        {
            cin >> h[numStone];
            dp[numStone] = 10e8;
        }
        // memset(dp, 10e7, sizeof(int)*(totalStones+1));
        dp[1] = 0;
        dp[2] = abs(h[2] - h[1]);

        for (long long i = 3; i <= totalStones; i++)
        {
            for (long long j=i-K; j <=i-1; j++) {
                if (j < 1) continue;
                auto t1 = dp[j] + abs(h[i] - h[j]);
                dp[i] = min(
                    dp[i],
                    t1
                );
            }
        }
        cout << dp[totalStones] << endl;
    }

    return 0;
}