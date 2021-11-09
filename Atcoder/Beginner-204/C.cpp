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

int N, M;
vi graph[2004];
vector<bool> visited(2004, false);

void dfs(int current, int &ans)
{
    visited[current] = true;
    ans++;
    for (auto c : graph[current])
    {
        if (!visited[c])
            dfs(c, ans);
    }
}

int solve()
{
    int ans = 0;
    FOR(i, 1, N + 1, 1)
    {
        visited = vector<bool>(2004, false);
        dfs(i, ans);
    }
    return ans;
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

    cin >> N >> M;
    REP(i, M)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
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