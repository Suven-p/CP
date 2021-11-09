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

ll resolve(map<ll, ll> powers, ll times)
{
    ll ans = 0;
    for (auto [power, freq] : powers)
    {
        if (freq == 1)
        {
            ans += power;
        }
        else
        {
            return -1;
        }
    }
    ans += (times - 1);
    return ans;
}

ll solve(ll X, ll Y)
{
    if (Y % X != 0)
    {
        return -1;
    }
    ll n = Y / X;
    ll power, ans = 0, times = 0;
    map<ll, ll> powers;
    while (true)
    {
        if (not n)
            break;
        power = log2(n + 1);
        powers[power]++;
        n -= ((ll)exp2(power) - 1);
        times++;
    }
    ans = resolve(powers, times);
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
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        ll X, Y;
        cin >> X >> Y;
        auto ans = solve(X, Y);
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