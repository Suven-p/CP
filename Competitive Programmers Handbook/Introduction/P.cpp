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

int N;
ll input[20];
ll sum = 0, ideal = 0;

ll dp(int index, ll val)
{
    if (val == ideal)
    {
        ll part1 = val;
        ll part2 = sum - val;
        return abs(part1 - part2);
    }
    if (index == N)
    {
        ll part1 = val;
        ll part2 = sum - val;
        return abs(part1 - part2);
    }

    if (val > ideal)
    {
        ll part1 = val;
        ll part2 = sum - val;
        ll val1 = abs(part1 - part2);
        return val1;
    }

    ll child1 = dp(index + 1, val + input[index]);
    ll child2 = dp(index + 1, val);
    return min(child1, child2);

    // vll values({diff1, diff2, child2});
    // auto min_elem = min_element(values.begin(), values.end());
    // return *min_elem;
}

ll solve()
{
    ll min_diff = dp(0, 0);
    ll val = min_diff;

    return val;
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

    cin >> N;
    REP(i, N)
    {
        cin >> input[i];
        sum += input[i];
    }
    sort(begin(input), end(input), [](ll a, ll b)
         { return a > b; });
    ideal = sum / 2;
    auto ans = solve();
    cout << ans << endl;

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