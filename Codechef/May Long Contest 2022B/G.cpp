#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#pragma GCC optimize "trapv"
#define TEST
#endif
typedef long long ll;
typedef unsigned long long ull;
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

struct Can
{
    ll position;
    ll value;
    ll cost;
    pair<ll, ll> range;
    Can(ll position = 0, ll value = 0, ll cost = 0) : position(position), value(value), cost(cost)
    {
        ll max_deviation = (ll)(value / cost);
        range = {position - max_deviation, position + max_deviation};
    }
};

int main()
{
#ifdef TEST
    freopen("/media/lubuntu_nevus/Home_image/CP/input.in", "r", stdin);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stdout);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;
    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        ll N, L, R;
        cin >> N >> L >> R;
        vector<ll> positions(N), coins(N);
        vector<Can> cans(N);
        ll current_cost = 0, max_cost = 0;
        REP(i, N)
        {
            cin >> positions[i];
        }
        REP(i, N)
        {
            cin >> coins[i];
        }
        REP(i, N)
        {
            auto position = positions[i],
                 value = coins[i];
            ll cost;
            cin >> cost;
            cans[i] = {position, value, cost};
            if (position >= L && position <= R)
            {
                current_cost += cost;
            }
            else
            {
                ll max_deviation = value / cost;
                if (abs(position - L) <= max_deviation)
                {
                    current_cost += cost;
                }
            }
        }
        max_cost = current_cost;
        std::sort(cans.begin(), cans.end(), [](const Can &a, const Can &b)
                  { return a.position < b.position; });
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
