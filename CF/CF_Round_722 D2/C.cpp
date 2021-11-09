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

constexpr int NMAX = 1e5 + 7;
vi tree[NMAX];
int N;
pair<int, int> liri[NMAX];
pair<ll, ll> values[NMAX];

void reset()
{
    REP(i, NMAX)
    {
        tree[i].clear();
        values[i] = {0, 0};
    }
}

ll dfs(int current, int parent)
{
    if (parent != 0 && tree[current].size() == 1)
    {
        values[current] = {0, 0};
    }
    ll ans1 = 0, ans2 = 0;
    for (auto c : tree[current])
    {
        if (c == parent)
        {
            continue;
        }
        dfs(c, current);
        ll val1 = abs(liri[current].first - liri[c].first) + values[c].first;
        ll val2 = abs(liri[current].first - liri[c].second) + values[c].second;
        ans1 += max(val1, val2);

        val1 = abs(liri[current].second - liri[c].first) + values[c].first;
        val2 = abs(liri[current].second - liri[c].second) + values[c].second;
        ans2 += max(val1, val2);
    }
    values[current] = {ans1, ans2};
    return max(ans1, ans2);
}

ll solve()
{
    ll ans1 = 0, ans2 = 0;
    dfs(1, 0);
    dfs(1, 0);
    ans1 = values[1].first;
    ans2 = values[1].second;
    return max(ans1, ans2);
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
        reset();
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            int li, ri;
            cin >> li >> ri;
            liri[i] = mp(li, ri);
        }
        for (int i = 1; i < N; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        auto ans = solve();
        cout << ans << "\n";
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