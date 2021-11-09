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

int N, K;

void solve()
{
    int ans = 0;
    for (int i = 0; i < (N / K); i++)
    {
        cout << "? ";
        for (int j = 1; j <= K; j++)
        {
            cout << i * K + j << " ";
        }
        cout << endl;
        int temp;
        cin >> temp;
        ans ^= temp;
    }
    if (N % K == 0)
    {
        cout << ans << endl;
        return;
    }
    int remaining = (N % K);
    int sz = remaining / 2;
    if ((remaining % 2) == 0)
    {
        int temp, temp2;
        cout << "? ";
        for (int j = 0; j < (N - K - sz) / sz; j++)
        {
            for (int i = 1; i <= K - sz; i++)
            {
                cout << i << " ";
            }
            for (int k = 1; k <= remaining; j++)
            {
                cout << (K - sz) + (j * sz) + k << " ";
            }
            cout << endl;
            cin >> temp;
            ans ^= temp;
        }
    }
    else
    {
        cout << -1 << endl;
    }
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

    cin >> N >> K;
    solve();

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