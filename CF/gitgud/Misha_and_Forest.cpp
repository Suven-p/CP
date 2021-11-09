// Problem Link: https://codeforces.com/contest/501/problem/C

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
#define FOR(i, j, k, inc) for (ll i = j; i < k; i += inc)
#define REP(i, n) for (ll i = 0; i < n; i++)
#ifdef TEST
#define debug(x...) cerr << #x << x << endl;
#else
#define debug(x...)
#endif

constexpr ll maxN = (1 << 16) + 5;
ll N;
vector<pair<ll, ll>> edges;
ll degree[maxN];
ll sum[maxN];
map<ll, set<ll>> degree_map;

void reset()
{
    N = 0;
    REP(i, maxN)
    {
        degree[i] = 0;
        sum[i] = 0;
    }
}

void solve()
{
    ll num_processed = degree_map[0].size();

    while (num_processed < N)
    {
        set<ll> skip;
        for (auto it = degree_map[1].begin(); it != degree_map[1].end();)
        {
            auto val = *it;
            auto parent = sum[val];
            switch (degree[parent])
            {
            case 1:
                degree_map[degree[parent]].erase(parent);
                num_processed += 2;
                break;
            default:
                degree_map[degree[parent]].erase(parent);
                degree[parent]--;
                degree_map[degree[parent]].insert(parent);
                sum[parent] ^= val;
                num_processed++;
            }

            edges.push_back(mp(val, parent));
            auto cur = it;
            it++;
            degree_map[1].erase(cur);
        }
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

    reset();

    cin >> N;

    for (ll numVertex = 0; numVertex < N; numVertex++)
    {
        ll u, v;
        cin >> u >> v;
        degree[numVertex] = u;
        sum[numVertex] = v;
        degree_map[u].insert(numVertex);
    }
    solve();
    cout << edges.size() << endl;
    for (auto c : edges)
    {
        cout << c.first << " " << c.second << "\n";
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