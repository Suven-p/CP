#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    #ifndef ONLINE_JUDGE
    cin >> totalTests;
    #endif

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        long long N, max_capacity;
        cin >> N >> max_capacity;
        long long weights[N+5], values[N+5], dp[N+5][max_capacity+5];
        for(long long i=1; i<=N; i++) {
            cin >> weights[i] >> values[i];
            dp[i][0] = 0;
        }
        for (long long capacity=0; capacity <= max_capacity; capacity++) {
            dp[1][capacity] = (capacity >= weights[1])?values[1]:0;
        }
        for(long long i=2; i<=N; i++) {
            for(long long capacity=1; capacity<=max_capacity; capacity++) {
                long long ans = dp[i-1][capacity];
                if (weights[i] <= capacity) {
                    ans = max(ans, dp[i-1][capacity-weights[i]] + values[i]);
                }
                dp[i][capacity] = ans;
            }
        }
        cout << dp[N][max_capacity] << endl;
    }

    return 0;
}