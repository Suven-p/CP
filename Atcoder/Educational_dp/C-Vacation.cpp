#include <bits/stdc++.h>

using namespace std;

long long INF = 10e12;
struct day {
    day(){
        points = {{'a', -INF}, {'b', -INF}, {'c', -INF}};
    }
    day(long long a, long long b, long long c){
        points = {{'a', a}, {'b', b}, {'c', c}};
    }
    map<char, long long> points;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    #ifndef ONLINE_JUDGE
    cin >> totalTests;
    #endif

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        long long N;
        cin >> N;
        long long dp[N][3];
        day data[N];
        for (int i=0; i < N; i++) {
            long long a, b, c;
            cin >> a >> b >> c;
            data[i] = {a, b, c};
        }

        for (int j=0; j < 3; j++) {
            dp[0][j] = data[0].points[char('a' + j)];
        }

        for (size_t i=1; i < N; i++) {
            for (int j=0; j < 3; j++) {
                auto max_index = -INF, max_element = -INF;
                // For each i, j find max value from previous row
                // For 1, 0 find max among 0, 1 and 0, 2
                for (int k=0; k < 3; k++) {
                    if (k!=j && dp[i-1][k] > max_element) {
                        max_index = k;
                        max_element = dp[i-1][k];
                    }
                }
                dp[i][j] = max_element + data[i].points[char('a' + j)];
            }
        }

        auto max_value = max_element(begin(dp[N-1]), end(dp[N-1]));
        cout << *max_value << endl;
    }

    return 0;
}