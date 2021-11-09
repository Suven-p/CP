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

int N;
int input[109];
int sum = 0, optimal = 0, best = 1e9;
bool dp[109 + 1][int(1e5 + 3)];

int findMin()
{
    for (int i = 0; i <= N; i++)
        dp[i][0] = true;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (input[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - input[i - 1]];
        }
    }

    int diff = INT_MAX;

    for (int j = sum / 2; j >= 0; j--)
    {
        if (dp[N][j] == true)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

int main()
{
#ifdef TEST
    freopen("/media/nevus/data/CP/input.in", "r", stdin);
    freopen("/media/nevus/data/CP/output.out", "w", stdout);
    freopen("/media/nevus/data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    REP(i, N)
    {
        cin >> input[i];
        sum += input[i];
    }
    optimal = (sum + 1) / 2;
    best = findMin();
    int a = (sum + best) / 2;
    int b = sum - a;
    cout << max(a, b) << endl;

#ifdef TEST
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << endl
         << fixed
         << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}