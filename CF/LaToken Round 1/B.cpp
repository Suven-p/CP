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
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int N;
        cin >> N;
        vll input;
        ll ans = 0;
        vector<bool> processed(N, false);
        REP(i, N)
        {
            ll t;
            cin >> t;
            input.push_back(t);
            if (i != 0)
            {
                ans += abs(t - input[input.size() - 2]);
            }
        }
        ans += (input[0] + input[N - 1]);
        if (N == 1)
        {
            cout << input[0] << endl;
            continue;
        }
        REP(i, N)
        {
            int prev = 0, next = 0;
            if (i == 0)
            {
                next = input[i + 1];
            }
            else if (i == N - 1)
            {
                prev = input[i - 1];
            }
            else
            {
                next = input[i + 1];
                prev = input[i - 1];
            }
            if (input[i] > max(next, prev))
            {
                ans -= (input[i] - max(next, prev));
            }
        }
        cout << ans << endl;
    }

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