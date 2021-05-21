#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
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

constexpr ll mod = 1e9 + 7;
ll exp_(ll N)
{
    ll ans = 1;
    ll inc = 50;
    ll val = (ll)(pow(2, inc)) % mod;
    while (N)
    {
        if (N >= inc)
        {
            ans *= val;
            ans %= mod;
            N -= inc;
        }
        else if (inc > 1)
        {
            inc /= 2;
            val = (ll)(pow(2, inc)) % mod;
        }
        else
        {
            ans *= 2;
            ans %= mod;
            N--;
        }
    }
    return ans;
}

int main()
{
#ifdef TEST
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    freopen("/media/psuv/Data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cout << exp_(N) << endl;

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