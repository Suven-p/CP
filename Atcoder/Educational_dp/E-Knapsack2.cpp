#include <bits/stdc++.h>

using namespace std;

int64_t INF = 10e12;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
#ifndef ONLINE_JUDGE
    cin >> totalTests;
#endif

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int N;
        int64_t max_capacity;
        cin >> N >> max_capacity;
        int64_t weights[N + 5];
        int64_t values[N + 5], sum_value = 0;

        int64_t max_N = 100, max_sum_value = 100 * 1000;
        int64_t dp[2][max_sum_value + 9];

        int current_index = 0, previous_index = 1;
        for (int64_t i = 1; i <= N; i++)
        {
            cin >> weights[i] >> values[i];
            sum_value += values[i];
        }

        for (int64_t j = 1; j <= sum_value; j++)
        {
            dp[current_index][j] = INF;
        }

        dp[current_index][0] = 0;
        dp[previous_index][0] = 0;
        dp[current_index][values[1]] = weights[1];
        int64_t ans = 0;
        swap(current_index, previous_index);
        for (int64_t i = 2; i <= N; i++)
        {
            for (int64_t j = 1; j <= sum_value; j++)
            {
                auto val1 = dp[previous_index][j];
                auto val2 = (j >= values[i]) ? ((dp[previous_index][j - values[i]]) + weights[i]) : INF;
                dp[current_index][j] = min(val1, val2);
            }
            swap(current_index, previous_index);
        }

        for (int64_t j = sum_value; j >= 0; j--)
        {
            if (dp[previous_index][j] <= max_capacity)
            {
                ans = j;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}