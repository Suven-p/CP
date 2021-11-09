// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numTests = 1;
    #ifndef ONLINE_JUDGE
    cin >> numTests;
    #endif

    for (int test_num = 0; test_num < numTests; test_num++)
    {
        int totalStones;
        cin >> totalStones;
        int dp[totalStones + 1], h[totalStones + 1];

        for (int numStone = 1; numStone <= totalStones; numStone++)
        {
            cin >> h[numStone];
        }
        dp[1] = 0;
        dp[2] = abs(h[2] - h[1]);
        for (int i = 3; i <= totalStones; i++)
        {
            auto t1 = dp[i - 1] + abs(h[i] - h[i - 1]);
            auto t2 = dp[i - 2] + abs(h[i] - h[i - 2]);
            dp[i] = min(
                t1,
                t2);
        }
        cout << dp[totalStones] << endl;
    }

    return 0;
}